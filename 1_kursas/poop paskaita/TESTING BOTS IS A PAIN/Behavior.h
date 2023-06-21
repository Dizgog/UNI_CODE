#ifndef CHATBOT_BEHAVIOR_H
#define CHATBOT_BEHAVIOR_H

#include "User.h"
#include "Interaction.hpp"
#include "Message.h"

namespace bot {
    class Behavior {
    public:
        virtual void run(User &user, Interaction interaction);
    };

    class QuestionBehavior : public Behavior {
    private:
        std::function<bool(std::string)> inputValidator;
        std::function<void(std::string)> onResult;
        Message *question;
        Message *invalidInput;
        std::string defaultAnswer;
        QuestionBehavior(const QuestionBehavior &other);
    public:
        explicit QuestionBehavior(
                std::function<void(std::string)> onResult,
                std::function<bool(std::string)> inputValidator,
                std::string defaultAnswer,
                Message *question,
                Message *invalidInput);
        ~QuestionBehavior();

        void run(User &user, Interaction interaction) override;
    };

    class BehaviorSequence : public Behavior {
    private:
        std::vector<Behavior*> behaviors;
        BehaviorSequence(const BehaviorSequence &other);
    public:
        explicit BehaviorSequence(std::vector<Behavior*> behaviors);
        ~BehaviorSequence();

        void run(User &user, Interaction interaction) override;
    };

    class SayMessageBehavior : public Behavior {
    private:
        Message *message;
        SayMessageBehavior(const BehaviorSequence &other);
    public:
        explicit SayMessageBehavior(Message *message);
        ~SayMessageBehavior();

        void run(User &user, Interaction interaction) override;
    };
}

#endif //CHATBOT_BEHAVIOR_H
