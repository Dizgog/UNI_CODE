#ifndef HYBRID_H_INCLUDE
#define HYBRID_H_INCLUDE
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>

template <typename T>
int partition(std::vector<T>& vec, int start, int end) {
    int pivot = start;
    for(int i = start + 1; i <= end; ++i) {
        if(vec[i] < vec[pivot]) {
            std::swap(vec[pivot + 1], vec[i]);
            std::swap(vec[pivot], vec[pivot + 1]);
            ++pivot;
        }
    }
    return pivot;
}

template <typename T>
void insertionSort(std::vector<T>& vec, int start, int end) {
    for(int i = start; i <= end; i++) {
        int j = i;
        while(j > start && vec[j-1] > vec[j]) {
            std::swap(vec[j-1], vec[j]);
            j--;
        }
    }
}

template <typename T>
void hybridSort(std::vector<T> &vec, int start, int end){
    while(start < end){
        if (end-start <= 10){
            insertionSort(vec, start, end);
            break;
        } else {
            int pivotIndex = partition(vec, start, end);
            if (pivotIndex - start < end - pivotIndex)
            {
                hybridSort(vec, start, pivotIndex - 1);
                start = pivotIndex + 1;
            }
            else {
                hybridSort(vec, pivotIndex + 1, end);
                end = pivotIndex - 1;
            }
        }
    }
}
template <typename T>
void printVector(std::vector<T> vec){
    for (size_t i=0;  i <vec.size();  i++) {
        std::cout<<vec[i]<<" ";

    }
  std::cout<<std::endl;
}


#endif