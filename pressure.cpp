#include "pressure.h"
double pressure::prescalc(double Mah)
{
	return un_triangle_pres(Mah) + head_Cpres(Mah);
}

double pressure::head_Cpres(double Mah)
{
	const int N = 10;

	double Mah_v[N];

	double H_current[N];
	double H_0[N];
	double H_025[N];
	double H_05[N];
	double H_1[N];
	double H_2[N];
	double H_25[N];
	double H_3[N];
	double H_4[N];
	double H_5[N];

	std::ifstream Hco;

	Hco.open("HeadPressure.txt");

	double C_head = 0;


	for (int i = 0; i < N; i++)
	{
		Hco >> Mah_v[i];
		Hco >> H_0[i];
		Hco >> H_025[i];
		Hco >> H_05[i];
		Hco >> H_1[i];
		Hco >> H_2[i];
		Hco >> H_25[i];
		Hco >> H_3[i];
		Hco >> H_4[i];
		Hco >> H_5[i];

		if (elem[0].ratio >= 0 && elem[0].ratio < 0.25)
		{
			H_current[i] = H_0[i];
		}

		if (elem[0].ratio >= 0.25 && elem[0].ratio < 0.5)
		{
			H_current[i] = H_025[i];
		}

		if (elem[0].ratio >= 0.5 && elem[0].ratio < 1)
		{
			H_current[i] = H_05[i];
		}

		if (elem[0].ratio >= 1 && elem[0].ratio < 2)
		{
			H_current[i] = H_1[i];
		}

		if (elem[0].ratio >= 2 && elem[0].ratio < 2.5)
		{
			H_current[i] = H_2[i];
		}

		if (elem[0].ratio >= 2.5 && elem[0].ratio < 3)
		{
			H_current[i] = H_3[i];
		}

		if (elem[0].ratio >= 3 && elem[0].ratio < 4)
		{
			H_current[i] = H_4[i];
		}

		if (elem[0].ratio >= 4)
		{
			H_current[i] = H_5[i];
		}


		if (Mah >= Mah_v[i - 1] && Mah < Mah_v[i] && i>=1) { C_head = (H_current[i - 1]) + (Mah - Mah_v[i - 1]) * (H_current[i] - H_current[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };
	}


	Hco.close();
	return C_head;
}

double pressure::un_triangle_pres(double Mah)
{
	double res = 0;
	for (int i = 1; i < elem.size(); i++)
	{
		elem[i].C_pres = triangle_Cpres(Mah, elem[i].ratio) * (1 - elem[0].upper_area / elem[0].lower_area);
		res += elem[i].C_pres;
	}
	return res;
}

double pressure::triangle_Cpres(double Mah, double ratio)
{
	const int N = 6;

	double Mah_v[N];

	double H_current[N];
	double H_15[N];
	double H_2[N];
	double H_25[N];
	double H_3[N];
	double H_4[N];
	double H_5[N];

	std::ifstream Hco;

	Hco.open("TrianglePressure.txt");

	double C_head = 0;


	for (int i = 0; i < N; i++)
	{
		Hco >> Mah_v[i];
		Hco >> H_15[i];
		Hco >> H_2[i];
		Hco >> H_25[i];
		Hco >> H_3[i];
		Hco >> H_4[i];
		Hco >> H_5[i];


		if (ratio >= 1.5 && ratio < 2)
		{
			H_current[i] = H_15[i];
		}

		if (ratio >= 2 && ratio < 2.5)
		{
			H_current[i] = H_2[i];
		}

		if (ratio >= 2.5 && ratio < 3)
		{
			H_current[i] = H_3[i];
		}

		if (ratio >= 3 && ratio < 4)
		{
			H_current[i] = H_4[i];
		}

		if (ratio >= 4)
		{
			H_current[i] = H_5[i];
		}


		if (Mah >= Mah_v[i - 1] && Mah < Mah_v[i] && i >= 1) { C_head = (H_current[i - 1]) + (Mah - Mah_v[i - 1]) * (H_current[i] - H_current[i - 1]) / (Mah_v[i] - Mah_v[i - 1]); };
	}


	Hco.close();
	elem[0].C_pres = C_head;
	return C_head;
}