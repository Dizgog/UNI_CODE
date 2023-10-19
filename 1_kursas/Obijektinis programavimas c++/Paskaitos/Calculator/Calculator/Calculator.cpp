#include <iostream>
#include "Calculator.h"


double Calc::add(double first, double second)
{
   return first + second;
}

double Calc::sub(double first, double second)
{
    return first - second;
}

double Calc::mul(double first, double second)
{
    return first * second;
}

double Calc::div(double first, double second)
{
    return first / second;
}

double Calc::rem(double first, double second)
{
    return first - (int)(first/second) * second;
}

double Calc::getAnswer(double first, char operat, double second)
{
    switch(operat){
        case '+':
        return add(first, second);
        case '-':
        return sub(first, second);
        case '*':
        return mul(first, second);
        case '/':
        return div(first, second);
        case '%':
        return rem(first, second);
        default:
        return -1;
    }

return 0;

}
