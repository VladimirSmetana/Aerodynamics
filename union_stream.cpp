#include "union_stream.h"

void union_stream::calculate_CXY(double angle, double Mah, double SS, double nu)
{
	CX = calculate_CX(Mah, SS, nu);
	CY = calculate_CY(Mah);
	//std::cout << "out! " << CY << std::endl;
	E = E_pressure(angle, Mah);
	CX += (CY + E);
	CY -= rad(CY + E);
	CY *= angle;
	//std_print(CY + E);
}