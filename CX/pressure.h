#pragma once
#include "../geometry.h"
#include <iostream>
#include <fstream>
#include <string>
class pressure : virtual public geometry
{
public:
	double prescalc(double Mah);

private:
	double head_Cpres(double Mah);
	double triangle_Cpres(double Mah, double ratio);
	double un_triangle_pres(double Mah);
	double bottom_pres(double Mah);
};

