#ifndef TEMPLATES_H_INCLUDED
#define TEMPLATES_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#endif
template <typename T>
void bubbleSort(vector<T> &arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr.at(j) > arr.at(j+1))
        {
            T temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
}

struct Names
{
    string name;

    // constructor
    Names(string x): name(x) {}

    // overload the operator<
    bool operator<(const Names &r) const
    {
        if (name != r.name)
            return name < r.name;
    }

    // overload the operator> (if required)
    bool operator>(const Names &r) const
    {
        if (name != r.name)
            return name > r.name;
    }
};


class Subjects {
public:

    string subject;
    // constructor
    Subjects(string x): subject(x) {}

    // overload the operator<
    bool operator<(const Subjects &r) const
    {
        if (subject != r.subject)
            return subject < r.subject;
    }

    // overload the operator> (if required)
    bool operator>(const Subjects &r) const
    {
        if (subject != r.subject)
            return subject > r.subject;
    }

};

struct Letters{
char letter;

    Letters(char x): letter(x) {}

    // overload the operator<
    bool operator<(const Letters &r) const
    {
        if (letter != r.letter)
            return letter < r.letter;
    }

    // overload the operator> (if required)
    bool operator>(const Letters &r) const
    {
        if (letter != r.letter)
            return letter > r.letter;
    }
};
