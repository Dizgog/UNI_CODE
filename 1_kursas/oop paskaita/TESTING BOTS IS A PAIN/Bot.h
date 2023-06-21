#ifndef CHATBOT_BOT_H
#define CHATBOT_BOT_H

#include "Behavior.h"

namespace bot {
    class Bot {
    private:
        class Implementation;

        Implementation *implementation;

        Bot(const Bot &);
    public:
        explicit Bot(Behavior *behavior, Interaction interaction);

        ~Bot();

        void onNewUserConnected(User &user);
    };
}

#endif //CHATBOT_BOT_H
