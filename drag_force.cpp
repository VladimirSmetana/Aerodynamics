#include "drag_force.h"
#include "friction.h"

void drag_force::calculate_CX(double Mah, double SS, double nu)
{
	fricalc(Mah, SS, nu);
}