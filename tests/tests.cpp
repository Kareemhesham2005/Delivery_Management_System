#include <iostream>
#include <cassert>
#include "../include/DeliverySystem.h"

using namespace dms;
int main(){
    DeliverySystem ds;
    std::string err;
    // List restaurants should not be empty
    auto list = ds.listRestaurants();
    assert(!list.empty());
    // Create order with invalid restaurant
    int oid = ds.createOrder(999, 0, Point{0,0}, err);
    assert(oid == -1);
    // Create order with valid data
    // Find first restaurant id by parsing list (simpler: assumed ids 1 and 2)
    oid = ds.createOrder(1, 0, Point{29.98,31.13}, err);
    assert(oid > 0);
    // Track created order
    auto desc = ds.describeOrder(oid);
    assert(!desc.empty());
    // Change status to Delivered
    bool ok = ds.changeOrderStatus(oid, OrderStatus::Delivered, err);
    assert(ok);
    std::cout << "All tests passed\n";
    return 0;
}
