#ifndef BASEEMPLOYEE_H
#define BASEEMPLOYEE_H
#include <string>

class BaseEmployee
{
    public:
        BaseEmployee(const std::string & = "Nenurodyta", double = 0.0);
        virtual ~BaseEmployee();

        //setteriai ir getteriai
        void setName(const std::string &);
        std::string getName () const;
        void setSalary(const double);
        double getSalary () const;

        double income () const;

    protected:
        //double salary;  //jei salary protected, vaikineje klaseje galime pasiekti tiesiogiai
    private:
        std::string name;
        double salary;
};

#endif // BASEEMPLOYEE_H
