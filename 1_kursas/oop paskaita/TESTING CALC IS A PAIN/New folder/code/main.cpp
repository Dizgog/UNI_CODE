#include <iostream>
#include "classes_logic.h"


/* Autorius: Eigirdas Stancius, Informatika 1 grupe, 1 kursas
 * Failo paskirtis: sukurti prastintoja/skaiciuotuva, kuris dirba su stdin/sdout */


using namespace std;


int main()
{
    Available_operators available;

    available.add_operator('-', 1, NEGATION);
    available.add_operator('+', 3, SUM);
    available.add_operator('-', 3, SUBTRACTION);
    available.add_operator('*', 2, MULTIPLICATION);
    available.add_operator('/', 2, DIVISION);
    available.add_operator('%', 2, MODULO);

    Calculator calculator(available);

    cout << calculator.show_available_operators() << endl;

    cout << "(To exit type \"exit\")" << endl;

    while(1)
    {
        cout << "\nType equation you want to simplify" << endl;

        string text;
        getline(cin, text);

        if(text == "exit")
        {
            return 0;
        }


        try
        {
            cout  << calculator.simplify(text) << endl;
        }
        catch(const Incorrect_input & incorrect)
        {
            calculator.clear_when_error();
            cout << "\nERROR!" << incorrect.get_error_message() << endl;;
        }
        catch(const out_of_range & incorrect)
        {
            /* yra operatoriu, kurie turi ta pati simboli, bet yra skirtingi -
            vienas unary, kitas binary; gali buti situaciju, kai egzistuoja
            tik vienas is tokiu operatoriu; STL map tokiu atveju, kai bandoma kreiptis
            ne i ta operatoriu, meta out_of_range exception'a */

            calculator.clear_when_error();
            cout << "Invalid operator" << endl;
        }
        catch(...)
        {
            cout << "Unexpected error" << endl;
            exit(0);
        }
    }
}
