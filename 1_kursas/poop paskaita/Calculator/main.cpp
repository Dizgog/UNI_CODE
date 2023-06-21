#include <iostream>
#include "Calculator.h"

int main(int argc, char const *argv[])
{
    
    double first, second;
    char op;
    std::cout << "Enter a simple equation made out of 2 numbers" << std::endl;
    std::cin >> first >> op >> second; 
    Calc math;
    std::cout << math.getAnswer(first, op, second) <<std::endl;
    return 0;
}
