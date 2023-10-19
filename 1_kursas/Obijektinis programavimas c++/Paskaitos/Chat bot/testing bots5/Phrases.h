#ifndef PHRASES_H

#include<string>
#include<vector>
#include<stdexcept>

#define PHRASES_H
#define string std::string
namespace BotSpace {
    class Phrases {
    private:
        std::vector <string> names;
        std::vector <string> greetings;
        std::vector <string> beforeName;
        string askForName, incorrectName, welcome;

    public:
        Phrases();

        int getNamesSize() const;

        int getGreetingsSize() const;

        string getName(int) const;

        string getGreeting(int) const;

        int getBeforeNameSize() const;

        string getBeforeName(int) const;

        string getAskForName() const;

        string getIncorrectName() const;

        string getWelcome() const;

    protected:
    };
}
#undef string
#endif //PHRASES_H