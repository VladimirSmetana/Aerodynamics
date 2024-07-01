#pragma once
#include "friction.h"

class drag_force : public friction
{
public:
	void calculate_CX();
};

