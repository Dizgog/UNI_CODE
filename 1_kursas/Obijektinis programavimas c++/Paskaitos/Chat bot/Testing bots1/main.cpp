#include "workout.h"
#include "character.h"
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    vector<Workout::Workout>workouts;
    vector<string>names={"Tam the Tremendous", "John the Aggressive", "Bullnecked Andrew", "Theobald Felwood", "Alexander Dankworth", "Armin Bordeaux", "Kraken", "Big Papa", "Mad Dog", "Irmantas Radavicius", "Daemon", "Gargoyle", "Zero", "Baby Brown", "Madness", "Elder Pogue", "Billy the Butcher"};
    workouts.push_back(Workout::Workout("Bench press", "The bench press, or chest press, is an upper-body weight training exercise in which the trainee presses a weight upwards while lying on a weight training bench.",STRENGTH, 7));
    workouts.push_back(Workout::Workout("Box jumps", "Jump training or plyos, are exercises in which muscles exert maximum force in short intervals of time, with the goal of increasing agility", AGILITY, 7));
    workouts.push_back(Workout::Workout("Treadmill", "A treadmill is a device generally used for walking, running, or climbing while staying in the same place.", STAMINA, 7));
    workouts.push_back(Workout::Workout("Sprint runs", "Fast as f booooy!", AGILITY, 12));
    workouts.push_back(Workout::Workout("Lumberjacks", "In a quick, chopping motion, swing both your arms side to side, left to right, as if hacking at a nice Ponderosa pine with an axe.", STRENGTH, 12));
    workouts.push_back(Workout::Workout("Squats", "A squat is a strength exercise in which the trainee lowers their hips from a standing position and then stands back up.", AGILITY, 12));
    workouts.push_back(Workout::Workout("Bulgarian splits", "JUST DONT.", STAMINA, 50));
    workouts.push_back(Workout::Workout("Hip thrust", "SUS. TRAP. MASTERRACE.", STRENGTH, 27));
    Character::Character MyPlayer("Daddy");
    Character::Character Enemy("", 15, 0, 3);

    srand(time(NULL));
    int choice1;
    size_t choice2;
    int value;
    while(1)
    {
        cout<< "\nGreetings, what would you like to do?\n1. HIT THE GYM\n2. Head home\n3. Fight in the JungleKING\n4. MyPlayer stats\n5. Workout.wiki\n6. End work" <<endl;
        cin>>choice1;
        while(getchar()!='\n');
        switch(choice1){
            case 1:
            {
                cout<<"Choose your workout:"<<endl;
                for(size_t i=0; i<workouts.size(); ++i)
                {
                    cout<<i+1<<". "<<workouts[i].getName()<<endl;
                }
                cin>>choice2;
                if((choice2-1)<workouts.size()&&(choice2-1)>=0)
                {
                    int choice3;
                    do
                    {
                        cout<<"Current level: "<< workouts[choice2-1].getLevel()<<endl;
                        cout<<"Do you want to increase(type 1)/lower(type -1) level? If not (type 0)"<<endl;
                        cin>>choice3;
                        if (choice3 == 1) ++workouts[choice2-1];
                        else if (choice3 == -1) --workouts[choice2-1];
                    }while(choice3 != 0);
                    if(workouts[choice2-1].getAtribute()==STRENGTH)
                        value = MyPlayer.getStrength();
                    if(workouts[choice2-1].getAtribute()==AGILITY)
                        value = MyPlayer.getAgility();
                    if(workouts[choice2-1].getAtribute()==STAMINA)
                        value = MyPlayer.getStamina();
                    if (value+10<workouts[choice2-1].getValue())
                    {
                        cout<<"You are too weak EgoLifter!!!"<<endl;
                    }
                    else
                    {
                        MyPlayer.increase(workouts[choice2-1].getAtribute(), workouts[choice2-1].getValue());
                    }
                }
                else
                {
                    cout<<"Undefined workout"<<endl;
                }
            break;
            }
            case 2:
            {
                cout<<"Energy replenished!!"<<endl;
                MyPlayer.goHome();
                break;
            }
            case 3:
            {
                Enemy=Character::Character(names[rand()%names.size()], rand()%(50+MyPlayer.getStrength()), rand()%(50+MyPlayer.getAgility()), rand()%(50+MyPlayer.getStamina()));
                cout<<"CHALLENGER IS: "<<Enemy.getName()<<endl;
                cout<<Enemy<<endl;
                int flag=0;
                if(Enemy.getStrength()<MyPlayer.getStrength())flag++;
                if(Enemy.getAgility()<MyPlayer.getAgility())flag++;
                if(Enemy.getStamina()<MyPlayer.getStamina())flag++;
                if(flag>=2)
                {
                    cout<<"VICTORY"<<endl;
                }
                else
                {
                    cout<<"Miserable loss. Go workout you weakling"<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<MyPlayer<<endl;
                break;
            }
            case 5:
            {
                size_t choice4;
                cout<<"Choose your workout:"<<endl;
                for(size_t i=0; i<workouts.size(); ++i)
                {
                    cout<<i+1<<". "<<workouts[i].getName()<<endl;
                }
                cin>>choice4;
                if((choice4-1)<workouts.size()&&(choice4-1)>=0)
                {
                    cout<<workouts[choice4-1].getDescription()<<endl;
                }
                break;
            }
            case 6:
            {
                cout<<"Ending work"<<endl;
                return 0;
            }
            default:
            {
                cout<<"Incorrect value"<<endl;
                break;
            }

        }
    }
    return 0;
}
