#ifndef DMS_ORDER_H
#define DMS_ORDER_H

#include <string>

namespace dms {

enum class OrderStatus { Assigned, Delivered, Cancelled };


struct Order {
    int id = -1;
    int restaurantId = -1;
    int itemIndex = -1;
    double cost = 0.0;
    int driverId;
    OrderStatus status = OrderStatus::Assigned;

    Order() = default;
    Order(int id_, int restId, int itemIdx, double cost_, int driverId_)
        : id(id_), restaurantId(restId), itemIndex(itemIdx), cost(cost_), status(OrderStatus::Assigned), driverId(driverId_) {}

    void setStatus(OrderStatus s);
    double getTotalCost() const;
    int getId() const;
    std::string getStatus() const;

};

} // namespace dms

#endif // DMS_ORDER_H
