#include "Message.h"

#include <random>

#include "NotImplementedException.h"

namespace bot {
    std::string Message::to_string() const {
        throw NotImplementedException("Message::to_string");
    }

    std::ostream &operator<<(std::ostream &out, Message *msg) {
        out << msg->to_string();

        return out;
    }

    class RandomMessage::Implementation {
    private:
        using size_type = std::vector<std::string>::size_type;

        const std::vector<std::string> variants;
        std::uniform_int_distribution<size_type> distribution;
        std::mt19937 randomEngine;
    public:
        explicit Implementation(std::vector<std::string> variants);

        std::string pickRandomMessage();
    };

    RandomMessage::Implementation::Implementation(std::vector<std::string> initialVariants) :
            variants(std::move(initialVariants)),
            randomEngine(std::random_device()()),
            distribution(std::uniform_int_distribution<size_type>(0, variants.size() - 1)) {
    }

    std::string RandomMessage::Implementation::pickRandomMessage() {
        return variants[distribution(randomEngine)];
    }

    RandomMessage::RandomMessage(std::vector<std::string> variants)
            : implementation(new Implementation(std::move(variants))) {

    }

    RandomMessage::~RandomMessage() {
        delete implementation;
    }

    RandomMessage::RandomMessage(const RandomMessage &other) {
        implementation = new Implementation(*other.implementation);
    }

    std::string RandomMessage::to_string() const {
        return implementation->pickRandomMessage();
    }
}