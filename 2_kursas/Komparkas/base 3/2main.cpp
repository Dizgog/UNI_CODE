// C++ program to convert a
// ternary number to decimal number
 
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
 
// Function to convert a ternary
// number to a decimal number
void convertToDecimal(int N)
{
    cout << "Decimal number of "
         << N << " is: ";
 
    // If the number is greater than 0,
    // compute the decimal
    // representation of the number
    if (N != 0) {
 
        int decimalNumber = 0,
            i = 0, remainder;
 
        // Loop to iterate through
        // the number
        while (N != 0) {
            remainder = N % 10;
            N /= 10;
 
            // Computing the decimal digit
            decimalNumber += remainder
                             * pow(3, i);
            ++i;
        }
        cout << decimalNumber << endl;
    }
    else
        cout << "0" << endl;
}
 
// Driver code
int main()
{
    int Ternary = 10202202;
 
    convertToDecimal(Ternary);
 
    return 0;
}