#pragma once
#include "geometry.h"
class friction: public geometry
{
	private:
		double const h_s = 8 * pow(10, -6);
	private:
		double area_ratio;
		double num;
		double Re;
		double n;
		double cif;
		double x_t;
		void stream_calc(double Re, double Mah);

	public:
		void fricalc(double Mah, double SS, double nu);
		double C_fric;
};

