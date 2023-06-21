#include "Time.hpp"
#include <sstream>
#include <stdexcept>

Time::Time(int shour, int sminu, int ssec)
{
    setHour(shour);
    setMinu(sminu);
    setSec(ssec);
}

Time::~Time()
{
    cout << "Object removed successfully" << endl;
}

    void Time::setHour(int hour)
    {
        if(hour<0)
            throw invalid_argument("There cannot be a - hours");
        else if (hour>24)
            throw invalid_argument("There cannot be more than 24 hours in a day");
        else
            shour = hour;
    }

    void Time::setMinu(int minu)
    {
        if(minu<0)
            throw invalid_argument("There cannot be less than 0 minutes");
        else if (minu>60)
            throw invalid_argument("There cannot be more than 60 minutes");
        else
            sminu = minu;
    }

    void Time::setSec(int sec)
    {
        if(sec<0)
            throw invalid_argument("There cannot be less than 0 less");
        else if (sec>60)
            throw invalid_argument("There cannot be more than 60 seconds");
        else
            ssec = sec;
    }


    int Time::getHour()
    {
    return shour;
    }

    int Time::getMin()
    {
    return sminu;
    }

    int Time::getSec()
    {
    return ssec;
    }


void Time::ShowTime12H()
{
    stringstream ss;

    if(shour>12)
        ss << shour-12 << ":" << sminu << " PM" << endl;
    else
        ss << shour << ":" << sminu << " AM" << endl;

    cout << ss.str();
}

void Time::ShowTime24H()
{
    stringstream ss;

    ss << shour << ":" << sminu << ":" << ssec <<endl;

    cout << ss.str();
}

void Time::addSec(int addingSec)
{

int addingMin = 0, addingHour = 0;

    if(ssec + addingSec > 60)
    {
        while(ssec + addingSec > 60)
        {
            addingSec = addingSec - 60;
            addingMin++;
            if(addingMin + sminu > 60)
            {
                while(addingMin > 60)
                {
                    addingMin = addingMin - 60;
                    addingHour++;
                }
            }

        }
    }

      setSec(ssec + addingSec);
      setMinu(sminu + addingMin);
      setHour(shour + addingHour);
}
