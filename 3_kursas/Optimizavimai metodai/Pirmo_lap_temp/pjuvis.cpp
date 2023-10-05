#include <iostream>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>
// Funkcijos, kurią norime optimizuoti, aprašymas.
double f(double x)
{
    return ((x * x - 0) * (x * x - 0)) / 9 - 1;
}

int main()
{
    const double epsilon = 0.00001; // Tikslumas
    double a = 0.0;              // Pradinis intervalo pradžios taškas
    double b = 10.0;             // Pradinis intervalo pabaigos taškas

    double tau = (sqrt(5.0) - 1.0) / 2.0; // Auksinio pjūvio konstanta

    double x1 = a + (1.0 - tau) * (b - a);
    double x2 = a + tau * (b - a);

    double f1 = f(x1);
    double f2 = f(x2);

    int loop = 1;
    int funk = 0;
    std::ofstream failas;
    failas.open("pjuvis.txt");

    while (std::abs(b - a) > epsilon)
    {
        if (f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + (1.0 - tau) * (b - a);
            f1 = f(x1);
            funk++;
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + tau * (b - a);
            f2 = f(x2);
            funk++;
        }
        failas << loop << ": "
               << "x: " << (a + b) / 2.0 << "\n";
        loop++;
    }

    double minimum_x = (a + b) / 2.0;
    failas << "min reiksme: " << minimum_x << " Funkcija iškviesta " << funk + 2;
    std::cout << "Minimum x: " << minimum_x << std::endl;

    return 0;
}