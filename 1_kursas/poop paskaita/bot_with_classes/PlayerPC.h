#ifndef PLAYERPC_H
#define PLAYERPC_H

#include<vector>
#include<iostream>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include<string>
#include "Utilities.h"

#define string std::string
namespace BotSpace {
    class PlayerPC {
    private:
        std::vector <string> words;
        int score;
        string name, word;
        Utilities utilities;
    public:
        PlayerPC(string);

        string getName() const;

        int getScore() const;

        void printLetters();

        ~PlayerPC();

        void addScore(int);

        string getWord();

        string guessWord(string);

        bool accept(string);

    protected:
    };
}
#undef string
#endif // PLAYERPC_H