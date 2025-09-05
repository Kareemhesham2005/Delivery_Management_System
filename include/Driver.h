#ifndef DMS_DRIVER_H
#define DMS_DRIVER_H

#include <string>
#include "Point.h"

namespace dms {

struct Driver {
    int id = -1;
    std::string name;
    Point location;
    bool available = true;

    Driver() = default;
    Driver(int id_, const std::string &name_, const Point &loc) : id(id_), name(name_), location(loc), available(true) {}
};

} // namespace dms

#endif // DMS_DRIVER_H
