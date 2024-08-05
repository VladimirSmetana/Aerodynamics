#include "inductance.h"




double inductance::E_pressure(double angle, double Mah)
{
    
    if (Mah < 1)
	{
		Mah = - sqrt(1 - sqr(Mah)) / elem[0].ratio;
	}
	else
	{
		Mah = sqrt(sqr(Mah) - 1) / elem[0].ratio;
	}

	const int N = 10;
	//double C_head = 0.035;
	double L_cyl = 0;

	double ratio;

	double Mah_v[N];
    double E_head = 0;
    double E_cone = 0;   
    double E = 0;

	double H_current[N];
	double H_head[N];
	double H_cone[N];


	std::ifstream Hco;

	Hco.open("resources/EPressure.txt");


	ratio = L_cyl / elem[0].ratio;

	for (int i = 0; i < N; i++)
	{
		Hco >> Mah_v[i];
		Hco >> H_head[i];
		Hco >> H_cone[i];

		if (Mah >= Mah_v[i - 1] && Mah < Mah_v[i] && i >= 1) { E_head = (H_head[i - 1]) + (Mah - Mah_v[i - 1]) * (H_head[i] - H_head[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };
		if (Mah >= Mah_v[i - 1] && Mah < Mah_v[i] && i >= 1) { E_cone = (H_cone[i - 1]) + (Mah - Mah_v[i - 1]) * (H_cone[i] - H_cone[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };        
	}

    elem[0].C_ind = (elem[0].CY+rad(2*E_head))*rad(sqr(angle));
    for (int j = 1; j < elem.size(); j++)
	{
		if (elem[j].upper_diameter < elem[j].lower_diameter) 
        { 

            elem[j].C_ind = (elem[j].CY*elem[j].upper_area/elem.back().upper_area+rad(2*E_cone*elem[j].upper_area/elem.back().upper_area))*sqr(angle);
        }
	}

    for (int j = 0; j < elem.size(); j++)
	{
        E+= elem[j].C_ind;
    }

	Hco.close();
    //std_print(E);
	return E;
}