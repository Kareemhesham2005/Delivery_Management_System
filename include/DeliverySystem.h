#ifndef DMS_DELIVERY_SYSTEM_H
#define DMS_DELIVERY_SYSTEM_H

#include <vector>
#include <string>
#include "Point.h"
#include "Driver.h"
#include "Restaurant.h"
#include "Order.h"

namespace dms {

class DeliverySystem {
public:
    DeliverySystem();
    ~DeliverySystem() = default;

    std::vector<Order> orders;

    // Create an order; returns order id or -1 on failure.
    int createOrder(int restaurantId, int itemIndex, const Point &customerLocation, std::string &errMsg);

    // Change the status of an existing order. Returns true on success.
    bool changeOrderStatus(int orderId, OrderStatus status, std::string &errMsg);

    // Get a human-readable description of an order; returns empty string if not found.
    std::string describeOrder(int orderId) const;

    // List restaurants and their items as a printable string.
    std::string listRestaurants() const;

private:
    // Internal storage
    std::vector<Restaurant> restaurants;
    std::vector<Driver> drivers;

    // Helper: find nearest available driver to a location (returns driver index or -1)
    int findNearestAvailableDriver(const Point &loc) const;
};

} // namespace dms

#endif // DMS_DELIVERY_SYSTEM_H
