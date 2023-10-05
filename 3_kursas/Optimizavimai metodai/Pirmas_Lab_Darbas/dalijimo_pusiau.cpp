#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define EPSILON 1e-4
 
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return ((x * x - 0) * (x * x - 0)) / 9 - 1;
}
 
// Prints root of func(x) with error of EPSILON
void bisection(double left, double right)
{
    ofstream failas;
    failas.open ("intervalo_dalijimo_pusiau.txt");
    double middle;
    
    while ((right-left) >= EPSILON)
    {
        
        
        // Find middle point
        middle =((left+right)/2);
        cout << func(middle) << " ";
        failas << middle << "\n";
        //failas << "Intervalo pradžia: " << left << " Intervalo vidurio taškas: " << middle << " Intervalo pabaiga: " << right << "\n" ;
        // Check if middle point is root
        if (func(middle) == 0.0)
            break;
 
        // Decide the side to repeat the steps
        else if (func(middle) * func(left) < 0)
            right = middle;
        else
            left = middle;

           
    }
        failas << func(middle) << "\n";
        failas << "Intervalo pradžia: " << func(left) << " Intervalo vidurio taškas: " << func(middle) << " Intervalo pabaiga: " << func(right) << "\n" ;
    std::cout << "The value of root is : " << middle;
}
 
// Driver program to test above function
int main()
{
    
    // Initial values assumed
    double a = 0 , b = 10;
    bisection(a, b);
    return 0;
}