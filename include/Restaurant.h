#ifndef DMS_RESTAURANT_H
#define DMS_RESTAURANT_H

#include <string>
#include <vector>
#include "Point.h"

namespace dms {

struct Item {
    std::string name;
    double cost = 0.0;
    Item() = default;
    Item(const std::string &n, double c) : name(n), cost(c) {}
};

struct Restaurant {
    int id = -1;
    std::string name;
    Point location;
    std::vector<Item> items;

    Restaurant() = default;
    Restaurant(int id_, const std::string &name_, const Point &loc) : id(id_), name(name_), location(loc) {}

    void addItem(const std::string &name, double cost) {
        items.emplace_back(name, cost);
    }
};

} // namespace dms

#endif // DMS_RESTAURANT_H
