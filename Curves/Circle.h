#pragma once
#include "Curve.h"

class Circle : public Curve
{
public:
	Circle(double r);
	virtual Point3D getPoint(double t) override;
	virtual Point3D derivative(double t) override;
	double getRadius() const;
	bool operator < (const Circle& c) const;
private:
	double radius;
};