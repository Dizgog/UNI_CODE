#ifndef BOT_H
#define BOT_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define string std::string

namespace Bot
{
    class MyBot
    {
            class MyBotImplementation;
            MyBotImplementation *impl;
        public:
            MyBot(const int &, const string &);
            virtual ~MyBot();
            int getAlive() const;
            int getChoice() const;
            void setChoice(const int &);
            string getName() const;
            void setName(const string &);
        protected:
    };
}

#endif // BOT_H
