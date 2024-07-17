#pragma once
#include "../geometry.h"
#include <iostream>
#include <fstream>
#include <string>
class lift_force: virtual public geometry
{
	public:
		double calculate_CY(double Mah, double SS, double nu);
		double head_lift(double Mah);
		double triangle_lift(double Mah, double ratio, int index);
		double un_triangle_lift(double Mah);
		double free_triangle_lift(int index);
};

