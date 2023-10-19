#include "Bot.h"
#include <time.h>
#include <sstream>

/***********************************************/
/*                                             */
/*                                             */
/*       Author: Matas Bruson Info 2gr.        */
/*                                             */
/*   Occupation: VU Computer Science student   */
/*                                             */
/*            Last edit: 2022-03-22            */
/*                                             */
/*  Program:                                   */
/*  This is a chat bot                         */
/*  which talks about some topics              */
/*                                             */
/*                                             */
/***********************************************/

using namespace Bot;

using namespace std;

int main()
{
    srand(time(NULL));

    vector<string> hellos{"Hello, what's your name?", "Buongiornoooo, what's your name?",
                          "Good morning my friend, what's your name?", "Hello Mister X, what's your X?",
                          "Hi, what's your name?" };
    vector<string> emotions{"That does not seem like a name, could you input a valid name?",
                            "For the second time, please insert your correct name", "Ah shit... Here we go again... insert yout name",
                            "Could you please FOR THE LAST TIME insert your name? Or not???", "STFU and go to school... Turn me on again, when you'll be able to write your own name..."};

    int number = (rand() % 5) + 1;

    cout << hellos[number - 1] << endl;

    string names;
    int count = 0;
    while (1) //Credits to Edvinas Čelkis, name checker
    {
        stringstream ss;
        getline(cin, names);
        ss << names;

        char trig = 0;
        while (!ss.eof())
        {
            string name;
            ss >> name;
            trig = !isupper(name[0]);
            for (size_t i = 1; i < name.length(); ++i)
            {
                if (trig || !islower(name[i]))
                {
                    trig = 1;
                    break;
                }
            }
            if (trig == 1)
                break;
        }
        if (trig == 0)
            break;

        ++count;
        system("cls");
        if (count == 4)
        {
            cout << emotions[count] << endl;
            exit(0);
        }
        else
        {
            cout << emotions[count] << endl;
        }
    }

    int choice;

    system("cls");
    cout << "Hello, " << names << " choose about what you want to talk about!" << endl;

    while (1) //Main menu cicle
    {
        try
        {
            cout << "1. Basketball" << endl << "2. Football" << endl << "3. Music" << endl << "4. Books" << endl << "5. Cuisine" << endl << "0. Exit" << endl << "(Look out! If you write anything except numbers you're going to quit our chat!)" << endl;
            cin >> choice;
            system("cls");

            MyBot bot(choice, names); //Bot

            cout << "Hello, again " << names << "! Choose about what you want to talk about!" << endl;
        }
        catch (invalid_argument &error)
        {
            cerr << "Error inserting input: " << error.what() << endl;
            cout << "Hello, again " << names << "! Choose about what you want to talk about!" << endl;
        }
    }

    return 0;
}
