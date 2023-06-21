#include <iostream>
#include "CalcOps.h"
#include "Calculator.h"
#include "OperationType.h"

int main()
{
    double x = 0, y = 0;
    int ix = 0, iy = 0; //variables for double->int conversion to do modulus
    int a = 0; //actions for double elements
    int sa = 0; //actions for single elements
    int op = -1;
    std::string ms = "";
    SelectOperation _O = SelectOperation::Menu;
    SelectAction _A = SelectAction::Add;
    int running = true;
    std::string s;

    while (running)
    {
        std::cout << "Select the operation: \n1 - Single\n2 - Double\n3 - Sequence\n\n";
        std::cin >> op;

        if (op == 1)
        {
            _O = SelectOperation::Single;
            std::cout << "Enter element: \n";
            std::cin >> x;
        }
        if (op == 2)
        {
            _O = SelectOperation::Double;
            std::cout << "Enter elements: \n";
            std::cin >> x >> y;
            ix = x;
            iy = y;
        }

        CalcFunctions::CalcOps calc(x, y);
        CalcFunctions::CalcOpsSingle calcs(x);

        switch (_O)
        {
        case Menu:
            break;
        case Single:
            std::cout << "Choose action: \n1 - Negate\n";
            std::cin >> sa;
            break;
        case Double:
            std::cout << "Choose action: \n1 - Add\n2 - Substract\n3 - Multiply\n4 - Divide\n5 - Modulo\n";
            std::cin >> a;
            break;
        case Sequence:
            std::cout << "Enter a mathematical expression: \n"; //need parser with stack push pop
            break;
        default:
            break;
        }

        if (sa == 1)
            _A = SelectAction::Negate;
        if (a == 1)
            _A = SelectAction::Add;
        if (a == 2)
            _A = SelectAction::Substract;
        if (a == 3)
            _A = SelectAction::Multiply;
        if (a == 4)
            _A = SelectAction::Divide;
        if (a == 5)
        {
            CalcFunctions::CalcOps calc(ix, iy);
            _A = SelectAction::Modulus;
        }

        switch (_A)
        {
        case Add:
            std::cout << "\nAnswer: " << calc.Add() << std::endl;
            break;
        case Substract:
            std::cout << "\nAnswer: " << calc.Substract() << std::endl;
            break;
        case Multiply:
            std::cout << "\nAnswer: " << calc.Multiply() << std::endl;
            break;
        case Divide:
            std::cout << "\nAnswer: " << calc.Divide() << std::endl;
            break;
        case Modulus:
            std::cout << "\nAnswer: " << calc.Modulus() << std::endl;
            break;
        case Negate:
            std::cout << "\nAnswer: " << calcs.Negate() << std::endl;
            break;
        default:
            break;
        }

        std::cout << "\nContinue? Y/N\n";
        std::cin >> s;

        if (s == "Y" || "y")
        {
            SelectOperation::Menu;
            running = true;
        }
        if (s == "N" || "n")
            running = false;
        else
        {
            running = false;
        }
    }
}
