#include "drag_force.h"


double drag_force::calculate_CX(double Mah, double SS, double nu)
{
	return fricalc(Mah, SS, nu) + prescalc();
}