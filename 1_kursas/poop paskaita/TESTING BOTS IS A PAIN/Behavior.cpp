#include "Behavior.h"

#include "NotImplementedException.h"

namespace bot {
    void Behavior::run(User &user, Interaction interaction) {
        throw NotImplementedException("Behavior::run");
    }

    QuestionBehavior::QuestionBehavior(
            std::function<void(std::string)> onResult,
            std::function<bool(std::string)> inputValidator,
            std::string defaultAnswer,
            Message *question,
            Message *invalidInput) :
            inputValidator(std::move(inputValidator)), question(question), invalidInput(invalidInput),
            onResult(std::move(onResult)), defaultAnswer(std::move(defaultAnswer)) {

    }

    QuestionBehavior::QuestionBehavior(const QuestionBehavior &other) {
        throw std::logic_error("Trying to copy non-copiable object");
    }

    QuestionBehavior::~QuestionBehavior() {
        delete question;
        delete invalidInput;
    }

    const int MAX_ATTEMPT_COUNT = 10;

    void QuestionBehavior::run(User &user, Interaction interaction) {
        int attemptCount = 0;
        std::string result;
        while (true) {
            ++attemptCount;

            interaction << question << std::endl;

            interaction >> result;

            if(inputValidator(result)) {
                break;
            } else if(attemptCount < MAX_ATTEMPT_COUNT) {
                interaction << invalidInput;
            } else {
                result = defaultAnswer;
                break;
            }
        }

        onResult(result);
    }

    BehaviorSequence::BehaviorSequence(std::vector<Behavior*> behaviors): behaviors(std::move(behaviors)) {
    }

    BehaviorSequence::~BehaviorSequence() {
        for(auto behavior : behaviors) {
            delete behavior;
        }
    }

    BehaviorSequence::BehaviorSequence(const BehaviorSequence &other) {
        throw std::logic_error("Trying to copy non-copiable object.");
    }

    void BehaviorSequence::run(User &user, Interaction interaction) {
        for(auto behavior : behaviors) {
            behavior->run(user, interaction);
        }
    }

    SayMessageBehavior::SayMessageBehavior(const BehaviorSequence &other) {
        throw std::logic_error("Trying to copy non-copiable object.");
    }

    SayMessageBehavior::SayMessageBehavior(Message *message): message(message) {

    }

    SayMessageBehavior::~SayMessageBehavior() {
        delete message;
    }

    void SayMessageBehavior::run(User &user, Interaction interaction) {
        interaction << message << '\n';
    };
}
