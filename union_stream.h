#pragma once
#include "CX/drag_force.h"
#include "CY/lift_force.h"

class union_stream : public drag_force, public lift_force
{
private:
	double E = NULL;

public:
	double CX;
	double CY;
	void calculate_CXY(const double &angle, const double &Mah, const double &SS, const double &nu);
};
