#ifndef DMS_ORDER_H
#define DMS_ORDER_H

#include <string>
#include <optional>

namespace dms {

enum class OrderStatus { Assigned, Delivered, Cancelled };

/*
Simple Order record. For clarity and safety this struct uses no raw pointers.
*/
struct Order {
    int id = -1;
    int restaurantId = -1;
    int itemIndex = -1;
    double cost = 0.0;
    std::optional<int> driverId; // driver assigned (if any)
    OrderStatus status = OrderStatus::Assigned;

    Order() = default;
    Order(int id_, int restId, int itemIdx, double cost_)
        : id(id_), restaurantId(restId), itemIndex(itemIdx), cost(cost_), status(OrderStatus::Assigned) {}

    void setStatus(OrderStatus s) { status = s; }
};

} // namespace dms

#endif // DMS_ORDER_H
