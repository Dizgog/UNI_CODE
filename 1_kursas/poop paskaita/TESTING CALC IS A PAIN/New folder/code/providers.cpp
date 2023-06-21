#include "classes_logic.h"
#include <sstream>
#include <algorithm>


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: igyvendinti klases, kurios gauna informacija is string'o*/


void Get_information::save_operator(int index, vector <Operator> & operators, const Available_operators & manager, string equation)
{
    Type type;

    // jei unary operatorius, tai tarpo po jo nera
    if(isspace(equation[index + 1]) == 0)
    {
        type = UNARY;
    }
    else
    {
        type = BINARY;

    }

    Operator temp;

    temp.set_position(index);
    temp.set_symbol(equation[index]);
    temp.set_type(type);
    temp.set_priority(manager.get_priority(equation[index], type));

    operators.push_back(temp);
}

void Get_information::remove_operators_in_brackets(vector <Operator> & operators, vector <pair<int, int>> & brackets)
{
    for(unsigned int i = 0; i < operators.size(); ++i)
    {
        for(unsigned int j = 0; j < brackets.size(); ++j)
        {
            if(((operators[i].get_position() > brackets[j].first) && (operators[i].get_position() < brackets[j].second)))
            {
                operators.erase(operators.begin() + i);
                --i;
                break;
            }
        }
    }
}

void Get_information::save_brackets(int index, vector <pair<int, int>> & brackets, string equation)
{
    if(equation[index] == '(')
    {
        pair<int, int> temp;
        temp.first = index;
        temp.second = -1;

        brackets.push_back(temp);
    }
    else
    {
        int temp = brackets.size() - 1;

        if(temp < 0)
        {
            brackets.push_back(pair<int, int> (-1, -1));
            return;
        }

        while(brackets[temp].second != - 1 && temp > 0)
        {
            --temp;
        }

        brackets[temp].second = index;
    }
}

void Get_information::remove_unnecessary_brackets(vector <pair<int, int>> & brackets, vector <Operator> & operators, string & equation)
{
    if(brackets[0].first == 0 && brackets[0].second == ((int)equation.size()) - 1)
    {
        equation.erase(equation.begin());
        equation.pop_back();

        brackets.erase(brackets.begin());


        for(unsigned int i = 0; i < brackets.size(); ++i)
        {
            --brackets[i].first;
            --brackets[i].second;
        }

        for(unsigned int i = 0; i < operators.size(); ++i)
        {
            operators[i].set_position(operators[i].get_position() - 1);
        }
    }
}

void Get_information::get_operators(vector <Operator> & operators, string equation, const Available_operators & manager)
{
    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(isdigit(equation[i]) == 0 && isspace(equation[i]) == 0 && equation[i] != '.')
        {
             if(equation[i] != '(' && equation[i] != ')' && equation[i] != '.')
             {
                 save_operator(i, operators, manager, equation);
             }
        }
    }
}

void Get_information::get_brackets(vector <pair<int, int>> & brackets, string equation)
{
    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(equation[i] == '(' || equation[i] == ')')
        {
            save_brackets(i, brackets, equation);
        }
    }
}

void Get_information::get_information(vector <Operator> & operators,
     vector <pair<int, int>> & brackets, const Available_operators & manager, string & equation)
{
    get_operators(operators, equation, manager);
    get_brackets(brackets, equation);


    if(brackets.empty() == false)
    {
       remove_unnecessary_brackets(brackets, operators, equation);
    }


    if(operators.empty() == false)
    {
        remove_operators_in_brackets(operators, brackets);
    }
}


int Get_operands::find_other_bracket(int one_position, vector <pair<int, int>> brackets)
{
    for(unsigned int i = 0; i < brackets.size(); ++i)
    {
        if(brackets[i].first == one_position || brackets[i].second == one_position)
        {
            return i;
        }
    }

    return -1;
}

string Get_operands::get_operand_in_brackets(string equation, int start, int end)
{
    string operand_in_brackets;

    for(int i = start; i <= end; ++i)
    {
        operand_in_brackets.push_back(equation[i]);
    }

    return operand_in_brackets;
}

double Get_operands::find_left_if_brackets(int bracket_index, vector <pair<int, int>> & brackets,
                        string equation, const Available_operators & available)
{
    int brackets_index = find_other_bracket(bracket_index, brackets);

    int start = brackets[brackets_index].first;
    int end = bracket_index;

    brackets.erase(brackets.begin() + brackets_index);

    string temp_equation = get_operand_in_brackets(equation, start, end);

    One_equation temp(temp_equation, available);

    return temp.calculate();
}

double Get_operands::find_right_if_brackets(int bracket_index, vector <pair<int, int>> & brackets,
                        string equation, const Available_operators & available)
{
    int brackets_index = find_other_bracket(bracket_index, brackets);

    int start = bracket_index;
    int end = brackets[brackets_index].second;

    brackets.erase(brackets.begin() + brackets_index);

    string temp_equation = get_operand_in_brackets(equation, start, end);

    One_equation temp(temp_equation, available);

    return temp.calculate();
}

double Get_operands::convert_to_double(string operand_string)
{
    stringstream ss;
    ss << operand_string;

    double operand;

    ss >> operand;

    return operand;
}

double Get_operands::find_left(int operator_index, vector <pair<int, int>> & brackets,
                        string equation, const Available_operators & available)
{
    int j = operator_index - 1;

    if(isspace(equation[j]) != 0)
    {
       --j;
    }

    string left_operand;

    while(isspace(equation[j]) == 0 && j >= 0)
    {
        if(equation[j] == ')')
        {
           return find_left_if_brackets(j, brackets, equation, available);
        }

        left_operand.push_back(equation[j]);
        --j;
    }

    reverse(left_operand.begin(), left_operand.end());

    return convert_to_double(left_operand);
}

double Get_operands::find_right(int operator_index, vector <pair<int, int>> & brackets,
                                 string equation, const Available_operators & available)
{
    int j = operator_index + 1;

    if(isspace(equation[j]) != 0)
    {
       ++j;
    }

    string right_operand;

    while(isspace(equation[j]) == 0 && j < (int)equation.size())
    {
        if(equation[j] == '(')
        {
            return find_right_if_brackets(j, brackets, equation, available);
        }

        right_operand.push_back(equation[j]);
        ++j;
    }

    return convert_to_double(right_operand);
}
