#include "../union_stream.h"

union_stream A;

bool set_elnumber(int elnumber)
{
    if (elnumber <= 0)
    {
        return false;
    }
    A.set_elnumber(elnumber);
    return true;
}

bool set_diameter(const std::vector<double> &diameters)
{
    for (double diameter : diameters)
    {
        if (diameter <= 0)
        {
            return false;
        }
    }

    A.set_diameter(diameters);
    return true;
}

bool set_length(const std::vector<double>& lengths)
{
    for (double length : lengths)
    {
        if (length <= 0)
        {
            return false;
        }
    }

    A.set_length(lengths);
    return true;    
}

