#include <iostream>
#include <vector>
using namespace std;

void bubbleSort1(vector<int> &v);

int main()
{
    vector<int> v = {6,2,1,4,3,5};

    bubbleSort1(v);
    return 0;
}


void bubbleSort1(vector<int> &v)
{
    int tavomama = 0, manomama=0;
        for (int i = 0; i < v.size()-1; ++i)
            for (int j = 0; j < v.size()-1-i; ++j)
            {
                manomama++;
                if (v[j] > v[j+1])
                    {
                    swap(v[j], v[j+1]);
                    tavomama++;
                    }
            }

    cout << "Palyginimas" << manomama << endl;
    cout << "SWAP" << tavomama << endl;
}

