#include <iostream>
#include "TEMPLATES.hpp"

using namespace std;


int main()
{
/*    vector<double> arr = {1.3, 4.2, 4.3, 9.2, .4};
    //double temp;
    double n = 5;
//  cout << "Iveskite skaicius i masyva" << endl;

    for(n=0; ;n++)
    {
        cin >> temp;

        if (temp == 0)
            break;

        arr.push_back(temp);
    }
*/
    int n = 5;
    //int
    vector<int> arr1 = {1, 4, 3, 9, 6};

    bubbleSort(arr1, n);
    for (int i = 0; i < n; i++)
        cout << arr1.at(i) << " ";
    cout << endl;

    //String
    vector<string> arr3 = {"see", "bee", "dee", "FR", "ABC"};
    bubbleSort(arr3, n);
    for (int i = 0; i < n; i++)
        cout << arr3.at(i) << " ";
    cout << endl;

    //double
    vector<double> arr2 = {1.3, 4.2, 4.3, 9.2, .4};
    bubbleSort(arr2, n);
    for (int i = 0; i < n; i++)
        cout << arr2.at(i) << " ";
    cout << endl;



     vector<Names> arr5 = {
        {"Barack"}, {"George"}, {"George"},
        {"Abraham"}, {"John"}
    };
    bubbleSort(arr5, n);
     for (const Names &node: arr5)
    {
        cout << node.name << ", ";

    }
    cout << endl;



     vector<Subjects> arr6 = {
        {"Mathematics"}, {"English"}, {"Physics"},
        {"Chemistry"}, {"History"}
    };
    bubbleSort(arr6, n);
     for (const Subjects &node: arr6)
    {
        cout << node.subject<< ", ";

    }
    cout << endl;

    vector<Letters> arr7 = {
        {'c'}, {'b'}, {'a'}, {'d'}, {'e'}, {'g'}
    };
    bubbleSort(arr7, n);
     for (const Letters &node: arr7)
    {
        cout << node.letter<< ", ";

    }
    cout << endl;
    /*
    vector<int> arr4 = {"ASD", "aSD","aSDF"};
    bubbleSort(arr4, 3);
    for (int i = 0; i < 3; i++)
        cout << arr4.at(i) << " ";
    cout << endl;
    */
    return 0;
}
