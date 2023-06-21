#include "Bot.h"

namespace Bot
{
    using namespace std;

    class MyBot::MyBotImplementation //All private members
    {
        friend class MyBot;
        private:
            int choice;
            static int countAlive;
            string name;
            static vector <string> basketQ;
            static vector <string> basketA;
            static vector <string> basketQ2;
            static vector <string> footballQ;
            static vector <string> footballA;
            static vector <string> footballQ2;
            static vector <string> musicQ;
            static vector <string> musicA;
            static vector <string> musicQ2;
            static vector <string> booksQ;
            static vector <string> booksA;
            static vector <string> booksQ2;
            static vector <string> reaction;
            static vector <string> cuisineQ;
            static vector <string> cuisineA;
            static vector <string> cuisineQ2;
            void questioning()const;
            void basket() const;
            void football() const;
            void music() const;
            void books() const;
            void cuisine() const;
            void chat(const vector <string> &, const vector <string> &, const vector <string> &, const vector <string> &) const;
    };

    int MyBot::MyBotImplementation::countAlive = 0;

    vector<string> MyBot::MyBotImplementation::basketQ{"To begin with, what is your favourite basketball team?",
        "What is your favourite player?", "Who is the G.O.A.T?",
        "I would love to know your top 5 player of all time!", "Attack or defense?"};
    vector<string> MyBot::MyBotImplementation::basketA{"My favorite is Los Angeles Lakers!",
        "LeGoat James, ofc!", "Kobe Bean Bryant aka Mamba",
        "My top 5 is : LeBron, Shaq, Curry, Jordan and Kobe", "The most important think is teamwork!"};
    vector<string> MyBot::MyBotImplementation::basketQ2{"Do you want to know my favourite team?",
        "Do you want to know my favourite player?", "Do you want to who is the G.O.A.T?",
        "Do you want to know my top 5?", "Do you want to know my opinion about it?"};

    vector<string> MyBot::MyBotImplementation::footballQ{"What is your favourite football team?",
        "What is your favourite player?", "Who is the G.O.A.T?",
        "I would love to know your top 11 player of all time!", "Attack or defense?"};
    vector<string> MyBot::MyBotImplementation::footballA{"My favorite is FC Barcelona!",
        "Cristiano Ronaldo, SIUUUUUUUUM!", "I believe, Diego Armando Maradona",
        "My top 11 is : CR7, Roberto Carlos, Pele, Maradona, Ronaldinho, Messi, Buffon, Ramos, Chiellini, De Bruyne and Ronaldo Nazario",
        "The most important think is teamwork!"};
    vector<string> MyBot::MyBotImplementation::footballQ2{"Do you want to know my favourite team?",
        "Do you want to know my favourite player?", "Do you want to who is the G.O.A.T?",
        "Do you want to know my top 11?", "Do you want to know my opinion about it?"};

    vector<string> MyBot::MyBotImplementation::musicQ{"What is your favourite song?",
        "Who is your favourite singer?", "Who is the best band?",
        "I would love to know your top 3 singers/bands of all time!", "Would you like to be a songwriter?"};
    vector<string> MyBot::MyBotImplementation::musicA{"Bohemian Rhapsody by Queen",
        "My favourite singer is Dzordana Butkute", "Of course my beloved Queen!",
        "My top 3 is : Lewis Armstrong, GunsNRoses, Freddie Mercury",
        "No, but my dream is to sing like Freddie Mercury!"};
    vector<string> MyBot::MyBotImplementation::musicQ2{"Do you want to know my favourite song?",
        "Do you want to know my favourite singer?", "Do you want to know my favourite band?",
        "Do you want to know my top 3?", "Do you want to know my opinion about it?"};

    vector<string> MyBot::MyBotImplementation::booksQ{"What is your favourite book?", "Who is your favourite writer?",
        "I would love to know your top 3 writers of all time!", "Would you like to be a writer?"};
    vector<string> MyBot::MyBotImplementation::booksA{ "My favourite book is Miskais Ateina Ruduo (Marius Katiliskis)", "Vincas Mykolaitis-Putinas, P.S. Not Vladimir Putin!...",
        "My top 3 is : Antanas Skema, Alessandro Manzoni ir Jurgis Kuncinas",
        "Absolutely yes, being like Oscar Wilde is something special!"};
    vector<string> MyBot::MyBotImplementation::booksQ2{"Do you want to know my favourite book?",
        "Do you want to know my favourite writer?", "Do you want to know my top 3?", "Do you want to know my opinion about it?"};

    vector<string> MyBot::MyBotImplementation::cuisineQ{"What is your favourite food?", "Who is your favourite cooker?",
        "What is the best tool in the kitchen?"};
    vector<string> MyBot::MyBotImplementation::cuisineA{ "My favourite food is lasagna", "My favourite Antonino Cannavaciuolo",
        "I love fork ;))), check https://www.youtube.com/watch?v=HDR_pZCxKh8"};
    vector<string> MyBot::MyBotImplementation::cuisineQ2{"Do you want to know my favourite book?",
        "Do you want to know my favourite cooker?", "Do you want to know my favourite tool?"};

    vector<string> MyBot::MyBotImplementation::reaction{ "Oh, I see!", "Marvelous...", "Amazing!", "That's wonderful!", "That's great!"};

    MyBot::MyBot(const int & choice, const string & name)
    {
        impl = new MyBotImplementation();
        setName(name);
        setChoice(choice);
        impl -> questioning();
        ++MyBotImplementation::countAlive;
    }

    MyBot::~MyBot()
    {
        --MyBotImplementation::countAlive;
        delete impl;
    }

    int MyBot::getAlive() const
    {
        return MyBotImplementation::countAlive;
    }

    int MyBot::getChoice() const
    {
        return impl -> choice;
    }

    void MyBot::setChoice(const int & choice)
    {
        impl -> choice = choice;
    }

    string MyBot::getName() const
    {
        return impl -> name;
    }

    void MyBot::setName(const string & name)
    {
        impl -> name = name;
    }

    void MyBot::MyBotImplementation::questioning() const
    {
        switch (this -> choice)
        {
            case 1:
                basket();
                break;
            case 2:
                football();
                break;
            case 3:
                music();
                break;
            case 4:
                books();
                break;
            case 5:
                cuisine();
                break;
            case 0:
                cout << "It was nice to meet you, " + name + ", have a nice day!" << endl;
                exit(0);
                break;
            default:
                throw invalid_argument("Your input is invalid");
                break;
        }
    }

    void MyBot::MyBotImplementation::basket() const
    {
        chat(basketA, basketQ, basketQ2, reaction);
    }

    void MyBot::MyBotImplementation::football() const
    {
        chat(footballA, footballQ, footballQ2, reaction);
    }

    void MyBot::MyBotImplementation::music() const
    {
        chat(musicA, musicQ, musicQ2, reaction);
    }

    void MyBot::MyBotImplementation::books() const
    {
        chat(booksA, booksQ, booksQ2, reaction);
    }

    void MyBot::MyBotImplementation::cuisine() const
    {
        chat(cuisineA, cuisineQ, cuisineQ2, reaction);
    }

    void MyBot::MyBotImplementation::chat(const vector <string> &subjectA, const vector <string> &subjectQ, const vector <string> &subjectQ2, const vector <string> &reaction) const
    {
        int shuffle[subjectQ.size()] = {0, 1, 2, 3, 4}; //5 questions
        random_shuffle(shuffle, shuffle + subjectQ.size()); //randomize the index

        bool found = false;
        for (int i = 0; i < subjectQ.size() && !found; ++i) //For cicle for asking questions
        {
            string str;
            cout << subjectQ[ shuffle[i] ] << endl;
            cin >> str;
            system("cls");
            while(1)
            {
                try
                {
                    string in;
                    cout << reaction[i] << " " << subjectQ2[ shuffle[i] ] << " Type Y or N or press 0, to get out"  << endl;
                    cin >> in;
                    if (in.size() == 1 && (in == "Y" || in == "y")) //Type Y to get an answer
                    {
                        cout << subjectA[ shuffle[i] ] << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else if (in.size() == 1 && (in == "N" || in == "n")) //Type N to go to another question
                    {
                        cout << "OK, let's go to another question!" << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    else if (in.size() == 1 && in == "0")
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        throw invalid_argument("Your input is invalid");
                        break;
                    }
                }
                catch (invalid_argument &error)
                {
                    cerr << "Error inserting input: " << error.what() << endl;
                }
            }
            if (found == true)
            {
                break;
            }
        }
        system("cls");
    }
}
