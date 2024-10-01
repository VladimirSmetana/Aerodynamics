#pragma once
#include "CX/drag_force.h"
#include "CY/lift_force.h"

class union_stream: public drag_force, public lift_force
{
private:
	double E;
public:
	double CX;
	double CY;
	void calculate_CXY(double angle, double Mah, double SS, double nu);
};

