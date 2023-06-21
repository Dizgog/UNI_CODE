#include "multiset.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <string>

int multiset_add (int number)
{

    for (int n = 0; n<multi.elements.size(); ++n)
    {
        //cout << "lol";
        if (multi.elements.at(n) == number)
        {
         multi.counts[n] +=1;
         return 0;
        }
    }


        //cout << "lol"
    multi.elements.push_back(number);
    multi.counts.push_back(1);
    return 0;
}

int multiset_toString ()
{
    string tempe, tempc;

    for (int n = 0; n<multi.elements.size(); ++n)
    {
        tempe = to_string(multi.elements.at(n));
        tempc = to_string(multi.counts.at(n));
        multi.selements.push_back(tempe);
        multi.scounts.push_back(tempc);
    }
}
