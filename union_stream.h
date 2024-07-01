#pragma once
#include "drag_force.h"

class union_stream: public drag_force
{
public:
	void calculate_CXY(double Mah, double SS, double nu);
};

