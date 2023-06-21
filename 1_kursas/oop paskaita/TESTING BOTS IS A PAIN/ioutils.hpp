#ifndef CHATBOT_IOUTILS_HPP
#define CHATBOT_IOUTILS_HPP

#include <vector>
#include <iostream>
#include <regex>

template<class T>
std::ostream &operator<<(std::ostream& output, std::vector<T> list) {
    output << "{ ";
    for(T item : list) {
        output << item << ", ";
    }
    output << "}";

    return output;
}

bool isPositiveAnswer(std::string answer) {
    std::regex positiveAnswerRegexp("^(y[ea]+[shp]?)|(aha)$");

    std::transform(answer.begin(), answer.end(), answer.begin(), [](char a) {
        return std::tolower(a);
    });

    return std::regex_match(answer, positiveAnswerRegexp);
}

#endif