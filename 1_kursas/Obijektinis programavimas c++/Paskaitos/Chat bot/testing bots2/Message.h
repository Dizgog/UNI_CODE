#ifndef CHATBOT_MESSAGE_H
#define CHATBOT_MESSAGE_H

#include <string>
#include <regex>

namespace bot {
    class Message {
    private:
        virtual std::string to_string() const;
    public:
        friend std::ostream& operator<<(std::ostream&, Message*);
    };

    class RandomMessage : public Message {
    private:
        class Implementation;
        Implementation *implementation;

        std::string to_string() const override;
    public:
        explicit RandomMessage(std::vector<std::string> variants);
        ~RandomMessage();
        RandomMessage(const RandomMessage &other);
    };
}

#endif //CHATBOT_MESSAGE_H
