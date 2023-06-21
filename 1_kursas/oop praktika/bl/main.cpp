#include <stdio.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "BaseEmployee.h"
#include "BasePlusEmployee.h"

using namespace std;

int main()
{
    BasePlusEmployee::setSalesBonus(100);

    cout << "Sukuriame base darbuotoja:\n";
    BaseEmployee worker1("Tomas", 1000.0);
    cout << "\nSukuriame base+ darbuotoja:\n";
    BasePlusEmployee worker2("Jonas", 300.0, 100);

    cout << "\nNaikiname darbuotojus:\n";

}

