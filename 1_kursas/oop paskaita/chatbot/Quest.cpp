#include "Quest.hpp"

std::vector<std::string> Quest::Quest::questList={"Furious Irmantas rushes in. He has a ton of homework for you",//BAD STUFF, ONLY WORK NO DRINKS + PUNISHMENT
"RANDOM CHIMP EVENT!!!", //2
"You were caught by slave traders. #LaborCampsBaby",//3
"You were caught red-handed by da Police. #LaborCampsBaby",//4
"Women. #LaborCampsBaby",//5
"Neatsakingas losimas gali pakenkti jums ir jusu artimiesiems",//6
"If only I had got that computer science degree...",//7
"F",//8
"This gotta be the best therapy",// PLEASANT STUFF, CAN BE A DRINKING TASK - PUNISHMENT
"What a surprising wave of motivation...",//10
"Irmantas is inviting you to a collaboration session. Will you take his offer?",//11
"RANDOM CHIMP EVENT!!!",//12
"A blessing by the gods. Only for the worthy!",//13
"Wooooahh? A CHALLENGER???",//14
"Men.", //ONLY DRINKING TASKS + PUNISHMENT
"A random alcoholic invited you to a drinking competition",//16
"Memories of your miserable childhood is starting to flood in. Prevent it from destroying your mentality!"//17
};

Quest::Quest::Quest(bool a)
{
    counter=0;
    if(a)generator();
}


void Quest::Quest::generator()
{
    std::vector<std::string>types ={"fish ", "mine ", "chop ", "work " ,"drink "};
    std::string result="";
    counter=0;
    int index=rand()%Quest::questList.size();
    if(index<=7)//BAD STUFF, ONLY WORK NO DRINKS + PUNISHMENT
    {
        type=1+rand()%4;
        reward=1+rand()%300;
        punishment=1+rand()%500;
        requirement=1+rand()%20;
        int duration=1+rand()%3;
        result+=Quest::questList[index];
        result+="\n";
        result+="You have to ";
        result+=types[type-1];
        result+=std::to_string(requirement);
        result+=" times, otherwise you will receive the punishment\nReward: ";
        result+=std::to_string(reward);
        result+="\nPunishment: ";
        result+=std::to_string(punishment);
        result+="\nTime limit: ";
        result+=std::to_string(duration);
        result+=" minutes";
        end = time(0)+duration*60;
    }
    else if(index>=14)//ONLY DRINKING TASKS + PUNISHMENT
    {
        type=5;
        reward=1+rand()%300;
        punishment=1+rand()%500;
        requirement=1+rand()%10;
        int duration=1+rand()%3;
        result+=Quest::questList[index];
        result+="\n";
        result+="You have to ";
        result+=types[type-1];
        result+=std::to_string(requirement);
        result+=" times, otherwise you will receive the punishment. YES YOU HAVE TO (YOUR PRIDE IS AT RISK)\nReward: ";
        result+=std::to_string(reward);
        result+="\nPunishment: ";
        result+=std::to_string(punishment);
        result+="\nTime limit: ";
        result+=std::to_string(duration);
        result+=" minutes";
        end = time(0)+duration*60;
    }
    else// PLEASANT STUFF, CAN BE A DRINKING TASK - PUNISHMENT
    {
        type=1+rand()%5;
        reward=1+rand()%300;
        punishment=1;
        requirement=1+rand()%20;
        int duration=1+rand()%3;
        result+=Quest::questList[index];
        result+="\n";
        result+="You have to ";
        result+=types[type-1];
        result+=std::to_string(requirement);
        result+=" times. Hard work leads to huge rewards!\nReward: ";
        result+=std::to_string(reward);
        result+="\nTime limit: ";
        result+=std::to_string(duration);
        result+=" minutes";
        end = time(0)+duration*60;
    }
    std::cout<<result<<std::endl<<std::endl;
    description=result;

}

int Quest::Quest::isComplete()
{
    if(counter>=requirement)return reward;
    else if(time(0)>=end)return -punishment;
    else return 0;
}

std::string Quest::Quest::getDesc() const
{
    return description;
}

int Quest::Quest::getType() const
{
    return type;
}

Quest::Quest& Quest::Quest::operator++()
{
    this->counter++;
    return *this;
}

Quest::Quest Quest::Quest::operator++(int)
{
    Quest new_qst=*this;
    this->counter++;
    return new_qst;
}
