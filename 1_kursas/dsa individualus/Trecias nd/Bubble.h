#ifndef BUBBLE_H_INCLUDE
#define BUBBLE_H_INCLUDE
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>


template <typename T>
void bubbleSort(std::vector<T>& arr)
{
     for(int i=0;i<arr.size()-1;++i){
		for(int j=0;j<arr.size()-i-1;++j){
			if(arr[j]>arr[j+1]){
				// T temp = arr[j+1];
				// arr[j+1] = arr[j];
				// arr[j] = temp;
                std::swap(arr[j+1], arr[j]);
			}
		}
	}
}
 
/* Function to print an array */

template <typename T>
void printVector(std::vector<T> vec){
    for (size_t i=0;  i <vec.size();  i++) {
        std::cout<<vec[i]<<" ";

    }
  std::cout<<std::endl;
}

#endif