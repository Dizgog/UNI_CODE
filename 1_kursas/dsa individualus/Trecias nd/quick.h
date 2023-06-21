#ifndef TREE_H_INCLUDE
#define TREE_H_INCLUDE
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <string.h>

template <typename T>
void swapp(std::vector<T> &arr, int pos1, int pos2){
	T temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

template <typename T>
int Partition(std::vector<T> &arr, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(arr[i]<arr[pivot]){
			swapp(arr, i, j);
			++j;
		}
	}
	swapp(arr, j,pivot);
	return j;
	
}

template <typename T>
void quickSort(std::vector<T> &arr, int start, int end ){
	if(start<end){
		int p = Partition(arr,start,end);
		quickSort(arr,start,p-1);
		quickSort(arr,p+1,end);
	}
	
}

template <typename T>
void printVector(std::vector<T> a){
    for (size_t i=0;  i <a.size();  i++) {
        std::cout<<a[i]<<" ";

    }
  std::cout<<std::endl;
}
 

#endif