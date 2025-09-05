#include "../include/DeliverySystem.h"

#include <sstream>
#include <limits>
#include <algorithm>

using namespace dms;

DeliverySystem::DeliverySystem() {
    // Seed with some drivers and restaurants (example data).
    drivers.emplace_back(1, "Ali", Point{42.1720, 29.4235});
    drivers.emplace_back(2, "Sara", Point{11.7210, 51.7721});
    drivers.emplace_back(3, "Omar", Point{29.9800, 31.1400});
    drivers.emplace_back(4, "Ahmed", Point{-20.2542, 12.4523});

    Restaurant r1(1, "Burger Place", Point{29.9773, 31.1325});
    r1.addItem("Classic Burger", 5.50);
    r1.addItem("Fries", 1.75);
    restaurants.push_back(std::move(r1));

    Restaurant r2(2, "Pasta Corner", Point{29.9800, 31.1310});
    r2.addItem("Spaghetti Bolognese", 7.25);
    r2.addItem("Garlic Bread", 2.00);
    restaurants.push_back(std::move(r2));
}

// Find nearest available driver; linear scan is fine for small demo data.
// Return index in drivers vector or -1 if none available.
int DeliverySystem::findNearestAvailableDriver(const Point &loc) const {
    int best = -1;
    double bestDist = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < drivers.size(); ++i) {
        if (!drivers[i].available) continue;
        double d = drivers[i].location.distanceTo(loc);
        if (d < bestDist) {
            bestDist = d;
            best = static_cast<int>(i);
        }
    }
    return best;
}

int DeliverySystem::createOrder(int restaurantId, int itemIndex, const Point &customerLocation, std::string &errMsg) {
    // Validate restaurant id (simple map of ids to indices)
    auto it = std::find_if(restaurants.begin(), restaurants.end(), [&](const Restaurant &r){ return r.id == restaurantId; });
    if (it == restaurants.end()) {
        errMsg = "Restaurant not found";
        return -1;
    }
    int restIndex = static_cast<int>(std::distance(restaurants.begin(), it));

    if (itemIndex < 0 || itemIndex >= static_cast<int>(it->items.size())) {
        errMsg = "Invalid item index for the chosen restaurant";
        return -1;
    }

    // Find nearest driver
    int driverIdx = findNearestAvailableDriver(customerLocation);
    if (driverIdx == -1) {
        errMsg = "No available drivers at the moment";
        return -1;
    }

    // Compute simple cost: item cost + distance * factor
    double distance = customerLocation.distanceTo(it->location);
    const double costPerKilo = 0.5; // illustrative factor
    double cost = it->items[itemIndex].cost + distance * costPerKilo;

    int orderId = static_cast<int>(orders.size()) + 1;
    Order order(orderId, restaurantId, itemIndex, cost);
    order.driverId = drivers[driverIdx].id;
    orders.push_back(std::move(order));

    // mark driver as busy
    drivers[driverIdx].available = false;

    return orderId;
}

bool DeliverySystem::changeOrderStatus(int orderId, OrderStatus status, std::string &errMsg) {
    if (orderId <= 0 || orderId > static_cast<int>(orders.size())) {
        errMsg = "Invalid order id";
        return false;
    }
    Order &o = orders[orderId - 1];
    o.setStatus(status);

    // If delivered or cancelled, free the driver (if any)
    if ((status == OrderStatus::Delivered || status == OrderStatus::Cancelled) && o.driverId.has_value()) {
        int did = o.driverId.value();
        auto it = std::find_if(drivers.begin(), drivers.end(), [&](const Driver &d){ return d.id == did; });
        if (it != drivers.end()) it->available = true;
    }
    return true;
}

std::string DeliverySystem::describeOrder(int orderId) const {
    if (orderId <= 0 || orderId > static_cast<int>(orders.size())) return {};

    const Order &o = orders[orderId - 1];
    std::ostringstream ss;
    ss << "Order #" << o.id << "\n";
    ss << "Status: ";
    switch (o.status) {
        case OrderStatus::Assigned: ss << "Assigned"; break;
        case OrderStatus::Delivered: ss << "Delivered"; break;
        case OrderStatus::Cancelled: ss << "Cancelled"; break;
    }
    ss << "\n";

    // restaurant and item info
    auto restIt = std::find_if(restaurants.begin(), restaurants.end(), [&](const Restaurant &r){ return r.id == o.restaurantId; });
    if (restIt != restaurants.end()) {
        ss << "Restaurant: " << restIt->name << "\n";
        if (o.itemIndex >= 0 && o.itemIndex < static_cast<int>(restIt->items.size())) {
            ss << "Item: " << restIt->items[o.itemIndex].name << " (" << restIt->items[o.itemIndex].cost << ")\n";
        }
    }
    ss << "Cost: " << o.cost << "\n";
    if (o.driverId.has_value()) {
        ss << "Driver ID: " << o.driverId.value() << "\n";
    }
    return ss.str();
}

std::string DeliverySystem::listRestaurants() const {
    std::ostringstream ss;
    for (const auto &r : restaurants) {
        ss << "Restaurant ID: " << r.id << " - " << r.name << " (location: " << r.location.x << "," << r.location.y << ")\n";
        for (size_t i = 0; i < r.items.size(); ++i) {
            ss << "  [" << i << "] " << r.items[i].name << " - " << r.items[i].cost << "\n";
        }
    }
    return ss.str();
}
