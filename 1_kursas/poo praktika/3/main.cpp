#include <iostream>
#include "time.hpp"
#include <vector>
using namespace std;


int main()
{
    vector<int> items;
    int hour, minu, sec;
    Time p;
    bool set = false;
    while (!set)
    {
        vector<int> items;
        try
        {
            //Time P;
            cout << "Enter hours, minutes , seconds: " << endl;
            cin >>  hour;
            p.setHour(hour);

            cin >>  minu;
            p.setMinu(minu);

            cin >>  sec;
            p.setSec(sec);


            //P->ShowTime24H();
             Time c(hour,minu,sec);

            set = true;
        }
        catch (invalid_argument &error)
        {
            cerr << "Error inputing time: " << error.what() << endl;
        }
    }

    Time *a = new Time(24, 45, 23);
    Time *b = new Time(10, 15, 45);

     //P->ShowTime24H();

    //delete a;

    c->ShowTime24H();

    delete a;

    //b->ShowTime24H();

    b->ShowTime24H();

    //p->ShowTime24H();

    b->addSec(4000);

    b->ShowTime24H();

   // delete b;
    return 0;
}
