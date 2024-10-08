#include "union_stream.h"

void union_stream::calculate_CXY(const double &angle, const double &Mah, const double &SS, const double &nu)
{
	CX = calculate_CX(Mah, SS, nu);
	CY = calculate_CY(Mah);
	// std::cout << "out! " << CY << std::endl;
	E = E_pressure(angle, Mah);
	CX += (CY + E);
	CY -= rad(CY + E);
	CY *= angle;
	// std_print(CY + E);
}