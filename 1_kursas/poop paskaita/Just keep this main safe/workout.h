#ifndef WORKOUT_H
#define WORKOUT_H
#include<string>
namespace Workout
{
    class Workout
    {
        private:
            std::string name;
            int level;
            std::string description;
            int atribute;
            int value;
        public:
            std::string getDescription() const;
            int getAtribute() const;
            int getValue() const;
            int getLevel() const;
            std::string getName() const;
            Workout& operator ++();
            Workout& operator --();
            Workout(std::string name, std::string description, int atribute, int value);
    };

}

#endif
