#ifndef CHATBOT_REGEXPVALIDATOR_H
#define CHATBOT_REGEXPVALIDATOR_H

#include <string>
#include <regex>

namespace bot {
    class RegexpValidator {
    private:
        std::regex regExp;
    public:
        explicit RegexpValidator(std::regex);
        explicit RegexpValidator(const std::string&);

        bool operator()(const std::string&) const;
    };
}

#endif //CHATBOT_REGEXPVALIDATOR_H
