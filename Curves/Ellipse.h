#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	Ellipse(double rx, double ry);
	virtual Point3D getPoint(double t) override;
	virtual Point3D derivative(double t) override;
private:
	double radiiX, radiiY;
};