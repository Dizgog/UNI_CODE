#ifndef CLASSES_LOGIC_H_INCLUDED
#define CLASSES_LOGIC_H_INCLUDED


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: ideti visu klasiu aprasus, visas konstantas*/


#include <functional>
#include <map>
#include <vector>
#include <cmath>
#include <string>


#define NEGATION negate<double>()

#define SUM plus<double>()
#define SUBTRACTION minus<double>()
#define MULTIPLICATION multiplies<double>()
#define DIVISION Divides<double>()
#define MODULO Modulo<double>()


using namespace std;


enum Type{UNARY, BINARY};


class Operator
{
    private:
        char symbol;
        int priority;
        Type type;
        int position;

    public:
        void set_symbol(char symbol);
        char get_symbol() const;


        void set_priority(int priority);
        int get_priority() const;


        Type get_type() const;
        void set_type(Type type);


        void set_position(int position);
        int get_position() const;
};


class Unary_operator : public Operator
{
    private:
        function<double(double)> operation;
        Type type = UNARY;

    public:
        Unary_operator();
        Unary_operator(char symbol, int priority, function<double(double)> operation);

        double do_operation(double num1) const;
};


class Binary_operator : public Operator
{
    private:
        function<double(double, double)> operation;
        Type type = BINARY;

    public:
        Binary_operator();
        Binary_operator(char symbol, int priority, function<double(double, double)> operation);

        double do_operation(double num1, double num2) const;
};


class Available_operators
{
    private:
        map <char, Unary_operator> unary_operators;
        map <char, Binary_operator> binary_operators;

    public:
        void add_operator(char symbol, int priority, function<double(double, double)> operation);
        void add_operator(char symbol, int priority, function<double(double)> operation);

        double do_operation(double num1, double num2, char operator_symbol) const;
        double do_operation(double num, char operator_symbol) const;

        int get_priority(char symbol, Type type) const;

        vector <Operator> get_operators() const;
        string show_operators() const;
};


// is tekstines eilutes gauna operatorius, skliaustus
class Get_information
{
    private:
        void save_operator(int index, vector <Operator> & operators, const Available_operators & available, string equation);

        // (ziureti apacioje klase One_equation) pasalina operatorius, kurie nera vieno reiskinio dalis
        void remove_operators_in_brackets(vector <Operator> & operators, vector <pair<int, int>> & brackets);


        void save_brackets(int index, vector <pair<int, int>> & brackets, string equation);

        // pasalina, jei yra pvz. tokia situacija: (5 + 3 + 4) - skliaustai nieko nekeicia
        void remove_unnecessary_brackets(vector <pair<int, int>> & brackets, vector <Operator> & operators, string & equation);

    public:
        void get_operators(vector <Operator> & operators, string equation, const Available_operators & manager);

        void get_brackets(vector <pair<int, int>> & brackets, string equation);

        void get_information(vector <Operator> & operators,
             vector <pair<int, int>> & brackets, const Available_operators & available, string & equation);
};


// is tekstines eilutes gauna operandus
class Get_operands
{
    private:

        // vienas is operandu gali buti skliaustuose esantis reiskinys, todel sitoje klaseje yra sis metodas
        int find_other_bracket(int one_position, vector <pair<int, int>> brackets);

        string get_operand_in_brackets(string equation, int start, int end);


        double find_left_if_brackets(int bracket_index, vector <pair<int, int>> & brackets,
                string equation, const Available_operators & available);

        double find_right_if_brackets(int bracket_index, vector <pair<int, int>> & brackets,
                string equation, const Available_operators & available);

    public:
        double convert_to_double(string operand_string);

        double find_left(int operator_index, vector <pair<int, int>> & brackets,
                          string equation, const Available_operators & available);

        double find_right(int operator_index, vector <pair<int, int>> & brackets,
                           string equation, const Available_operators & available);
};


/*  vienu reiskiniu laikomas reiskinys, kuriame nera skliaustu, pvz: 5 + 3, o
    5 * (3 + 8) nera vienas reiskinys, todel bus sukurtas daugiau nei vienas One_equation
    klases objektas, norint apskaiciuoti visa sita eilute */
class One_equation
{
    private:
        const Available_operators available;
        string equation;

        vector <Operator> operators;
        vector <pair<int, int>> brackets;

    public:
        One_equation(string equation, const Available_operators & available);

        // pirma atlieka operacijas, kuriu prioritetas didesnis(priority skaicius mazesnis)
        double do_priority_operations(int operator_index);

        double calculate();
};


// klase naudojama exception'u gaudymams
class Incorrect_input
{
    private:
        string error_message;

    public:
        Incorrect_input(string error_message);

        string get_error_message() const;
};


class Validator
{
    private:
        string equation;
        const vector <Operator> available_operators;

        // operatoriu pozicijos
        vector <int> validate_operators;

    public:
        Validator(const vector <Operator> & available_operators);

    private:
        // tik pvz: "5.54" arba "5" yra geri skaiciu formatai
        void check_if_number_is_valid(string number);
        void check_numbers_format();


        void check_if_symbols_valid();
        void check_if_is_operator(int position);

        void check_if_operators_have_operands();

        // visi skliaustai uzsidaro ir atsidaro, nera tusti
        void check_if_brackets_valid();

        void remove_spaces();
        void add_spaces();

    public:
        void clear();

        string validate(string equation);
};


class Calculator
{
    private:
        const Available_operators available;
        Validator validator;

    public:
        Calculator(const Available_operators & available);

        string show_available_operators();

        void clear_when_error();

        double simplify(string equation);
};


// is bibliotekos "functional" klase divides netikrina dalybos is 0
template <typename T>
class Divides
{
    public:
        T operator() (const T& x, const T& y) const
        {
            if(y == 0)
            {
                throw Incorrect_input("\nDivision by zero");
            }

            return x / y;
        }
};


// is bibliotekos "functional" klase modulus veikia tik su sveikaisiais skaiciais
template <typename T>
class Modulo
{
    public:
        T operator() (const T& x, const T& y) const
        {
            if(y == 0)
            {
                throw Incorrect_input("\nDivision by zero");
            }

            return fmod(x, y) + 0.0;
        }
};


#endif // CLASSES_LOGIC_H_INCLUDED
