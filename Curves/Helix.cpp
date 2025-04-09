#define _USE_MATH_DEFINES
#include <cmath>
#include "Helix.h"

Helix::Helix(double r, double s)
{
    if (r > 0) {
        radius = r;
    }
    step = s;
}

Point3D Helix::getPoint(double t)
{
    return Point3D(radius * cos(t), radius * sin(t), M_1_PI / 2 * t * step);
}

Point3D Helix::derivative(double t)
{
    return Point3D(-radius * sin(t), radius * cos(t), M_1_PI / 2 * t * step);
}
