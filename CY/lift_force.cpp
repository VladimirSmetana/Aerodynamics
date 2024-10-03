#include "lift_force.h"


double lift_force::calculate_CY(double Mah)
{
	return head_lift(Mah) + un_triangle_lift(Mah);
}

double lift_force::head_lift(double Mah)
{
	if (Mah < 1)
	{
		Mah = - sqrt(1 - sqr(Mah)) / elem[0].ratio;
	}
	else
	{
		Mah = sqrt(sqr(Mah) - 1) / elem[0].ratio;
	}

	const int N = 9;
	double C_head = 0.035;
	double L_cyl = 0;

	double ratio;

	double Mah_v[N];

	double H_current[N];
	double H_0[N];
	double H_05[N];
	double H_1[N];
	double H_2[N];
	double H_4[N];

	std::ifstream Hco;

	Hco.open("resources/HeadNormal.txt");



	for (int j = 1; j < elem.size(); j++)
	{
		if (elem[j].upper_diameter < elem[j].lower_diameter) { L_cyl /= elem[j].lower_diameter; break; }
		else L_cyl += elem[j].elem_length;
	}

	ratio = L_cyl / elem[0].ratio;

	for (int i = 0; i < N; i++)
	{
		Hco >> Mah_v[i];
		Hco >> H_0[i];
		Hco >> H_05[i];
		Hco >> H_1[i];
		Hco >> H_2[i];
		Hco >> H_4[i];


		if (ratio >= 0 && ratio < 0.5)
		{
			H_current[i] = H_0[i];
		}

		else if (ratio >= 0.5 && ratio < 1)
		{
			H_current[i] = H_05[i];
		}

		else if (ratio >= 1 && ratio < 2)
		{
			H_current[i] = H_1[i];
		}

		else if (ratio >= 2 && ratio < 4)
		{
			H_current[i] = H_2[i];
		}

		else if (ratio >= 4)
		{
			H_current[i] = H_4[i];
		}


		if (i >= 1 && Mah >= Mah_v[i - 1] && Mah < Mah_v[i]) { C_head = (H_current[i - 1]) + (Mah - Mah_v[i - 1]) * (H_current[i] - H_current[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };
	}


	Hco.close();
	elem[0].CY = C_head;
	return C_head;
}

double lift_force::un_triangle_lift(double Mah)
{
	double res = 0;
	double big_rat = 0;
	double small_rat = 0;
	double S_rat;

	for (int i = 1; i < elem.size(); i++)
	{
		if (elem[i].upper_area < elem[i].lower_area)
		{
			big_rat	= elem[i].ratio;
			S_rat = elem[i].upper_area / elem[i].lower_area;

			elem[i].CY = triangle_lift(Mah, big_rat, i) - free_triangle_lift(i)* S_rat;
			res += elem[i].CY * elem[i].upper_area / elem.back().upper_area;
		}
	}
	return res;
}


double lift_force::free_triangle_lift(int index)
{
	double arg = elem[index].lower_diameter / 2 /(elem[index].virtual_length - elem[index].elem_length);
	double Q = atan(arg);
	return (2 / 57.3) * sqr(cos(Q));
}

double lift_force::triangle_lift(double Mah, double ratio, int index)
{
	if (Mah < 1)
	{
		Mah = - sqrt(1 - sqr(Mah)) / ratio;
	}
	else
	{
		Mah = sqrt(sqr(Mah) - 1) / ratio;
	}

	const int N = 10;

	double Mah_v[N];

	double H_current[N];
	double H_0[N];
	double H_1[N];
	double H_2[N];
	double H_3[N];
	double H_4[N];

	double L_cyl = 0;




	std::ifstream Hco;

	Hco.open("resources/TriangleNormal.txt");

	double C_head = 0;

	for (int j = index+1; j < elem.size(); j++)
	{
		if (elem[j].upper_diameter < elem[j].lower_diameter) { L_cyl /= elem[j].lower_diameter; break; }
		else L_cyl += elem[j].elem_length;
	}

	ratio = L_cyl / ratio;

	for (int i = 0; i < N; i++)
	{
		Hco >> Mah_v[i];
		Hco >> H_0[i];
		Hco >> H_1[i];
		Hco >> H_2[i];
		Hco >> H_3[i];
		Hco >> H_4[i];

			
		if (ratio > 0 && ratio < 1)
		{
			H_current[i] = H_0[i];
		}

		else if (ratio >= 0 && ratio < 1)
		{
			H_current[i] = H_0[i];
		}

		else if (ratio >= 1 && ratio < 2)
		{
			H_current[i] = H_1[i];
		}

		else if (ratio >= 2 && ratio < 3)
		{
			H_current[i] = H_2[i];
		}

		else if (ratio >= 3 && ratio < 4)
		{
			H_current[i] = H_3[i];
		}

		else if (ratio >= 4)
		{
			H_current[i] = H_4[i];
		}


		else if (Mah >= Mah_v[i - 1] && Mah < Mah_v[i] && i >= 1) { C_head = (H_current[i - 1]) + (Mah - Mah_v[i - 1]) * (H_current[i] - H_current[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };
	}


	Hco.close();
	return C_head;
}