#pragma once
#include "geometry.h"
class friction: public geometry
{
	private:
		double area_ratio;
		double cif;
		double num;
	public:
		void fricalc();
		double C_fric;
};

