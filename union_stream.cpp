#include "union_stream.h"

void union_stream::calculate_CXY(double Mah, double SS, double nu)
{

	CX = calculate_CX(Mah, SS, nu);

	CY = calculate_CY(Mah);

}