#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
	Helix(double r, double s);
	virtual Point3D getPoint(double t) override;
	virtual Point3D derivative(double t) override;
private:
	double radius, step;
};