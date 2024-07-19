// ARD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "union_stream.h"
int main()
{
    union_stream G;
    G.set_elnumber(4);
    G.set_diameter(3.7, 3.7, 4.1, 4.1);
    G.set_length(7, 7, 2, 14);
    double velocity = 300;
    double altitude = 0.1;

    double Mah = 0.1;//velocity / A.get_SV();
    double arrayMah[15]{ 0.1, 0.3, 0.5, 0.7, 0.9, 1.0, 1.3, 1.5, 2, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
    double arrayH[5]{ 0.1, 10, 20, 40, 60 };



    for (int j = 0; j < 5; j++)
    {
        atmosphere A(arrayH[j] * 1000);
        for (int i = 0; i < 15; i++)
            {
                G.calculate_CXY(arrayMah[i], A.get_SV(), A.get_dyn());


            }
        std::cout << std::endl;
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
