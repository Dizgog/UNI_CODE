#ifndef CHATBOT_INTERACTION_HPP
#define CHATBOT_INTERACTION_HPP

#include <string>
#include <iostream>
#include <type_traits>

namespace bot {
    class Interaction {
    private:
        std::istream &inputStream;
        std::ostream &outputStream;

        // Shamelessly stolen from https://stackoverflow.com/questions/8097534/type-trait-for-strings
        template<typename T>
        struct is_string
                : public std::disjunction<
                        std::is_same<char *, typename std::decay_t<T>>,
                        std::is_same<const char *, typename std::decay_t<T>>,
                        std::is_same<std::string, typename std::decay_t<T>>
                > {
        };
    public:
        explicit Interaction(std::istream &inputStream, std::ostream &outputStream)
                : inputStream(inputStream), outputStream(outputStream) {

        }

        template<class T>
        std::ostream &operator<<(T &&value) {
            outputStream << "bot> " << std::forward<T>(value);
            return outputStream;
        }

        std::ostream &operator<<(std::ostream& (*manip)(std::ostream&)) {
            outputStream << manip;
            return outputStream;
        }

        template<class T, class = typename std::enable_if<!is_string<T>::value, bool>::type>
        std::istream &operator>>(T &&value) {
            outputStream << "usr> ";
            inputStream >> std::forward<T>(value);

            return inputStream;
        }

        Interaction &operator>>(std::string &value) {
            outputStream << "usr> ";

            std::getline(inputStream, value);

            return *this;
        }
    };
}

#endif //CHATBOT_INTERACTION_HPP
