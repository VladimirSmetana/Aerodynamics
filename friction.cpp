#include "friction.h"

void friction::fricalc()
{
	area_ratio = full_round_area / midel_area;
	C_fric = area_ratio * cif * num;
}