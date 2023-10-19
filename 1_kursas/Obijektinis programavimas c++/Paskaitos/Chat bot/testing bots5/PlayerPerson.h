#ifndef PLAYERPERSON_H
#define PLAYERPERSON_H

#include<iostream>
#include<string>
#include "Utilities.h"
#include<algorithm>

#define string std::string
namespace BotSpace {
    class PlayerPerson {
    private:
        string name, shuffledWord;
        int score;
        Utilities utilities;
    public:
        PlayerPerson(string);

        string getName() const;

        int getScore() const;

        ~PlayerPerson();

        void printLetters();

        void addScore(int);

        string guessWord();

        bool accept(string);

        void getWord();

        string getShuffledWord() const;

    protected:
    };
}
#undef string
#endif // PLAYERPERSON_H