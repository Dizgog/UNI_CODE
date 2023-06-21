#ifndef CHATBOT_NOTIMPLEMENTEDEXCEPTION_H
#define CHATBOT_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

namespace bot {
    class NotImplementedException : public std::exception {
    private:
        std::string exceptionMessage;
    public:
        explicit NotImplementedException(const std::string &methodName);

        const char *what() const noexcept override;
    };
}

#endif //CHATBOT_NOTIMPLEMENTEDEXCEPTION_H
