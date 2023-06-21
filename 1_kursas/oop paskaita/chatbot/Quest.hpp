#ifndef QUEST_HPP
#define QUEST_HPP

#define DEFAULT_MONEE 1000
#define DRINK_PRICE 5
#define VALUTE " Ukrainian hryvnia"

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

namespace Quest
{
    class Quest{
    private:
        std::string description;
        int requirement;
        int counter;
        int reward;
        int punishment;
        time_t end;
        void generator();
        int type;
    public:
        int getType() const;
        static std::vector<std::string>questList;
        Quest(bool a=0);
        std::string getDesc() const;
        int isComplete();
        Quest& operator++();
        Quest operator++(int);
    };
}
#endif // QUEST_HPP
