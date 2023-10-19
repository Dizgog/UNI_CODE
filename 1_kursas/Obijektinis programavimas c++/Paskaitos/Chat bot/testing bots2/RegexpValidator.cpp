#include "RegexpValidator.h"

namespace bot {
    RegexpValidator::RegexpValidator(std::regex regExp): regExp(std::move(regExp)) {

    }

    RegexpValidator::RegexpValidator(const std::string &source): regExp(source) {

    }

    bool RegexpValidator::operator()(const std::string &value) const {
        return std::regex_match(value, regExp);
    }
}