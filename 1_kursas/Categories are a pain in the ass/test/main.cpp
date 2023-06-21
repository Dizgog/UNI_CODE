#include <iostream>
#include "test.h"
//#include "test.cpp"
#define N 100
int main()
{
    std::vector<int> input;
    srand(time(NULL));
    int rnum;
    for(int i = 0; i < N; ++i)
    {

        rnum = rand() % 1000;
        input.push_back(rnum);
    }


    printVector(input);
    bubbleSort(input);
    printVector(input);



}