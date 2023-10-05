#include <bits/stdc++.h>
#include <math.h>
#define EPSILON 1e-4
using namespace std;

double func(double x)
{
    return ((pow(2, (pow(2, x) - 8))) / 9) - 1;
}
double derivFunc(double x)
{
    return 4 * (((x * x * x) - 0 * x)) / 9;
}

double derivFunction2(double x)
{
    return 4 * (3 * (x * x) - 0) / 9;
}
void newtonRaphson(double x)
{
    ofstream failas;
    failas.open("niutionas.txt");
    double h = derivFunc(x) / derivFunction2(x);
    int loop = 1;
    int funk = 0;
    while (abs(h) >= EPSILON)
    {
        h = derivFunc(x) / derivFunction2(x);
        x = x - h;
        failas << loop << ": "
               << "x: " << x << "\n";
        loop++;
        funk++;
    }
    failas << funk;

    cout << "x: " << x;
    cout << " f(x): " << h;
}

int main()
{
    newtonRaphson(5.0);
    return 0;
}