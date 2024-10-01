#pragma once
#include "../geometry.h"
class friction: virtual public geometry
{
	private:
		double const h_s = 8 * pow(10, -6);
		double area_ratio;
		double Re;
		double n;
		double x_t;
		void stream_calc(double Re, double Mah);
		double C_fric;
	protected:
		double fricalc(double Mah, double SS, double nu);
};

