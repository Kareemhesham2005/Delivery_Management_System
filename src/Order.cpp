#include "../include/Order.h"

using namespace dms;

double Order::getTotalCost() const { return cost; }

int Order::getId() const { return id; }

std::string Order::getStatus() const {
    if (status == OrderStatus::Assigned) return "Assigned";
    if (status == OrderStatus::Cancelled) return "Cancelled";
    if (status == OrderStatus::Delivered) return "Delivered";
    return "Not Found";
}

void Order::setStatus(OrderStatus s) {status = s;}

