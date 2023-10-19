#ifndef LOONG_H_INCLUDED
#define LOONG_H_INCLUDED

#include <stdio.h>
#include <iostream>

class Loong{
private:

    char number[51];
    //int tens;

public:

    Loong(string shour = "0");
   ~Loong();

    void add (char num);
    void subtract(char num);
    void multiply(char num);
    void divide(char num);
    void mod(char num);

    void more(char num);
    void les(char num);
    void moreor(char num);
    void lesor(char num);
    void euqual(char num);
    void notequal(char num);

    int get();
};

#endif
