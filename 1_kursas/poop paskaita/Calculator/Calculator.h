#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>

class Calc {
protected:
double first,second;
char operat;
public:

void setFirst(double first);
void setSecond(double second);
void setOperator(char operat);

double getFirst();
double getSecond();
char getOperator();
double getAnswer(double first, char operat, double second);

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
double rem(double, double);
};

#endif