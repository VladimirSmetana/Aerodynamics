#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include "atmosphere.h"

struct element
{
	double upper_diameter;
	double lower_diameter;
	double elem_length;
	double virtual_length;
	double ratio;
	double round_area;
	double upper_area;
	double lower_area;
	double base_line;

	double C_fric;
	double C_pres;
	double C_ind;
	double CX;
	double CY;
};

class geometry
{

protected:
	std::vector<element> elem;
	double full_length = 0;
	double full_round_area = 0;
	double full_ratio;
	double midel_diameter;
	double midel_area;
	double cif;
	double num;

public:
	void set_elnumber(const int &n);
	void set_length(const std::vector<double>& lengths);
	void set_diameter(const std::vector<double>& diameters);

private:
	void pre_calculations();

	// math
public:
	double const PI = 3.141592653589793;
	double min(const double &x, const double &y);
	double sqr(const double &x);
	double rad(const double &x);
	template <typename T>
	void std_print(T x);
};
