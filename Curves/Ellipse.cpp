#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(double rx, double ry)
{
    if (rx < 0 || ry < 0) {
        throw std::invalid_argument("Radii must be positive");
    }
    else {
        radiiX = rx;
        radiiY = ry;
    }
}

Point3D Ellipse::getPoint(double t)
{
    return Point3D(radiiX * cos(t), radiiY * sin(t), 0);
}

Point3D Ellipse::derivative(double t)
{
    return Point3D(-radiiX * sin(t), radiiY * cos(t), 0);
}


