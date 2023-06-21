#include "Player.hpp"


using namespace std;
string flip(vector<string>arr, int &pay);
string roll(vector<string>arr, int &pay);

int main()
{
    Player::Player a("This was hard ngl");
    srand(time(NULL));
    string commandline;
    vector<string>drinks={"It wasn't so bad...", "The beer here is the best","How about another one?", "Ahhh I want another", "5 Ukrainian hryvnia aint that much... Maybe another?", "Alcoholism kills people", "AAAAAAAAAAAAAAAAAAA", "Splendit", "SAIKOU NA?!!", "I want to die"};
    cout<<"Welcome to the pub, grab a drink!\nWe also employ: You can work here as a fisherman, lumberjack or a miner\nAnd if you have extra Hryvnia by the hand... Maybe try gambling?\n(Type 'Help' for commands)"<<endl;
    while(1)
    {
        getline(cin, commandline);
        vector<string>arr;
        stringstream ss(commandline);
        int words=0;
        while (ss.good()){
            string temp;
            ss>>temp;
            arr.push_back(temp);
            ++words;
        }
        if(arr[0]=="Terminate"||arr[0]=="terminate")
        {
            cout<<"Terminating myself..."<<endl;
            return 0;
        }
        else if(arr[0]=="Help"||arr[0]=="help"||arr[0]=="'Help'")
        {
            int helpcomm=20, helpdesc=100;
            cout<<"Here is a list of commands:"<<endl;
            cout<<setw(helpcomm)<<"Command name"<<"|"<<setw(helpdesc)<<"Command description"<<"|"<<endl;
            cout<<setfill('-')<<setw(helpcomm+helpdesc+1)<<"-"<<setfill(' ')<<"|"<<endl;
            //Comands list
            cout<<setw(helpcomm)<<"Profile"<<"|"<<setw(helpdesc)<<"Shows your profile: balance and career"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Quest"<<"|"<<setw(helpdesc)<<"Gives you the current quest description. Quests appear randomly"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Fish"<<"|"<<setw(helpdesc)<<"Catches a fish. A way of getting paid. Chance of catching big fat fishes"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Mine"<<"|"<<setw(helpdesc)<<"Mines some ore. A way of getting paid. Chance of mining rare materials"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Chop"<<"|"<<setw(helpdesc)<<"Chops a tree. A way of getting paid"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Flip <guess> <bet>"<<"|"<<setw(helpdesc)<<"Flips a coin. If <guess> is correct you get 133%-150% of the <bet>"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Roll <guess> <bet>"<<"|"<<setw(helpdesc)<<"Rolls a dice. If <guess> is correct you get 1000% of the <bet>"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Drink"<<"|"<<setw(helpdesc)<<"Only beer. Cost is 5 Ukrainian hryvnia"<<"|"<<endl;
            cout<<setw(helpcomm)<<"Terminate"<<"|"<<setw(helpdesc)<<"Ends the program"<<"|"<<endl;
            continue;//preventing from spawning a quest
        }
        else if(arr[0]=="Drink"||arr[0]=="drink")
        {
            if(a.getDrunkness()<10)
            {
                cout<<drinks[rand()%drinks.size()]<<endl;
                a.drink();
            }
            else
                cout<<"You are too drunk to even buy a drink. Go work a bit so you can evaporate the alcohol"<<endl;
        }
        else if(arr[0]=="Chop"||arr[0]=="chop")
        {
            a.chop();
        }
        else if(arr[0]=="Mine"||arr[0]=="mine")
        {
            a.mine();
        }
        else if(arr[0]=="Fish"||arr[0]=="fish")
        {
            a.fish();
        }
        else if(arr[0]=="Flip"||arr[0]=="flip")
        {
            a.flip(arr);
        }
        else if(arr[0]=="Roll"||arr[0]=="roll")
        {
            a.roll(arr);
        }
        else if(arr[0]=="Profile"||arr[0]=="profile")
        {
            cout<<a<<endl;
            continue; //preventing from spawning a quest
        }
        else if(arr[0]=="Quest"||arr[0]=="quest")
        {
            if(a.getIsQuest())cout<<a.getQuest()<<endl;
            else cout<<"You don't have a quest"<<endl;
            continue; //preventing from spawning a quest
        }
        else
        {
            cout<<"Could not recognize this command. If you wish for list of commands type 'Help'"<<endl;
            continue; //preventing from spawning a quest
        }

        if((!a.getIsQuest())&&!(rand()%3))a.new_quest();
        if(a.getIsQuest())a.checkQuest();
    }
    return 0;
}

