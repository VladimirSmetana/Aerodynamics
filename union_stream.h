#pragma once
#include "drag_force.h"
#include "lift_force.h"

class union_stream: public drag_force, public lift_force
{
public:
	double CX;
	double CY;
	void calculate_CXY(double Mah, double SS, double nu);
};

