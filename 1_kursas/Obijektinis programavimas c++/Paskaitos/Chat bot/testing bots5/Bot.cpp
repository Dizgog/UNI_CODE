#include<iostream>
#include<sstream>
#include "Bot.h"
#include "Utilities.h"
#include "Phrases.h"
#include "PlayerPC.h"
#include "PlayerPerson.h"

namespace BotSpace {
    using namespace std;

    struct Bot::BotImpl {
    private:
        string name, companionName;
        Utilities utilities;
        Phrases phrases;
        const int rounds = 10;
        int id;
        static int count;

        friend class Bot;

        string chooseName() {
            int nameIndex = utilities.random(phrases.getNamesSize());
            return phrases.getName(nameIndex);
        }

        void introduceMessage() {
            int greetingIndex = utilities.random(phrases.getGreetingsSize());
            string greeting = phrases.getGreeting(greetingIndex);
            int beforeNameIndex = utilities.random(phrases.getBeforeNameSize());
            string beforeName = phrases.getBeforeName(beforeNameIndex);

            system("CLS");
            cout << greeting << endl;
            cout << beforeName << " ";
            cout << getName() << "." << endl;
            cout << phrases.getAskForName();
        }

        void setCompanionName() {
            string name, word;
            bool finishLoop;
            stringstream nameBuffer;
            do {
                getline(cin, name);
                nameBuffer = stringstream(name);
                nameBuffer >> word;
                finishLoop = utilities.validateName(name) && name == word;
                if (!finishLoop) {
                    cout << phrases.getIncorrectName();
                }
            } while (!finishLoop);
            companionName = name;
        }

        void setName(string name) {
            this->name = name;
        }

        void welcomeMessage() const {
            cout << phrases.getWelcome();
        }

        void playRound(PlayerPC &p1, PlayerPerson &p2) {
            cout << "It's " << p1.getName() << "'s turn!" << endl;
            cout << "   Letters:   ";
            p1.printLetters();
            int attempt = 1;
            bool accepted;
            do {
                cout << "Attempt " << attempt << ": ";
                string guess = p2.guessWord();
                cout << "Does " << p1.getName() << " accept? ";
                accepted = p1.accept(guess);
                if (!accepted) {
                    cout << "-";
                } else {
                    cout << "+";
                }
                cout << endl;
                attempt++;
            } while (!accepted && attempt < 4);
            int points;
            if (accepted) {
                points = 4 - attempt + 1;
                p1.addScore(points);
            } else {
                points = 0;
                cout << "That's a failure! The right answer is " << p1.getWord() << endl;
            }
            cout << p1.getName() << " gets " << points << " points!" << endl;

        }

        void playRound(PlayerPerson &p1, PlayerPC &p2) {
            cout << "It's " << p1.getName() << "'s turn!" << endl;
            cout << "   Letters:   ";
            p1.printLetters();
            if (p1.getShuffledWord() != "") {
                int attempt = 1;
                bool accepted;
                do {
                    cout << "Attempt " << attempt << ": ";
                    string guess = p2.guessWord(p1.getShuffledWord());
                    cout << guess << endl;
                    cout << "Does " << p1.getName() << " accept?";
                    accepted = p1.accept(guess);
                    attempt++;
                } while (attempt < 4 && !accepted);
                int points;
                if (accepted) {
                    points = 4 - attempt + 1;
                    p1.addScore(points);
                } else {
                    points = 0;
                    cout << "That's a failure! The right answer is ";
                    p1.getWord();
                }
                cout << p1.getName() << " gets " << points << " points!" << endl;
            }
        }

    public:
        string getName() const {
            return name;
        }

        string getCompanionName() {
            return companionName;
        }


        BotImpl() {
            id = count + 1;
            count++;
        }

        ~BotImpl() {
        }

        void printRules() {
            cout << "Welcome to the game!" << endl;
            cout << "The game is called 'Word Puzzle'" << endl;
            cout << "Let me briefly introduce you the rules:" << endl;
            cout << "- Each player gives a bunch of letters for opponent." << endl;
            cout << "- The aim is to construct a meaningful word." << endl;
            cout << "- Players can guess at most 3 times." << endl;
            cout << "- At the first correct attempt, player gets 3, at the second - 2, at the third - 1 or 0 points."
                 << endl;
            cout << "- After each attempt player accepts or rejects word by '+' (yes) or '-' (no) respectively."
                 << endl;
            cout << "- If the right word is not found,  the correct answer finally should be provided." << endl;
            cout
                    << "- If the provided answer is wrong (different number of letters/different letters), player loses 1 point."
                    << endl;
            cout << "- Word should consist of at least 3 letters, otherwise player loses 1 point." << endl;
            cout << "- There are 10 rounds for 2 words (for each player to guess)." << endl;
            cout << "- Player, who collects the most points, is a winner." << endl;
            cout << "In case of an equal number of points, draw is announced." << endl;
            cout << "- Only latin small letters are to be used in word construction, otherwise player loses 1 point."
                 << endl
                 << "  Replace any special symbols with equivalent latin ones." << endl << endl;
            cout << "And that's all! Any questions? No? Lets start!" << endl << endl;
        }

        void playGame() {
            PlayerPC player1(getName());
            PlayerPerson player2(getCompanionName());
            cout << "       Players: " << player1.getName() << " and " << player2.getName() << "! Good luck!" << endl
                 << endl;

            for (int i = 0; i < rounds; ++i) {
                cout << "                ROUND " << i + 1 << endl;
                playRound(player1, player2);
                playRound(player2, player1);
                cout << player1.getName() << ": " << player1.getScore() << ", " << player2.getName() << ": "
                     << player2.getScore() << "." << endl;

            }
            cout << endl << endl << "Game is over! ";
            if (player1.getScore() == player2.getScore()) {
                cout << "It's a tie";
            } else {
                cout << "The winner is ";
                if (player1.getScore() > player2.getScore()) {
                    cout << player1.getName();
                } else {
                    cout << player2.getName();
                }
            }
            cout << "! Congratulations!" << endl << "Press enter to continue   ";
            string answer;
            getline(cin, answer);
        }

    protected:

    };

    int Bot::BotImpl::count = 0;

    Bot::Bot() {
        bot = new Bot::BotImpl;
        string name = bot->chooseName();
        bot->setName(name);
    }

    Bot::~Bot() {
        delete bot;
    }

    Bot &Bot::operator=(const Bot &other) {
        if (this == &other) {
            return *this;
        }
        delete bot;
        bot = new BotImpl(*(other.bot));
        return *this;
    }

    Bot::Bot(const Bot &other) {
        bot = new BotImpl(*(other.bot));
    }

    void Bot::sayHi() {
        bot->introduceMessage();
        bot->setCompanionName();
        bot->welcomeMessage();
    }

    void Bot::startSession() {
        bot->printRules();
        bot->playGame();
    }

    string Bot::getCompanionName() const {
        return bot->getCompanionName();
    }

    string Bot::getName() const {
        return bot->getName();
    }

}