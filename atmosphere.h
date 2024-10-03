#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H
#include <cmath>
#define M_PI 3.14159265358979323846
#endif // ATMOSPHERE_H


class atmosphere
    {
    private:

        double HT[15]{1     ,  11019,  32000 , 47350 , 71802 , 86152 , 104128, 120000 , 140000, 160000, 200000, 325000, 400000, 600000, 1200000};

        double dynH[11]{ 1, 1000, 5000, 10000, 12000, 14000, 20000, 32000, 40000, 60000, 80000 };
        double dynT[11]{ 1.46, 1.58, 2.21, 3.53, 4.56, 6.24, 16, 110, 401, 5110, 71600};

        double TT[15]{288.15,  216.65, 228.65, 270.65, 214.65, 186.65, 203.81, 334.417, 559.6,  695.6,  834.4,  941.9,  984.65, 995.9,  1000};
        double TMM[8]{288.15,  216.65, 228.65, 270.65, 214.65, 186.65, 212.0 , 380.60 };

        double Bst [11]{-0.0065, -0.0065, 0.0000 , 0.0010, 0.0028, 0, -0.0028, -0.0020, 0, 0.0030, 0.0110};
        double Hst [11] {1,  11019, 20630, 32000 , 47350 , 51412, 71802 , 86152 , 95411, 104128, 120000};

        static constexpr double PI = 3.1415926535;
        static constexpr double Mc = 28.964420;
        static constexpr double gc = 9.80665;
        static constexpr double ac = 340.294;
        static constexpr double Hpc = 8434.5;
        static constexpr double pc = 101325.0;
        static constexpr double Tc = 288.15;
        static constexpr double vc = 458.94;
        static constexpr double yc = 12.013;
        static constexpr double poc = 1.2250;
        static constexpr double SOS = 110.4;
        static constexpr double RB = 8314.32;
        static constexpr double r = 287.05287;
        static constexpr double hi = 1.4;
        static constexpr double R = 6371000;

        double const nc = 25.471 * pow(10, 24);
        double const nuc = 14.607 * pow(10, -6);
        double const muc = 17.894 * pow(10, -6);
        double const lac = 25.343 * pow(10, -3);
        double const omegac = 6.9193 * pow(10, 9);
        double const Na = 602.257 * pow(10, 24);
        double const BS = 1.458 * pow(10, -6);
        double const b = 0.365 * pow(10, -9);  
        double const dync = 14.607 * pow(10, -6);

        double B[4];
        double A[5];

        double po;
        double Bett;
        double mstep;
        double pp;
        double tCel; 
        double Hmas; 
        double vsred; 
        double lsred; 
        double lamb;
        double Hs;
        double Hp;
        double Pap;
        double Tm;
        double Mol; 
        double g;
        double T;
        double P; 
        double n; 
        double yyd;
        double a;
        double omega;
        double dyn;

    public:
        explicit atmosphere (double H);

        double get_T();
        double get_n();
        double get_pressure();
        double get_density();
        double get_AOG();
        double get_SV();
        double get_dyn();
    };
