#include "classes_logic.h"
#include <cctype>


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: igyvendinti klases susijusias su string'o validacija */


#define INVALID_SYMBOLS "\nThere are invalid symbols"

#define BRACKETS_INVALID "\nBrackets are invalid"
#define BRACKETS_EMPTY "\nBrackets are empty"

#define NO_OPERANDS "\nOperators do not have operands"

#define INVALID_NUMBER_FORMAT "\nNumber format is not valid"

#define EMPTY "\nYou must enter something"


Incorrect_input::Incorrect_input(string error_message)
{
    this -> error_message = error_message;
}

string Incorrect_input::get_error_message() const
{
    return error_message;
}


Validator::Validator(const vector <Operator> & available_operators)
    :available_operators(available_operators)
{

}

void Validator::check_if_is_operator(int position)
{
    for(unsigned int i = 0; i < available_operators.size(); ++i)
    {
        if(available_operators[i].get_symbol() == equation[position])
        {
            validate_operators.push_back(position);
            return;
        }
    }

    throw Incorrect_input(INVALID_SYMBOLS);
}

void Validator::check_if_operators_have_operands()
{
    for(unsigned int i = 1; i < validate_operators.size(); ++i)
    {
        if(validate_operators[i] - validate_operators[i - 1] == 1)
        {
            throw Incorrect_input(NO_OPERANDS);
        }
    }

    // patikrina paskutini operatoriu, nes praeitas ciklas to nepadaro
    if(validate_operators.size() >= 1)
    {
        if(validate_operators.back() == ((int)equation.size() - 1))
        {
            throw Incorrect_input(NO_OPERANDS);
        }
    }
}

void Validator::check_if_number_is_valid(string number)
{
    int dot_counter = 0;
    int dot_position;

    for(int i = 0; i < (int)number.size(); ++i)
    {
        if(number[i] == '.')
        {
            ++dot_counter;
            dot_position = i;
        }
    }

    if(dot_counter > 1 ||(dot_counter == 1 && (dot_position == 0 ||
        dot_position == (int)number.size() - 1)))
    {
        throw Incorrect_input(INVALID_NUMBER_FORMAT);
    }
}

void Validator::check_numbers_format()
{
    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(isdigit(equation[i]) != 0 || equation[i] == '.')
        {
            string temp;

            while(isdigit(equation[i]) != 0 || equation[i] == '.')
            {
                temp.push_back(equation[i]);
                ++i;
            }

            check_if_number_is_valid(temp);
        }
    }
}

void Validator::check_if_symbols_valid()
{
    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(isdigit(equation[i]) == 0)
        {
            if(equation[i] != '(' && equation[i] != ')' && equation[i] != '.')
            {
                check_if_is_operator(i);
            }
        }
    }
}

void Validator::check_if_brackets_valid()
{
    Get_information get_info;

    vector <pair<int, int>> brackets;

    get_info.get_brackets(brackets, equation);

    for(unsigned int i = 0; i < brackets.size(); ++i)
    {
        if(brackets[i].first > brackets[i].second ||
           brackets[i].first < 0 || brackets[i].second < 0)
        {
            throw Incorrect_input(BRACKETS_INVALID);
        }
        else if(brackets[i].second - brackets[i].first == 1)
        {
            throw Incorrect_input(BRACKETS_EMPTY);
        }
    }
}

void Validator::remove_spaces()
{
    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(isspace(equation[i]) != 0)
        {
            equation.erase(equation.begin() + i);
            --i;
        }
    }
}

void Validator::add_spaces()
{
    for(int i = validate_operators.size() - 1; i >= 0; --i)
    {
        // ideda tarpa is desines, jei operatorius binary ir nera skliausto
        if(equation[validate_operators[i] + 1] != ')' && validate_operators[i] != 0)
        {
            if(equation[validate_operators[i] - 1] != '(')
            {
                equation.insert(equation.begin() + validate_operators[i] + 1, ' ');
            }
        }

        // is kaires, jei nera skliausto
        if(validate_operators[i] >= 1 && equation[validate_operators[i] - 1] != '(')
        {
            equation.insert(equation.begin() + validate_operators[i], ' ');
        }
    }
}

void Validator::clear()
{
    validate_operators.clear();
}

string Validator::validate(string equation)
{
    this -> equation = equation;

    if(equation.empty() == true)
    {
        throw Incorrect_input(EMPTY);
    }

    remove_spaces();

    check_if_symbols_valid();
    check_if_brackets_valid();
    check_numbers_format();
    check_if_operators_have_operands();

    add_spaces();

    clear();
    return this -> equation;
}
