#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void bubbleSort(std::vector<std::string> &arr, int n);

int main()
{
    std::ofstream ofs("out.txt");
    std::vector<std::string> arr;
    std::string temp;
    std::cout << "Iveskite skaicius i masyva" << std::endl;
    int n;

    for(n=0; ;n++)
    {
        std::cin >> temp;

        if (temp == "-")
            break;

        arr.push_back(temp);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr.at(i) << " ";
        ofs << arr.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}

void bubbleSort(std::vector<std::string> &arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr.at(j) > arr.at(j+1))
        {
            std::string temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
}
