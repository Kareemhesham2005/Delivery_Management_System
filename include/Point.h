#ifndef DMS_POINT_H
#define DMS_POINT_H

#include <cmath>

namespace dms {

struct Point {
    double x = 0.0;
    double y = 0.0;

    Point() = default;
    Point(double x_, double y_) : x(x_), y(y_) {}

    // Euclidean distance to another point.
    double distanceTo(const Point &other) const {
        const double dx = other.x - x;
        const double dy = other.y - y;
        return std::sqrt(dx*dx + dy*dy);
    }
};

} // namespace dms

#endif // DMS_POINT_H
