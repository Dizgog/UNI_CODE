#include "PlayerPC.h"

namespace BotSpace {
    using namespace std;

    PlayerPC::PlayerPC(string name) {
        this->name = name;
        score = 0;
        words = {"long", "shoes", "flower", "flour", "battery", "carpenter", "forest", "aside",
                 "astonishment", "sustainable", "rich", "poverty", "fourteen", "business", "presentation",
                 "implementation", "shelter", "frustration", "unbelievable", "risk", "damage", "security",
                 "entertainment", "environment", "suggest", "offer", "punishment", "details", "money",
                 "household", "implication"};
    }

    string PlayerPC::getName() const {
        return name;
    }

    PlayerPC::~PlayerPC() {
    }

    int PlayerPC::getScore() const {
        return score;
    }

    void PlayerPC::printLetters() {
        word = words[utilities.random(words.size())];
        string shuffledWord = word;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(shuffledWord.begin(), shuffledWord.end(), default_random_engine(seed));
        cout << shuffledWord << endl;
    }

    void PlayerPC::addScore(int score) {
        this->score += score;
    }

    string PlayerPC::getWord() {
        return word;
    }

    string PlayerPC::guessWord(string shuffled) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(shuffled.begin(), shuffled.end(), default_random_engine(seed));
        return shuffled;
    }

    bool PlayerPC::accept(string newWord) {
        return word == newWord;
    }
}