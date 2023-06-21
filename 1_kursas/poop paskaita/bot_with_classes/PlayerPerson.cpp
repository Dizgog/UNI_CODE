#include "PlayerPerson.h"

namespace BotSpace {
    using namespace std;

    PlayerPerson::PlayerPerson(string name) {
        this->name = name;
        score = 0;
    }

    string PlayerPerson::getName() const {
        return name;
    }

    PlayerPerson::~PlayerPerson() {
    }

    int PlayerPerson::getScore() const {
        return score;
    }

    void PlayerPerson::printLetters() {
        string letters;
        getline(cin, letters);
        if (!utilities.validateLetters(letters)) {
            score--;
            cout << "Invalid letter combination, -1 point." << endl;
            shuffledWord = "";
        } else {
            shuffledWord = letters;
        }
    }

    void PlayerPerson::addScore(int score) {
        this->score += score;
    }

    string PlayerPerson::guessWord() {
        string guess;
        getline(cin, guess);
        return guess;
    }

    bool PlayerPerson::accept(string newWord) {
        string conformation;
        do {
            getline(cin, conformation);
            if (conformation != "+" && conformation != "-") {
                cout << "Type only + or -.   ";
            }
        } while (conformation != "+" && conformation != "-");
        if (conformation == "+") {
            return true;
        }
        return false;
    }

    void PlayerPerson::getWord() {
        string answer;
        getline(cin, answer);
        sort(shuffledWord.begin(), shuffledWord.end());
        while (shuffledWord != answer && next_permutation(shuffledWord.begin(), shuffledWord.end()));
        if (shuffledWord != answer) {
            score--;
            cout << "Answer is not valid, -1 point." << endl;
        }
    }

    string PlayerPerson::getShuffledWord() const {
        return shuffledWord;
    }
}

