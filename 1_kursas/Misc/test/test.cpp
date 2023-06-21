#include "test.h"
#include <iostream>


//template <typename T>

void bubbleSort(std::vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}
 
/* Function to print an array */


void printVector(std::vector<int> a){
    for (size_t i=0;  i <a.size();  i++) {
        std::cout<<a[i]<<" ";

    }
  std::cout<<std::endl;
}