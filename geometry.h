#pragma once
#include <vector>
#include <iostream>

struct element
{
	double upper_diameter;
	double lower_diameter;
	double elem_length;
	double ratio;
};


class geometry
{
private:
	//std::vector<double> length; 
	//std::vector<double> diameter;
	std::vector<element> elem;

public:
	void set_elnumber(int n);

	void set_length(double l1, double l2, double l3);
	void set_length(double l1, double l2, double l3, double l4);

	void set_diameter(double d1, double d2, double d3);
	void set_diameter(double d1, double d2, double d3, double d4);

	void pre_calculations();
};

