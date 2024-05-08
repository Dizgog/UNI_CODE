//#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& A, int left, int mid, int right, vector<int>& temp, int& comparisons) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (A[i] < A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
        comparisons++; // Pridedame palyginimą
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (int idx = left; idx <= right; idx++) {
        A[idx] = temp[idx];
    }
}

void mergeSort(vector<int>& A, int left, int right, vector<int>& temp, int& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid, temp, comparisons);
        mergeSort(A, mid + 1, right, temp, comparisons);
        merge(A, left, mid, right, temp, comparisons);
    }
}

int main() {
    vector<int> A = {3, 23, 33, 43, 51, 61, 72, 85};
    int comparisons = 0;
    vector<int> temp(A.size());

    mergeSort(A, 0, A.size() - 1, temp, comparisons);

    cout << "Surūšiuotas masyvas: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Atlikti palyginimai: " << comparisons << endl;

    return 0;
}
