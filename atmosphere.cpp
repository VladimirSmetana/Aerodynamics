#include "atmosphere.h"

atmosphere::atmosphere(double H) : po(0),
                                   Bett(0),
                                   mstep(0),
                                   pp(0),
                                   tCel(0),
                                   Hmas(0),
                                   vsred(0),
                                   lsred(0),
                                   lamb(0),
                                   ////////////
                                   T(Tc),
                                   P(pc),
                                   n(nc),
                                   yyd(yc),
                                   a(ac),
                                   omega(omegac),
                                   dyn(dync)
{
    Tm = Tc * Mc / Mol;
    Hp = (R * H) / (R + H);
    g = gc * pow(R / (R + H), 2);

    for (int i = 1; i < 15; i++)
    {
        if (H >= HT[i - 1] && H < HT[i])
        {
            T = (TT[i - 1]) + (H - HT[i - 1]) * (TT[i] - TT[i - 1]) / (HT[i] - HT[i - 1]);
        };
    }

    for (int i = 1; i < 8; i++)
    {
        if (H >= HT[i - 1] && H < HT[i])
        {
            Tm = (TMM[i - 1]) + (H - HT[i - 1]) * (TMM[i] - TMM[i - 1]) / (HT[i] - HT[i - 1]);
        };
    }

    for (int i = 1; i < 11; i++)
    {
        if (H >= dynH[i - 1] && H < dynH[i])
        {
            dyn = (dynT[i - 1]) + (H - dynH[i - 1]) * (dynT[i] - dynT[i - 1]) / (dynH[i] - dynH[i - 1]);
        };
        if (H > 80000)
            dyn = 71600;
    }
    dyn *= pow(10, -5);

    if (H < 94000)
    {


        /// Молярная масса
        Mol = Mc;

        Bett = (7466 * pow(H, 3) - 1262795028 * pow(H, 2) + 61597340039789 * H - 833732588564247562) * pow(10, -20);
        /// Давление
        if (abs(Bett) < 0.0000001)
        {
            pp = log(101325);
            Hs = H - 0.1;
            P = exp(pp - (0.434294 * gc / (r * T)) * (H - 0));
        } // P = exp(pp - (0.434294 * gc / (r * T)) * (H - Hs)); }
        if (abs(Bett) >= 0.0000001)
        {
            pp = log(101325);
            Hs = H - 0.1;
            P = exp(pp - (gc * log((Tm + Bett * (H - 0)) / Tm)) / (Bett * r));
        }
        Pap = 101325 * exp(-gc * H * Mc / (RB * T));
        /// Плотность
        po = (P * Mol) / (RB * T);
        /// Концентрация частиц воздуха
        n = 7.243611 * pow(10, 22) * P / T;

        tCel = T - 273.15;
        yyd = po * g;
        Hmas = (RB / Mol) * (T / g);
        a = 20.046796 * sqrt(T);
        vsred = 145.50685 * T / Mol;
        lsred = 2.332376e-5 * T / P;
        omega = 6.238629e6 * P / sqrt(T * Mol);
        lamb = (2.648151e-3 * pow(T, 3 / 2)) / (T + 245.4 * pow(10, -(12 / T)));
        // dyn = lamb / po;
    }
}

double atmosphere::get_T()
{
    return T;
}

double atmosphere::get_n()
{
    return n;
}
double atmosphere::get_pressure()
{
    return P;
}
double atmosphere::get_density()
{
    return po;
}

double atmosphere::get_AOG()
{
    return g;
}

double atmosphere::get_SV()
{
    return a;
}

double atmosphere::get_dyn()
{
    return dyn;
}