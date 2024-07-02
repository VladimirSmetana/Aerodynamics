#pragma once
#include "friction.h"
#include "pressure.h"

class drag_force : public friction
{
public:
	void calculate_CX(double Mah, double SS, double nu);
};

