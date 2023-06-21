#include <iostream>
#include <set>

#include "ioutils.hpp"
#include "sortingUtils.h"
#include "Bot.h"
#include "RegexpValidator.h"

class GreetUser : public bot::Behavior {
public:
    void run(bot::User &user, bot::Interaction interaction) override {
        interaction << "Hello, " << user.getName() << "!\n";
        interaction << "I'm a DSA Bot." << std::endl;
    }
};

class WhichSortYouAre : public bot::Behavior {
public:
    void run(bot::User &user, bot::Interaction interaction) override {
        while (true) {
            interaction << "Let's play a simple game.\n";
            interaction
                    << "Your goal is to sort given array to ascending order. I'll say, which sorting method you are.\n";
            interaction << "Let's begin. The array is:\n";

            std::vector<int> list = generateRandomList(10);
            std::vector<int> listCopy = list;
            interaction << list << '\n';
            interaction << "Tell me, which elements to swap? Write element values, not indexes.\n";

            std::set<int> swapsPerformed;

            std::string input;
            std::stringstream buffer;

            while (!isVectorSorted(list)) {
                interaction >> input;
                buffer.str(input);

                int a = -1, b = -1;
                buffer >> a >> b;

                buffer.clear();

                auto aPosition = std::find(list.begin(), list.end(), a);
                auto bPosition = std::find(list.begin(), list.end(), b);

                if (aPosition == list.end() || bPosition == list.end()) {
                    interaction << "Invalid values. Please, provide existing values\n";
                } else {
                    std::swap(*aPosition, *bPosition);
                    interaction << "Swapped elements " << a << " and " << b << ". Now array is:\n";
                    interaction << list << '\n';

                    swapsPerformed.insert(getOperationIndex(a, b, (int) list.size()));
                }
            }

            interaction << "You are " << determineWhichSort(listCopy, swapsPerformed) << '\n';
            interaction << "Want to play once more?\n";
            std::string answer;
            interaction >> answer;

            if (!isPositiveAnswer(answer)) {
                break;
            }
        }
    }
};

int main() {
    bot::Message *nameQuestion = new bot::RandomMessage(
            {
                    "Who are you?",
                    "What is your name?",
                    "How can I call you?",
                    "Name?",
            });
    bot::Message *invalidNameMessage = new bot::RandomMessage(
            {
                    "That is not your name.",
                    "Please, enter your REAL name.",
                    "Fun fact: the name is a capital letter, followed by few small letters.",
            });

    bot::Message *goodbyeMessage = new bot::RandomMessage(
            {
                    "Goodbye",
                    "Bye!",
                    "See you later",
                    "Bye bye!"
            });

    bot::User user{};

    auto onUserNameInput = [&user](const std::string &name) {
        user.setName(name);
    };

    bot::Behavior *askUserBehavior = new bot::QuestionBehavior(
            onUserNameInput,
            bot::RegexpValidator("^[A-Z][a-z]+(\\s+[A-Z][a-z]+)*\\s*$"),
            "Idiot",
            nameQuestion,
            invalidNameMessage);

    bot::Behavior *greetUserBehavior = new GreetUser();
    bot::Behavior *gameBehavior = new WhichSortYouAre();
    bot::Behavior *goodbyeBehavior = new bot::SayMessageBehavior(goodbyeMessage);
    bot::Behavior *mainBehavior = new bot::BehaviorSequence(
            {askUserBehavior, greetUserBehavior, gameBehavior, goodbyeBehavior});
    bot::Interaction interaction = bot::Interaction(std::cin, std::cout);

    bot::Bot bot(mainBehavior, interaction);

    bot.onNewUserConnected(user);

    return 0;
}
