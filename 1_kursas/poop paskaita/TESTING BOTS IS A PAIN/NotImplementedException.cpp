#include "NotImplementedException.h"

namespace bot {
    NotImplementedException::NotImplementedException(const std::string &methodName)
        : exceptionMessage("Method " + methodName + " is not implemented.") {
    }

    const char *NotImplementedException::what() const noexcept {
        return exceptionMessage.c_str();
    }
}