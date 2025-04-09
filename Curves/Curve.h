#pragma once

struct Point3D {
	Point3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}
	double x;
	double y;
	double z;
};

class Curve {
public:
	virtual Point3D getPoint(double t) = 0;
	virtual Point3D derivative(double t) = 0;
};