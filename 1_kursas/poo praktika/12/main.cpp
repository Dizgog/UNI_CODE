#include <iostream>
#include <vector>
#include <string.h>
class animal{
public:
    virtual void rawr()
    {
        std::cout << "rawr" << std::endl;
    }
};

class cat : public animal{
private:
    int legs = 4;
public:
    virtual void rawr()
    {
        std::cout << "meow" <<std::endl;
    }

};

class cow : public animal{
private:
    int legs = 4;
    int horns = 2;
public:
    virtual void rawr()
    {
        std::cout << "moo" << std::endl;
    }
};

class rooster : public animal{
private:
    int legs = 2;
    int wings = 2;
public:
    virtual void rawr()
    {
        std::cout << "cock-a-doodle-doo" << std::endl;
    }
};

class giant_cat : public animal{
private:
    int legs = 4;
public:
    virtual void rawr()
    {
        std::cout << "MEOW" << std::endl;
    }
};


class general_animal{
private:
    std::string animal;
    int legs, wings, horns;
public:
general_animal(std::string animal)
{
    setAnimal(animal);
}

    void setAnimal(std::string animal)
    {
        this->animal = animal;

        if(animal == "Animal")
        {
        }
        if(animal == "Cat")
        {
            setLegs(4);
        }
        if(animal == "Cow")
        {
            setLegs(4);
            setHorns(2);
        }
        if(animal == "Rooster")
        {
            setLegs(2);
            setWings(2);
        }
        if(animal == "GiantCat")
        {
            setLegs(4);
        }
    }

    void rawr()
    {
        if(animal == "Animal")
        {
            std::cout << "rawr" << std::endl;
        }
        if(animal == "Cat")
        {
            std::cout << "meow" << std::endl;
        }
        if(animal == "Cow")
        {
            std::cout << "moo" << std::endl;
        }
        if(animal == "Rooster")
        {
            std::cout << "cock-a-doodle-doo" << std::endl;
        }
        if(animal == "GiantCat")
        {
            std::cout << "MEOW" << std::endl;
        }
    }

    void setLegs(const int &legs)
        {
            this -> legs = legs;
        }

        void setWings(const int &wings)
        {
            this -> wings = wings;
        }

        void setHorns(const int &horns)
        {
            this -> horns = horns;
        }

        int getLegs() const
        {
            return legs;
        }

        int getWings() const
        {
            return wings;
        }

        int getCorns() const
        {
            return horns;
        }

};
int main(int argc, char const *argv[])
{
    animal an;
    cat ca;
    cow co;
    rooster ro;
    giant_cat gi;

    std::vector<animal> animals;

    animals.push_back(an);
    animals.push_back(ca);
    animals.push_back(co);
    animals.push_back(ro);
    animals.push_back(gi);

    std::vector<animal*> animals1;

    animals1.push_back(new animal);
    animals1.push_back(new cat);
    animals1.push_back(new cow);
    animals1.push_back(new rooster);
    animals1.push_back(new giant_cat);

    std::vector<animal>::iterator it;

    for (it = animals.begin(); it < animals.end(); it++)
    {
        (*it).rawr();
    }
    std::cout << std::endl;

    std::vector<animal *>::iterator it1;

    for (it1 = animals1.begin(); it1 < animals1.end(); it1++)
    {
        (*it1) -> rawr();
    }

    for (it1 = animals1.begin(); it1 < animals1.end(); it1++)
    {
        delete *it1;
    }

    std::cout << std::endl;

    std::vector<general_animal> animals2;
    animals2.push_back(general_animal("Animal"));
    animals2.push_back(general_animal("Cat"));
    animals2.push_back(general_animal("Cow"));
    animals2.push_back(general_animal("Rooster"));
    animals2.push_back(general_animal("GiantCat"));

    std::vector<general_animal>::iterator it2;

    for(it2 = animals2.begin(); it2 < animals2.end(); it2++)
    {
        (*it2).rawr();
    }

     std::cout << std::endl;
    return 0;
}
