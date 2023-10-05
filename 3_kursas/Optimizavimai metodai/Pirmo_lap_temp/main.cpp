#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define EPSILON 0.0001

double funkcija(double x)
{
    return ((x * x - 0) * (x * x - 0)) / 9 - 1;
}

void pusiauDalinimas(double a, double b)
{
    ofstream failas;
    failas.open("intervalo_dalijimo_pusiau.txt");
    double c = a;
    int loop = 1;
    int funk = 0;
    while (((b - a)) > EPSILON)
    {

        c = (a + b) / 2;

        if (funkcija(c) == 0.0)
        {
            funk++;
            break;
        }

        else if (funkcija(c) < funkcija(b))
            b = c;
        else
            a = c;

        funk += 2;

        failas << loop << ": " << c << "\n";
        loop++;
    }
    failas << funk;
    std::cout << "x: " << c;
}

int main()
{

    double a = 0, b = 10;
    pusiauDalinimas(a, b);
    return 0;
}
