// ARD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <array>
#include "union_stream.h"




int main()
{

    union_stream G;
    G.set_elnumber(4);
    G.set_diameter(3.7, 3.7, 4.1, 4.1);
    G.set_length(7, 7, 2, 14);

    // const double altitude = 3;
    // const double velocity = 400;
    // const double Mah = 0.1;//velocity / A.get_SV();

    std::array<double, 15> arrayMah = {0.1, 0.3, 0.5, 0.7, 0.9, 1.0, 1.3, 1.5, 2, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
    std::array<double, 5> attack_angle = {2, 4, 6, 8, 10}; 
    std::array<double, 5> arrayH = {0, 10, 20, 40, 60};

    for (int j = 0; j < 5; j++)
    {
        std::ofstream aero_file("results/aero_file_" + std::to_string(j) + ".csv");
        aero_file << "Mah, Cx, Cy\n";
        atmosphere A(arrayH.at(j) * 1000);
        for (auto &arrayMah_:arrayMah)
        {
            G.calculate_CXY(G.rad(attack_angle.at(j)), arrayMah_, A.get_SV(), A.get_dyn());
            aero_file << arrayMah_ << "," << G.CX << "," << G.CY << "\n";
            //std::cout << G.CY << std::endl;
        }
        std::cout << std::endl;
        aero_file.close();
    }
}
