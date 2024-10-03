#include "geometry.h"
#include <iostream>
#include <fstream>
#include <string>

class inductance : virtual public geometry
{
public:
    double E_pressure(double angle, double Mah);
};