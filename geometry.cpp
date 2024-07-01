#include "geometry.h"

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
}

void geometry::set_length(double l1, double l2, double l3, double l4)
{
	elem[0].elem_length = l1;
	elem[1].elem_length = l2;
	elem[2].elem_length = l3;
	elem[3].elem_length = l4;
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
		elem[i].ratio = elem[i].elem_length / elem[i].lower_diameter;
	}
}