#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Quest.hpp"

namespace Player
{
    class Player{
    private:
        std::string name;
        int monee;
        int drunkness;
        int lumberlevel, fisherlevel, minerlevel;
        int lumberexp, fisherexp, minerexp;
        int counterw, counterc, counterf, counterm; //How many times worked, chopped, fished, mined.
        bool isQuest;
        Quest::Quest quest;
        // To be created
        //std::vector<Achievement>ach;
        //bool hasAchieved(int index);
    public:
        Player(std::string name="Kolega");
        int getDrunkness() const;
        int getMonee() const;
        bool getIsQuest() const;
        std::string getQuest() const;
        void checkQuest();
        void new_quest();
        void drink();
        void fish();
        void chop();
        void mine();
        void flip(std::vector<std::string>arr);
        void roll(std::vector<std::string>arr);
        void profile();
        friend std::ostream& operator<<(std::ostream &os, Player a);
    };
}

#endif // PLAYER_HPP
