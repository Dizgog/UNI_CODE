#ifndef BOT_H
#define BOT_H

#include<string>

#define string std::string
namespace BotSpace {
    class Bot {
        struct BotImpl;
    public:
        Bot();

        string getName() const;

        string getCompanionName() const;

        void sayHi();

        void startSession();

        ~Bot();

        Bot &operator=(const Bot &other);

    private:
        BotImpl *bot;

        Bot(const Bot &other);

    protected:
    };
}
#undef string
#endif //BOT_H
