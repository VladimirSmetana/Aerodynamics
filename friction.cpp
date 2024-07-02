#include "friction.h"

void friction::stream_calc(double Re, double Mah)
{


	if (Re <= 485000)
	{
		cif = 2.656 / sqrt(Re);
		num = pow(1 + 0.1 * pow(Mah, 0.1), -0.125);
	}
	if (Re > 485000 && Re < 10000000)
	{
		n = 5 + (1.3 + 0.6 * Mah * (1 - 0.25 * pow(Mah, 2))) * sqrt(1 - pow(log10((h_s / full_length * Re) - 1) / (2.2 + 0.08 * pow(Mah, 2) / (1 + 0.312 * pow(Mah, 2))), 2));
		x_t = min(pow(10, n) / Re, elem[0].elem_length / full_length);

		cif = 0.91 / pow(log10(Re), 2.58) * pow(1 - x_t + 40 * pow(x_t, 0.625)/pow(Re, 0.375), 0.8);
		num = pow(1 + 0.1 * pow(Mah, 0.1), -0.125);
	}
	if (Re >= 10000000)
	{
		cif = 0.91 / pow(log10(Re), 2.58);
		num = pow(1 + 0.1 * pow(Mah, 0.1), -2/3);
	}
}

void friction::fricalc(double Mah, double SS, double nu)
{
	area_ratio = full_round_area / midel_area;
	Re = SS * Mah * full_length / nu;
	stream_calc(Re, Mah);
	C_fric = area_ratio * cif * num;
	std::cout << C_fric << std::endl;
}