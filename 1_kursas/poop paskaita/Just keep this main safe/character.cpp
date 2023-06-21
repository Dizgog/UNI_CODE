#include "character.h"

void Character::Character::increase(int atribute, int value)
{
    value+=(rand()%15)-7;
    if(energy>0)
    {
        if(atribute==STRENGTH)
        {
            std::cout<<"Your strength increased by: "<<value<<std::endl;
            strength+=value;
        }
        else if(atribute==AGILITY)
        {
            std::cout<<"Your agility increased by: "<<value<<std::endl;
            agility+=value;
        }
        else if(atribute==STAMINA)
        {
            std::cout<<"Your stamina increased by: "<<value<<std::endl;
            stamina+=value;
        }
        energy--;
    }
    else std::cout<<"Not enough energy. Head home to rest"<<std::endl;
}
Character::Character::Character(std::string name)
{
    this->name=name;
    this->strength=0;
    this->agility=0;
    this->stamina=0;
    this->energy=5;
}
Character::Character::Character(std::string name, int strength, int agility, int stamina)
{
    this->name=name;
    this->strength=strength;
    this->agility=agility;
    this->stamina=stamina;
    this->energy=0;
}
int Character::Character::getStrength() const
{
    return strength;
}
int Character::Character::getAgility() const
{
    return agility;
}
int Character::Character::getStamina() const
{
    return stamina;
}
int Character::Character::getEnergy() const
{
    return energy;
}
std::string Character::Character::getName() const
{
    return name;
}
void Character::Character::goHome(){

    this->energy = 5;

}
std::ostream& Character::operator<<(std::ostream &os, Character player)
{
    std::cout<<player.getName()<<" stats: "<<std::endl;
    std::cout<<"Strength: "<<player.getStrength()<<std::endl<<"Agility: "<<player.getAgility()<<std::endl<<"Stamina: "<<player.getStamina()<<std::endl;
    std::cout<<"Energy left: "<<player.getEnergy()<<std::endl;
}
