#pragma once
#include <vector>
#include <iostream>

class geometry
{
private:
	std::vector<double> length; 
	std::vector<double> diameter;

public:
	void set_elnumber(int n);

	void set_lenght(double l1, double l2, double l3);
	void set_lenght(double l1, double l2, double l3, double l4);

	void set_diametr(double d1, double d2, double d3);
	void set_diametr(double d1, double d2, double d3, double d4);
};

