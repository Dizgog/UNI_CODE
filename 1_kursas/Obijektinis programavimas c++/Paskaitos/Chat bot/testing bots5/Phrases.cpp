#include "Phrases.h"

namespace BotSpace {
    using namespace std;

    Phrases::Phrases() {
        names = {"John", "Dayen", "ComputerMinator", "StupidBot", "Uncle RURU", "Slavista"};
        greetings = {"Hi there!", "HELLOOOOO.", "Hello, my dearest!", "Good afternoon...", "Good day!",
                     "Helo again :)"};
        beforeName = {"I'm", "I am", "People call me", "My name is", "Lets introduce each other. I am"};
        askForName = "Can I ask what's yours?   ";
        incorrectName = "Note: Name consists of 1 word, first Letter is in uppercase, others are lowercase. Please repeat.\n";
        welcome = "Nice to meet you!\n";
    }

    int Phrases::getNamesSize() const {
        return names.size();
    }

    int Phrases::getGreetingsSize() const {
        return greetings.size();
    }

    string Phrases::getName(int index) const {
        if (index < 0 || index >= getNamesSize()) {
            throw invalid_argument("Name doesn't exist.");
        }
        return names[index];
    }

    string Phrases::getGreeting(int index) const {
        if (index < 0 || index >= getGreetingsSize()) {
            throw invalid_argument("Greeting doesn't exist.");
        }
        return greetings[index];
    }

    int Phrases::getBeforeNameSize() const {
        return beforeName.size();
    }

    string Phrases::getBeforeName(int index) const {
        if (index < 0 || index >= getBeforeNameSize()) {
            throw invalid_argument("BeforeName doesn't exist.");
        }
        return beforeName[index];
    }

    string Phrases::getAskForName() const {
        return askForName;
    }

    string Phrases::getIncorrectName() const {
        return incorrectName;
    }

    string Phrases::getWelcome() const {
        return welcome;
    }
}
