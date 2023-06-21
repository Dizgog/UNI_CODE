#include "Bot.h"

#include <stdexcept>

namespace bot {
    class Bot::Implementation {
    private:
        Behavior *behavior;
        Interaction interaction;

        Implementation(const Implementation &);
    public:
        explicit Implementation(Behavior *behavior, Interaction interaction);

        ~Implementation();

        void handleUser(User &user);
    };

    Bot::Implementation::Implementation(Behavior *behavior, Interaction interaction) :
            behavior(behavior), interaction(interaction) {
    }

    void Bot::Implementation::handleUser(User &user) {
        behavior->run(user, interaction);
    }

    Bot::Implementation::~Implementation() {
        delete behavior;
    }

    Bot::Implementation::Implementation(const Implementation &other): interaction(other.interaction) {
        throw std::logic_error("Bot::Implementation is non-copiable object.");
    }

    Bot::Bot(Behavior *behavior, Interaction interaction) :
            implementation(new Implementation(behavior, interaction)) {
    }

    void Bot::onNewUserConnected(User &user) {
        implementation->handleUser(user);
    }

    Bot::Bot(const Bot &obj) {
        throw std::logic_error("Bot is non-copiable object.");
    }

    Bot::~Bot() {
        delete implementation;
    }
}
