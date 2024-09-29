// ARD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "union_stream.h"

int main()
{
    
    union_stream G;
    G.set_elnumber(4);
    G.set_diameter(3.7, 3.7, 4.1, 4.1);
    G.set_length(7, 7, 2, 14);
    const double velocity = 400;
    const double altitude = 3;
    const double attack_angle = 5;

    const double Mah = 0.1;//velocity / A.get_SV();
    const double arrayMah[15]{ 0.1, 0.3, 0.5, 0.7, 0.9, 1.0, 1.3, 1.5, 2, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
    const double arrayH[5]{ 0.1, 10, 20, 40, 60 };


    for (int j = 0; j < 5; j++)
    {
        std::ofstream aero_file("aero_file_" + std::to_string(j) + ".csv");
        aero_file << "Mah, Cx, Cy\n";
        atmosphere A(arrayH[j] * 1000);
        for (int i = 0; i < 15; i++)
            {
                G.calculate_CXY(G.rad(attack_angle), arrayMah[i], A.get_SV(), A.get_dyn());
                aero_file << arrayMah[i] << "," << G.CX << "," << G.CY << "\n";                
            }
        std::cout << std::endl;
        aero_file.close();
    }
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
