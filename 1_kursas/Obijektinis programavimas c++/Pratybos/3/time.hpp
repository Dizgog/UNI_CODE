#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Time{

private:
    int hour, minu, sec;
    int shour, sminu, ssec;
public:

    //int hour, minu, sec;
    Time(int shour = 0, int sminu = 0, int ssec = 0);
   ~Time();

    void setHour(int hour);
    void setMinu(int minu);
    void setSec(int sec);

    int getHour();
    int getMin();
    int getSec();

    void ShowTime12H();
    void ShowTime24H();

    void addSec(int addingSec);
};

#endif
