#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n);

int main()
{
    vector<int> arr;
    int temp;
    cout << "Iveskite skaicius i masyva" << endl;
    int n;

    for(n=0; ;n++)
    {
        cin >> temp;

        if (temp == 0)
            break;

        arr.push_back(temp);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr.at(i) << " ";
    cout << endl;

    return 0;
}

void bubbleSort(vector<int> &arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr.at(j) > arr.at(j+1))
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
}
