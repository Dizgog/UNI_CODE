#ifndef UTILITIES_H
#define UTILITIES_H

#include<string>
#include<ctime>
#include<algorithm>

#define string std::string
namespace BotSpace {
    class Utilities {
    public:
        Utilities();

        int random(int);

        static bool validateName(string);

        bool validateLetters(const string &) const;

    protected:
    };
}
#undef string
#endif