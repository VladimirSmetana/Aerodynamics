#pragma once
#include "friction.h"
#include "pressure.h"

class drag_force : public friction, public pressure
{
public:
	double calculate_CX(double Mah, double SS, double nu);
};

