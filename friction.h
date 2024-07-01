#pragma once
#include "geometry.h"
class friction: public geometry
{
	private:
		double area_ratio;
	public:
		void fricalc();
};

