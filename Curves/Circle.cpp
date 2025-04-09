#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double r)
{
    if (r >= 0) {
        radius = r;
    }
    else {
        throw std::invalid_argument("radius cannot be negative");
    }
}

Point3D Circle::getPoint(double t)
{
    return Point3D (radius * std::cos(t), radius * std::sin(t), 0);
}

Point3D Circle::derivative(double t)
{
    return Point3D (radius * (-std::sin(t)), radius * std::cos(t), 0);
}

double Circle::getRadius() const
{
    return radius;
}

bool Circle::operator<(const Circle& c) const
{
    return radius < c.radius;
}
