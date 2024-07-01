#pragma once
#include <vector>
#include <iostream>
#include <cmath>


struct element
{
	double upper_diameter;
	double lower_diameter;
	double elem_length;
	double virtual_length;
	double ratio;
	double round_area;
	double lower_area;
	double base_line;
};


class geometry
{
private:
	std::vector<element> elem;
	double full_length;
	double full_round_area;
	double const PI = 3.141592653589793;

public:
	void set_elnumber(int n);

	void set_length(double l1, double l2, double l3);
	void set_length(double l1, double l2, double l3, double l4);

	void set_diameter(double d1, double d2, double d3);
	void set_diameter(double d1, double d2, double d3, double d4);

	void pre_calculations();
};

