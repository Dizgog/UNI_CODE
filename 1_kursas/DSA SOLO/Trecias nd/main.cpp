#include <iostream>
//#include "Sort.h"
// #include "quick.h"
 #include "Hybrid.h"
//  #include "Bubble.h"
#define N 10
int main()
{
    std::vector<char> inputB = {'f','b','d','c','a','r','s','i','z','x'};
    std::vector<char> inputH = {'f','b','d','c','a','r','s','i','z','x'};
    std::vector<char> inputT = {'f','b','d','c','a','r','s','i','g','x'};

    std::vector<int> inputBB;
    std::vector<int> inputHH;
    std::vector<int> inputTT;
    srand(time(NULL));
    int rnum;
    for(int i = 0; i < N; ++i)
    {

        rnum = rand() % 1000;
        inputBB.push_back(rnum);
        inputHH.push_back(rnum);
        inputTT.push_back(rnum);
    }


    // printVector(inputB);
    // bubbleSort(inputB);
    // printVector(inputB);

    // printVector(inputBB);
    // bubbleSort(inputBB);
    // printVector(inputBB);
 

 
    // printVector(inputT);
    // quickSort(inputT, 0, N - 1) ;
    // printVector(inputT);

    // printVector(inputTT);
    // quickSort(inputTT, 0, N - 1);
    // printVector(inputTT);



    printVector(inputH);
    hybridSort(inputH, 0, N - 1);
    printVector(inputH);

    printVector(inputHH);
    hybridSort(inputHH, 0, N - 1);
    printVector(inputHH);
}
