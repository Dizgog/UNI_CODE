#ifndef BASEPLUSEMPLOYEE_H
#define BASEPLUSEMPLOYEE_H

#include <string>
#include "BaseEmployee.h"

class BasePlusEmployee : public BaseEmployee
{
    public:
        BasePlusEmployee(const std::string & = "Nenurodyta", double = 0.0, int = 0);
        virtual ~BasePlusEmployee();

        //setteriai ir getteriai
        void setNumberOfSales(const int);
        int getNumberOfSales () const;
        static void setSalesBonus (const double);
        static double getSalesBonus ();

        double income () const;
    protected:
    private:
        static double salesBonus;
        int numberOfSales;
};

#endif // BASEPLUSEMPLOYEE_H
