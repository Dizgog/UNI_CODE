#include "classes_logic.h"


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: igyvendinti klases susijusias su prastinimu ir pati prastintoja/skaiciuotuva */


One_equation::One_equation(string equation, const Available_operators & available)
    :available(available)
{
    Get_information info;
    info.get_information(operators, brackets, available, equation);

    this -> equation = equation;
}

double One_equation::do_priority_operations(int operator_index)
{
    int current_priority = operators[operator_index].get_priority();
    ++operator_index;

    Get_operands operand;

    double num1 = operand.find_left(operators[operator_index].get_position(), brackets, equation, available);
    double num2;

    while((operator_index < (int) operators.size()) && current_priority > (operators[operator_index].get_priority()))
    {
        num2 = operand.find_right(operators[operator_index].get_position(), brackets, equation, available);

        num1 = available.do_operation(num1, num2, operators[operator_index].get_symbol());

        operators.erase(operators.begin() + operator_index);
    }

    return num1;
}

double One_equation::calculate()
{
    double num1;
    double num2;

    Get_operands operand;

    if(operators.size() == 0)
    {
        return operand.convert_to_double(equation);
    }


    for(unsigned int i = 0; i < operators.size(); ++i)
    {
        if(operators[i].get_type() == BINARY)
        {
            if(i == 0)
            {
                num1 = operand.find_left(operators[0].get_position(), brackets, equation, available);
            }

            if((operators.size() > 1 ) && (operators[i].get_priority() > operators[i + 1].get_priority()))
            {
                num2 = do_priority_operations(i);
            }
            else
            {
                num2 = operand.find_right(operators[i].get_position(), brackets, equation, available);
            }

            num1 = available.do_operation(num1, num2, operators[i].get_symbol());
        }
        else
        {
            num1 = operand.find_right(operators[i].get_position(), brackets, equation, available);

            num1 = available.do_operation(num1, operators[i].get_symbol());
        }
    }


    operators.clear();
    return num1;
}


Calculator::Calculator(const Available_operators & available)
    :available(available), validator(available.get_operators())
{

}

void Calculator::clear_when_error()
{
    validator.clear();
}

double Calculator::simplify(string equation)
{
    equation = validator.validate(equation);

    return One_equation(equation, available).calculate();
}

string Calculator::show_available_operators()
{
    return available.show_operators();
}

