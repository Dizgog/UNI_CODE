#include <iostream>
#include <stdexcept>
#include "BaseEmployee.h"
using namespace std;

BaseEmployee::BaseEmployee(const std::string &name, double salary)
:name(name)
{
    setSalary(salary);
    cout << "Sukurtas Base darbuotojas " + name + ", kurio pajamos metams " << income() << endl;
}

BaseEmployee::~BaseEmployee()
{
    cout << "Sunaikintas Base darbuotojas " + name + ", kurio pajamos metams " << income() << endl;
}

void BaseEmployee::setName(const std::string &name)
{
    this -> name = name;
}

string BaseEmployee::getName () const
{
    return name;
}

void BaseEmployee::setSalary(const double salary)
{
    if ( salary >= 0.0 )
        this -> salary = salary;
    else
        throw invalid_argument( "Salary must be >= 0.0" );
}

double BaseEmployee::getSalary () const
{
    return salary;
}

double BaseEmployee::income () const
{
    return 12*salary;
}
