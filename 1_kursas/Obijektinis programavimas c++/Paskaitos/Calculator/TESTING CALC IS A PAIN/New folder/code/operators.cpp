#include "classes_logic.h"
#include <sstream>


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: igyvendinti klases, kurios dirba su operatoriais*/


void Operator::set_symbol(char symbol)
{
    this -> symbol = symbol;
}

char Operator::get_symbol() const
{
    return symbol;
}

void Operator::set_priority(int priority)
{
    this -> priority = priority;
}

int Operator::get_priority() const
{
    return priority;
}

Type Operator::get_type() const
{
    return type;
}

void Operator::set_type(Type type)
{
    this -> type = type;
}

void Operator::set_position(int position)
{
    this -> position = position;
}

int Operator::get_position() const
{
    return position;
}


Unary_operator::Unary_operator()
{

}

Unary_operator::Unary_operator(char symbol, int priority, function<double(double)> operation)
{
    set_symbol(symbol);
    set_priority(priority);

    this -> operation = operation;
}

double Unary_operator::do_operation(double num1) const
{
    return operation(num1);
}


Binary_operator::Binary_operator()
{

}

Binary_operator::Binary_operator(char symbol, int priority, function<double(double, double)> operation)
{
    set_symbol(symbol);
    set_priority(priority);

    this -> operation = operation;
}

double Binary_operator::do_operation(double num1, double num2) const
{
    return operation(num1, num2);
}


void Available_operators::add_operator(char symbol, int priority, function<double(double, double)> operation)
{
    binary_operators.emplace(symbol, Binary_operator(symbol, priority, operation));
}

void Available_operators::add_operator(char symbol, int priority, function<double(double)> operation)
{
    unary_operators.emplace(symbol, Unary_operator(symbol, priority, operation));
}

double Available_operators::do_operation(double num1, double num2, char operator_symbol) const
{
    return binary_operators.at(operator_symbol).do_operation(num1, num2);
}

double Available_operators::do_operation(double num, char operator_symbol) const
{
    return unary_operators.at(operator_symbol).do_operation(num);
}

int Available_operators::get_priority(char symbol, Type type) const
{
    if(type == UNARY)
    {
        return unary_operators.at(symbol).get_priority();
    }
    else if(type == BINARY)
    {
        return binary_operators.at(symbol).get_priority();
    }

    return -1;
}

vector <Operator> Available_operators::get_operators() const
{
    vector <Operator> operators;

    for(auto i = unary_operators.begin(); i != unary_operators.end(); ++i)
    {
        operators.push_back(i -> second);
    }

    for(auto i = binary_operators.begin(); i != binary_operators.end(); ++i)
    {
        operators.push_back(i -> second);
    }

    return operators;
}

string Available_operators::show_operators() const
{
    string operators = "Available operators:\n";

    for(auto i = unary_operators.begin(); i != unary_operators.end(); ++i)
    {
        operators += i -> second.get_symbol();
        operators += "(unary)\n";
    }

    for(auto i = binary_operators.begin(); i != binary_operators.end(); ++i)
    {
        operators += i -> second.get_symbol();
        operators += "\n";
    }

    return operators;
}
