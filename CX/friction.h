#pragma once
#include "../geometry.h"
class friction: virtual public geometry
{
	private:
		double const h_s = 8 * pow(10, -6);
	private:
		double area_ratio;

		double Re;
		double n;

		double x_t;
		void stream_calc(double Re, double Mah);

	public:
		double fricalc(double Mah, double SS, double nu);
		double C_fric;
};

