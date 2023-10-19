    #include <iostream>
    #include <sstream>
    #include <string>
    using namespace std;



int main()
{
    string name;

    string lowerN[4] = {"Puts some confidence in to the first letter of your name", "Come on, I know you can do better than that", "Are you even trying?", "I see you are not trying indeed"};
    string lengtN[4] = {"My hearing has gotten quite bad, could you repeat your name?", "Speak up young man", "That can't be your real name", "If this is your actual make a nick name or something"};
    string upperN[4] = {"You don't need to shout your name!", "I hear you just fine, so don't shout", "CAN YOU BE EVEN MORE LOUD?", "*Dies from you making too much sound*"};
    string greetN[4] = {"Nice to meet you ", "Hello ", "Can't say its a pleasure ", "I don't actually want to speak to you, but beggars can't be choosers "};
    int mood = 0;
    cout << "Hello young one, what is your name" << endl;
    while(1)
    {
enter:
        int temp=0;
        getline(cin, name);

        if(islower(name[0]))
        {
        cout << lowerN[mood] << endl;

        if(mood<3)
            mood++;
        }

        if(name.length()<=2) //No name is one letter wrong
        {
            cout << lengtN[mood] << endl;

            if(mood<3)
            mood++;
        }

        if(temp!=1)
        {
            for (int n = 1; n<name.length(); ++n)
                if(isupper(name[n]))
                {
                    cout << upperN[mood] << endl;

                    if(mood<3)
                    mood++;

                    goto enter;
                }
                else
                    temp = 1;
        }
        if(isupper(name[0]) && name.length()>2 && temp == 1)
            break;
    }
    cout << "I see." << endl << greetN[mood] << name << endl;


    string answer;

    cout << "So " << name << " do you want to talk about dungeons and dragons?" << endl << "If you don't you can just say no" <<endl;

    cin >> answer;

    if(answer == "no" || answer == "No" || answer == "NO" || answer == "nO")
    {
        cout << "Well what a shame, guess i will get going if you're not interested" << endl;
        return 0;
    }
    else
    {
        cout << "Lovely its been a while since this old soul could share his passion with such a young person" << endl;

        cout << "So would you like to learn about the most popular races in the game? Well its not like I'm going to talk about anything else" << endl;

        cout << "I knew you ofcourse know about all of the main races in the game, but just to remember about them myself I'll say them" << endl;

        while(1)
        {
            cout << endl <<"So there are Dwarves, Elves, Halflings, Humans, Dragonborns, Gnomes, Half-elves, Half-orcs, and Tieflings." << endl << "Which one would you like to know more" << endl;

            cin >> answer;

            if(answer == "Dwarves")
            {
                cout << "Dwarves are short, strong mountain-dwelling folk known for their fantastic weaponry and long-standing grudges." << endl;
                cout << "They're culturally obsessed with gold and glory and have a deep loyalty to their clans." <<endl;
                cout << "Their society is made of a number of kingdoms in mountainous regions, who keep to themselves other than to trade their masterwork goods." << endl;
            }
             else if(answer == "Elves")
            {
                cout << "Elves are beautiful, tall, otherworldly humanoids." << endl;
                cout << "They're renowned for their magical prowess and elegant society, and ted to live in glittering cities ensconced in ancient forests or tall, thin, silver spires on the coasts." << endl;
                cout << "Culturally, elves are known to be unnervingly calm, with the perspective of centuries-long studies to fall back on." << endl;
                cout << "They’re highly diplomatic and somewhat isolationist in views." << endl;
            }
            else if(answer == "Halflings")
            {
                cout << "Halflings are generally about half the height of a human, with a huge love of food and creature comforts, Halflings generally seek out calm, peaceful lives in agricultural communities."<<endl;
                cout << "They have no need for adventures, thank you very much…except that they do because of their innate curiosity and empathy for those in distress." << endl;
            }
            else if(answer == "Humans")
            {
                cout << "Humans are really balanced and boring, you are one you should know what they are. If you want something fun don't chose this race" << endl;
            }
            else if(answer == "Dragonborns")
            {
                 cout << "As the name implies, these are a people descended from dragons, born with scales covering their bodies and powerful magic inherent in them." << endl;
                 cout << "While dragons in the game are amazing enough to talk for hours, it’s enough to say right now that they’re massive, powerful, rare, and their coloration determines their powers." << endl;
            }
            else if(answer == "Half-elves")
            {
                 cout << "These characters result from the unusual pairing of two disparate races, and one of the most common is the Half-Elf." << endl;
                 cout << "Because of their mixed ancestry, they can walk through both the Elven world and the world of their other parent, but they don’t really belong to either." << endl;
            }
            else if(answer == "Half-orcs")
            {
                 cout << " Half-Orcs are big, boisterous, and dangerous to have as enemies." <<endl;
                 cout << "Most often raised among the Orcs, a tribal and culturally violent race (who claim new territories through acts of war among themselves and value physical strength)" << endl;
                 cout << "Half-Orcs bear a lot of scars, both physically, in trying to prove their worth, and mentally, in trying to accept it." << endl;
            }
            else if(answer == "Tieflings")
            {
                 cout << " Tieflings have inherently interesting and unusual backstories! Tieflings are the products of an infernal bloodline, meaning they’re part-devil humanoids." <<endl;
                 cout << "An important note, though — they’re not half devils. That’s a different thing entirely. No, Tieflings are a few generations down the line." << endl;
            }

            else if(answer == "Gnomes")
            {
                cout << "They may be small but they know how to take up space — Gnomes are bombastic, excitable, and loud, known for trying anything and everything they can to sate their inquisitiveness." << endl;
                cout << "Gnomes live in rolling hills and bright woodlands, in cleverly hidden cities and settlements frequently built alongside Human dwellings." << endl;
            }
            else
            {
                cout << "I don't know about this class, or maybe just miss heard you, could you repeat that one more time?" << endl;
            }
        }
    }


    return 0;
}
