#include "workout.h"

std::string Workout::Workout::getDescription() const
{
    return description;
}
int Workout::Workout::getAtribute() const
{
    return atribute;
}
int Workout::Workout::getValue() const
{
    return value;
}
int Workout::Workout::getLevel() const
{
    return level;
}
std::string Workout::Workout::getName() const
{
    return name;
}
Workout::Workout& Workout::Workout::operator ++()
{
    if (level<15)
    {
        level++;
        value+=5;
    }
    return *this;
}
Workout::Workout& Workout::Workout::operator --()
{
    if(level>1)
    {
        level--;
        value-=5;
    }
    return *this;
}
Workout::Workout::Workout(std::string name, std::string description, int atribute, int value)
{
    this->name=name;
    this->description=description;
    this->atribute=atribute;
    this->value=value;
    this->level=1;
}
