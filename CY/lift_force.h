#pragma once
#include "../geometry.h"
#include "../inductance.h"
#include <iostream>
#include <fstream>
#include <string>
class lift_force: public inductance
{
	public:
		double calculate_CY(double Mah);
		double head_lift(double Mah);
		double triangle_lift(double Mah, double ratio, int index);
		double un_triangle_lift(double Mah);
		double free_triangle_lift(int index);
};

