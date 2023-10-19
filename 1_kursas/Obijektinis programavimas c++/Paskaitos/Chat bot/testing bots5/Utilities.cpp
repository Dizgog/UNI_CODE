#include "Utilities.h"

namespace BotSpace {
    using namespace std;

    Utilities::Utilities() {
        srand(time(nullptr));
    }

    int Utilities::random(int size) {
        return rand() % size;
    }

    bool Utilities::validateName(string name) {
        if (!isupper(name[0])) {
            return false;
        }
        for (int i = 1; i < name.length(); ++i) {
            if (!islower(name[i])) {
                return false;
            }
        }
        return true;
    }

    bool Utilities::validateLetters(const string &letters) const {
        if (letters.length() < 3) {
            return false;
        }
        if (!all_of(letters.begin(), letters.end(), [](char l) { return islower(l); })) {
            return false;
        }
        return true;
    }

}
