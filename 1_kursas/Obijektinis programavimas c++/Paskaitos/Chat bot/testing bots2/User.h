#ifndef CHATBOT_USER_H
#define CHATBOT_USER_H

#include <string>

namespace bot {
    class User {
    private:
        class Implementation;

        Implementation *implementation;
    public:
        explicit User();

        User(const User &);

        ~User();

        std::string getName() const;

        void setName(const std::string &name);
    };
}

#endif //CHATBOT_USER_H
