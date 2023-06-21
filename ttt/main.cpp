// C++ program to convert decimal
// number to ternary number

#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

// Function to convert a decimal
// number to a ternary number
void convertToTernary(int N)
{
    // Base case
    if (N == 0)
        return;

    // Finding the remainder
    // when N is divided by 3
    int x = N % 3;
    N /= 3;
    if (x < 0)
        N += 1;

    // Recursive function to
    // call the function for
    // the integer division
    // of the value N/3
    convertToTernary(N);

    // Handling the negative cases
    if (x < 0)
        cout << x + (3 * -1);
    else
        cout << x;
}

// Function to convert the decimal to ternary
void convert(int Decimal)
{
    cout << "Ternary number of "
         << Decimal << " is: ";

    // If the number is greater
    // than 0, compute the
    // ternary representation
    // of the number
    if (Decimal != 0) {
        convertToTernary(Decimal);
    }
    else
        cout << "0" << endl;
}

// Driver code
int main()
{
    int Decimal = 37;

    convert(Decimal);

    return 0;
}
