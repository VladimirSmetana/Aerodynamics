#include "geometry.h"
#include <math.h>

double geometry::min(const double &x, const double &y)
{
	if (x < y)
		return x;
	else if (y < x)
		return y;
	else
		return x;
}

double geometry::sqr(const double &x)
{
	return x * x;
}

double geometry::rad(const double &x)
{
	return x / 57.3;
}

template <typename T>
void geometry::std_print(T x)
{
	std::cout << x << std::endl;
}

void geometry::set_elnumber(const int &n)
{
	// length.resize(n);
	// diameter.resize(n);
	elem.resize(n);
}


void geometry::set_length(const std::vector<double>& lengths)
{
	for (size_t i = 0; i < lengths.size(); ++i) {
	elem[i].elem_length = lengths[i];}
	pre_calculations();
}




void geometry::set_diameter(const std::vector<double>& diameters) {
    
    for (size_t i = 0; i < diameters.size(); ++i) {
        if (i == 0) {
            elem[i].upper_diameter = 0;
            elem[i].lower_diameter = diameters[i];
        } else {
            elem[i].upper_diameter = diameters[i - 1];
            elem[i].lower_diameter = diameters[i];
        }
    }
}

void geometry::pre_calculations()
{
	for (int i = 0; i < elem.size(); i++)
	{
		if (i == 0)
		{
			elem[i].base_line = 2 * PI * sqrt(pow(elem[i].elem_length, 2) + pow(elem[i].upper_diameter / 2, 2));
			elem[i].round_area = 2 * PI * elem[i].elem_length * elem[i].upper_diameter / 2 + PI * pow(elem[i].elem_length, 2);
		}
		else
		{
			elem[i].base_line = sqrt(pow(elem[i].elem_length, 2) + pow(elem[i].lower_diameter - elem[i].upper_diameter, 2) / 4);
			elem[i].round_area = PI * (elem[i].upper_diameter + elem[i].lower_diameter) * elem[i].base_line / 2;
		}

		elem[i].upper_area = PI * pow(elem[i].upper_diameter, 2) / 4;
		elem[i].lower_area = PI * pow(elem[i].lower_diameter, 2) / 4;
		elem[i].virtual_length = elem[i].elem_length + elem[i].elem_length / (elem[i].lower_diameter / elem[i].upper_diameter - 1);

		full_length += elem[i].elem_length;
		full_round_area += elem[i].round_area;

		if (elem[i].upper_diameter < elem[i].lower_diameter && abs(elem[i].upper_diameter) > 0.1)
		{
			elem[i].ratio = elem[i].virtual_length / elem[i].lower_diameter;
		}
		else
		{
			elem[i].ratio = elem[i].elem_length / elem[i].lower_diameter;
		}
	}
	full_ratio = full_length / elem.back().upper_diameter;
	midel_diameter = elem.back().upper_diameter;
	midel_area = elem.back().lower_area;
}