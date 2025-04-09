#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <cmath>
#include <algorithm>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"


using namespace std;

void printCurveVals(vector<unique_ptr<Curve>>& curves, double t);

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distrib(0.1, 10.0);
	uniform_int_distribution<> types(0, 2);
	vector<unique_ptr<Curve>> curves;
	unsigned int size = 100;
	for (int i = 0; i < size; i++)
	{
		int type = types(gen);
		switch (type) {
		case 0: 
			curves.push_back(make_unique<Circle>(distrib(gen)));
			break;
		case 1:
			curves.push_back(make_unique<Ellipse>(distrib(gen), distrib(gen)));
			break;
		case 2:
			curves.push_back(make_unique<Helix>(distrib(gen), distrib(gen)));
			break;
		}
	}

	printCurveVals(curves, M_PI_4);

	vector<reference_wrapper<Circle>> circles;

	for (int i = 0; i < curves.size(); i++) {
		auto* circle = dynamic_cast<Circle*>(curves[i].get());
		if (circle != nullptr) {
			circles.push_back(*circle);
		}
	}
	
	sort(circles.begin(), circles.end(),
		[](const Circle& c1, const Circle& c2) {
			return c1.getRadius() < c2.getRadius();
		});

	double sumRadii = 0;
#pragma omp parallel for reduction(+:sumRadii)
	for (int i = 0; i < circles.size(); i ++) {
		sumRadii += circles[i].get().getRadius();
	}

	return 0;
   
}

void printCurveVals(vector<unique_ptr<Curve>>& curves, double t) {
	for (int i = 0; i < curves.size(); i++) {
		Point3D p = curves[i]->getPoint(t);
		Point3D derivative = curves[i]->derivative(t);
		cout << "Point:" << p.x << " " << p.y << " " << " " << p.z << endl;
		cout << "Derivative:" << derivative.x << " " << derivative.y << " " << " " << derivative.z << endl << endl;
	}
}

