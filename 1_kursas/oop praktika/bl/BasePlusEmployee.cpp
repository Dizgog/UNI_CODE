#include <iostream>
#include <stdexcept>
#include "BasePlusEmployee.h"
using namespace std;

double BasePlusEmployee::salesBonus = 0;

BasePlusEmployee::BasePlusEmployee(const std::string &name, double salary, int numberOfSales)
:BaseEmployee(name, salary)  //geriausias budas priskirti reiksmes tevineje klaseje
{
    //setName(name);   //galima ir taip, bet tevines klases objektas vis tiek sukuriamas
    //setSalary(salary);
    setNumberOfSales(numberOfSales);
    cout << "Sukurtas Base+ darbuotojas " + name + ", kurio pajamos metams " << income() << endl;
}

BasePlusEmployee::~BasePlusEmployee()
{
    cout << "Sunaikintas Base+ darbuotojas " + getName() + ", kurio pajamos metams " << income() << endl;
}

void BasePlusEmployee::setNumberOfSales(const int number)
{
    if ( number >= 0.0 )
        this -> numberOfSales = number;
    else
        throw invalid_argument( "Number of sales must be >= 0.0" );
}

int BasePlusEmployee::getNumberOfSales () const
{
    return numberOfSales;
}

void BasePlusEmployee::setSalesBonus(const double bonus)
{
    if ( bonus >= 0.0 )
        salesBonus = bonus;
    else
        throw invalid_argument( "Sales bonus must be >= 0.0" );
}

double BasePlusEmployee::getSalesBonus ()
{
    return salesBonus;
}


double BasePlusEmployee::income () const
{
    return BaseEmployee::income() + numberOfSales * salesBonus;
    //return 12*getSalary() + numberOfSales * salesBonus;  //metodas pilnai perrasytas, bet yra kodo pakartojimas
    //return 12*salary + numberOfSales * salesBonus;  //Veiks, jei salary yra protected
}
