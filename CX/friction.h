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
		double C_fric;

		void stream_calc(double Re, double Mah);
	protected:
		double fricalc(double Mah, double SS, double nu) ;
	public:
		friction() : area_ratio(0), Re(0), n(0), x_t(0), C_fric(0) {};
};

