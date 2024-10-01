#pragma once
#include "../geometry.h"
class friction: virtual public geometry
{
	private:
		double const h_s = 8 * pow(10, -6);
		double area_ratio = 0;
		double Re = 0;
		double n = 0;
		double x_t = 0;
		double C_fric = 0;

		void stream_calc(double Re, double Mah);
	protected:
		double fricalc(double Mah, double SS, double nu);
};

