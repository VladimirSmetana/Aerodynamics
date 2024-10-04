#include "geometry.h"
#include <iostream>
#include <fstream>
#include <string>

class inductance : virtual public geometry
{
public:
    inductance();
    double E_pressure(const double &angle, double Mah);
private:
    static constexpr int N = 10;
	double Mah_v[N];
	double H_head[N];
	double H_cone[N];
	// double C_head = 0.035;

	double L_cyl;
	double E_head;
	double E_cone;
	double E;
	double ratio;
};
