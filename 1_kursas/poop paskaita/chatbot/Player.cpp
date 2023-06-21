#include "Player.hpp"

Player::Player::Player(std::string name)
{
    this->name=name;
    this->monee=DEFAULT_MONEE;
    this->drunkness=0;

    this->lumberlevel=0;
    this->fisherlevel=0;
    this->minerlevel=0;

    this->lumberexp=0;
    this->fisherexp=0;
    this->minerexp=0;

    this->counterw=0;
    this->counterc=0;
    this->counterf=0;
    this->counterm=0;

    this->isQuest=false;
}

int Player::Player::getDrunkness() const
{
    return drunkness;
}

bool Player::Player::getIsQuest() const
{
    return isQuest;
}

std::string Player::Player::getQuest() const
{
    return quest.getDesc();
}

int Player::Player::getMonee() const
{
    return monee;
}

void Player::Player::new_quest()
{
    if(!isQuest)
    {
        std::cout<<std::endl;
        isQuest=1;
        quest = Quest::Quest(isQuest);
    }
}

void Player::Player::checkQuest()
{
    int result=quest.isComplete();
    if(result)
    {
        isQuest=0;
        if(result<0)
        {
            std::cout<<"QUEST FAILED"<<std::endl;
        }
        else
        {
            std::cout<<"QUEST FINISHED"<<std::endl;
        }
    monee+=result;
    }
}

void Player::Player::fish()
{
    std::string result="Fish Weight ";
    int weight=rand()%40;
    int pay=weight*(fisherlevel+1);
    result+=std::to_string(weight);
    result+="\nReward: ";
    result+=std::to_string(pay);
    result+=VALUTE;
    ++fisherexp;
    if(fisherexp/((fisherlevel+1)*20))
    {
        ++fisherlevel;
        fisherexp=0;
    }
    monee+=pay;
    if(drunkness)drunkness--;
    std::cout<<result<<std::endl;
    if(quest.getType()==1)quest++;
    if(quest.getType()==4)quest++;
}

void Player::Player::mine()
{
    std::string result="You mined ";
    int rarity=minerlevel+rand()%100;
    int pay=0;
    if(rarity<50)
    {
        result += "a scrap of copper\nReward: 1 ";
        result += VALUTE;
        pay=1;
    }
    else if(rarity<75)
    {
        result += "an iron ore\nReward: 5 ";
        result += VALUTE;
        pay=5;
    }
    else if(rarity<94)
    {
        result += "some titanium\nReward: 75 ";
        result += VALUTE;
        pay=75;
    }
    else if(rarity<99)
    {
        result += "a GOLD vein\nReward: 400 ";
        result += VALUTE;
        pay=400;
    }
    else
    {
        result+="DIAMOND\nReward: 1000 ";
        result += VALUTE;
        pay=1000;
    }
    ++minerexp;
    if(minerexp/((minerlevel+1)*10))
    {
        ++minerlevel;
        minerexp=0;
    }
    monee+=pay;
    if(drunkness)drunkness--;
    std::cout<<result<<std::endl;
    if(quest.getType()==2)quest++;
    if(quest.getType()==4)quest++;
}

void Player::Player::chop()
{
    std::string result="Chop chop";
    int value=rand()%20;
    int pay=value*(rand()%(lumberlevel+1+(rand()%10)));
    result+="\nReward: ";
    result+=std::to_string(pay);
    result+=VALUTE;
    ++lumberexp;
    if(lumberexp/((lumberlevel+1)*15))
    {
        ++lumberlevel;
        lumberexp=0;
    }
    monee+=pay;
    if(drunkness)drunkness--;
    std::cout<<result<<std::endl;
    if(quest.getType()==3)quest++;
    if(quest.getType()==4)quest++;
}


void Player::Player::drink()
{
    monee-=DRINK_PRICE;
    drunkness++;
    if(quest.getType()==5)quest++;
}

void Player::Player::flip(std::vector<std::string>arr)
{
    if(arr.size()!=3)
    {
        std::cout<<"Command is: Flip <guess> <bet>"<<std::endl;
        return;
    }
    std::string result="";
    int pay=0;
    //Identifies guess
    int guess;
    if(arr[1]=="Heads"||arr[1]=="heads"||arr[1]=="0"||arr[1]=="Head"||arr[1]=="head")
        guess=0;
    else if(arr[1]=="Tails"||arr[1]=="tails"||arr[1]=="1"||arr[1]=="Tail"||arr[1]=="tail")
        guess=1;
    else
    {
        std::cout<<"Only Heads and Tails"<<std::endl;
        return;
    }

    //Validates bet
    int bet=stoi(arr[2]);
    if(monee<bet)
    {
        std::cout<<"Cannot bet what you don't have. Go work a bit"<<std::endl;
        return;
    }
    if(bet<=1||bet>10000)
    {
        std::cout<<"Valid bets are between 2 and 10000"<<std::endl;
        return;
    }


    int side=rand()%2;
    if(side)
        result+="You flipped Tails\n";
    else
        result+="You flipped Heads\n";

    if(side==guess)
    {
        result+="You won ";
        pay=bet+bet/2;
        result+=std::to_string(pay);\
        result+=VALUTE;
    }
    else
    {
        result+="You lost";
        pay=-bet;
    }
    monee+=pay;
    std::cout<<result<<std::endl;
}

void Player::Player::roll(std::vector<std::string>arr)
{
    if(arr.size()!=3)
    {
        std::cout<<"Command is: Roll <guess> <bet>"<<std::endl;
        return;
    }
    std::string result="";
    int pay=0;
    //Identifies guess
    int guess=-1;
    try
    {
        guess=stoi(arr[1]);
    }
    catch(...){};
    if(!guess||guess<0||guess>6)
    {
        std::cout<<"Only values 1 to 6 are valid guesses"<<std::endl;
        return;
    }

    //Validates bet
    int bet=-1;
    try
    {
        bet=stoi(arr[2]);
    }
    catch(...){};
    if(monee<bet)
    {
        std::cout<<"Cannot bet what you don't have. Go work a bit"<<std::endl;
        return;
    }
    if(bet<=1||bet>100000)
    {
        std::cout<<"Valid bets are between 2 and 100000"<<std::endl;
        return;
    }


    int side=1+rand()%6;
    std::cout<<"You rolled "<<side<<std::endl;

    if(side==guess)
    {
        result+="You won ";
        pay=bet*10;
        result+=std::to_string(pay);
        result+=VALUTE;
    }
    else
    {
        result+="You lost";
        pay=-bet;
    }
    std::cout<<result<<std::endl;
}

void Player::Player::profile()
{
    std::cout<<"\nUser Profile:\nName: "<<name<<"\nCurrent Balance: "<<monee<<"\nFisherman: lvl "<<fisherlevel<<"\nLumberjack: lvl "<<lumberlevel<<"\nDwarf: lvl "<<minerlevel<<std::endl;
}


std::ostream& Player::operator<<(std::ostream &os, Player a)
{
    a.profile();
    return os;
}
