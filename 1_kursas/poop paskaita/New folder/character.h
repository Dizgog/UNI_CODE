#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#define STRENGTH 0
#define AGILITY 1
#define STAMINA 2

namespace Character
{
    class Character
    {
        private:
            std::string name;
            int strength;
            int agility;
            int stamina;
            int energy;
        public:
            void increase(int atribute, int value);
            Character(std::string name);
            Character(std::string name, int strength, int agility, int stamina);
            int getStrength() const;
            int getAgility() const;
            int getStamina() const;
            int getEnergy() const;
            std::string getName() const;
            void goHome();
            friend std::ostream& operator<<(std::ostream &os, Character player);
    };
}

#endif
