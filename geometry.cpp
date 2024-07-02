#include "geometry.h"
#include <math.h>

double geometry::min(double x, double y)
{
	if (x < y) return x;
	if (y < x) return y;
}

void geometry::set_elnumber(int n)
{
	//length.resize(n);
	//diameter.resize(n);
	elem.resize(n);
}

void geometry::set_length(double l1, double l2, double l3)
{
	elem[0].elem_length = l1;
	elem[1].elem_length = l2;
	elem[2].elem_length = l3;
	pre_calculations();
}

void geometry::set_length(double l1, double l2, double l3, double l4)
{
	elem[0].elem_length = l1;
	elem[1].elem_length = l2;
	elem[2].elem_length = l3;
	elem[3].elem_length = l4;
	pre_calculations();
}

void geometry::set_diameter(double d1, double d2, double d3)
{
	elem[0].upper_diameter = 0;
	elem[0].lower_diameter = d1;

	elem[1].upper_diameter = d1;
	elem[1].lower_diameter = d2;

	elem[2].upper_diameter = d2;
	elem[2].lower_diameter = d3;
}

void geometry::set_diameter(double d1, double d2, double d3, double d4)
{
	elem[0].upper_diameter = 0;
	elem[0].lower_diameter = d1;

	elem[1].upper_diameter = d1;
	elem[1].lower_diameter = d2;

	elem[2].upper_diameter = d2;
	elem[2].lower_diameter = d3;

	elem[3].upper_diameter = d3;
	elem[3].lower_diameter = d4;
}

void geometry::pre_calculations()
{
	for (int i = 0; i < elem.size(); i++)
	{
		elem[i].lower_area = PI * pow(elem[i].upper_diameter,2)/4;
		elem[i].base_line = sqrt(pow(elem[i].elem_length, 2) + pow(elem[i].lower_diameter - elem[i].upper_diameter, 2) / 4);
		elem[i].virtual_length = elem[i].elem_length + elem[i].elem_length / (elem[i].lower_diameter / elem[i].upper_diameter  - 1);
		elem[i].round_area = PI * (elem[i].upper_diameter + elem[i].lower_diameter) * elem[i].base_line / 2;

		full_length += elem[i].elem_length;
		full_round_area += elem[i].round_area;

		if (elem[i].upper_diameter < elem[i].lower_diameter && abs(elem[i].upper_diameter)>0.1)
		{
			elem[i].ratio = elem[i].virtual_length / elem[i].lower_diameter;
		}
		else 
		{
			elem[i].ratio = elem[i].elem_length / elem[i].lower_diameter;
		}
	}
	midel_diameter = elem.back().upper_diameter;
	midel_area = elem.back().lower_area;
}