#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <algorithm>
#define N 100
using namespace std;
using namespace chrono;

void pushv(vector<int>& input, vector<int>& test);
void pushd(vector<int>& input, deque<int>& test);
void pushl(vector<int>& input, list<int>& test);

void push_pullv(vector<int>& input, vector<int>& test);
void push_pulld(vector<int>& input, deque<int>& test);
void push_pulll(vector<int>& input, list<int>& test);

void sortedv(vector<int>& input, vector<int>& test);
void sortedd(vector<int>& input, deque<int>& test);
void sortedl(vector<int>& input, list<int>& test);

int main()
{
    vector<int> input;
    srand(time(NULL));
    int rnum;
    for(int i = 0; i < N; ++i)
    {

        rnum = rand() % 1000;
        input.push_back(rnum);
    }

    chrono::time_point<chrono::system_clock> start, end;




    cout << "#######################INPUT IN THE BACK#######################"<<endl;

    vector<int> vtest;
    auto vstart = chrono::system_clock::now();
    pushv(input, vtest);
    auto vend = chrono::system_clock::now();
    auto vduration = duration_cast<microseconds>(vend - vstart);
    cout<<"Vector input in the back: " << vduration.count() << " microseconds" << endl;

    auto dstart = chrono::system_clock::now();
    deque<int> dtest;
    pushd(input, dtest);
    auto dend = chrono::system_clock::now();
    auto dduration = duration_cast<microseconds>(dend - dstart);
    cout<<"Deque input in the back: " << dduration.count() << " microseconds" << endl;

    auto lstart = chrono::system_clock::now();
    list<int> ltest;
    pushl(input, ltest);
    auto lend = chrono::system_clock::now();
    auto lduration = duration_cast<microseconds>(lend - lstart);
    cout<<"List input in the back: " << lduration.count() << " microseconds" << endl;

    vtest.clear();
    dtest.clear();
    ltest.clear();

    cout << "#######################INPUT IN THE BACK AND THE FRONT#######################"<<endl;

    auto vstart_2 = chrono::system_clock::now();
    push_pullv(input, vtest);
    auto vend_2 = chrono::system_clock::now();
    auto vduration_2 = duration_cast<microseconds>(vend_2 - vstart_2);
    cout<< "Vector input in the back and the front: " << vduration_2.count() << " microseconds" << endl;

    auto dstart_2 = chrono::system_clock::now();
    push_pulld(input, dtest);
    auto dend_2 = chrono::system_clock::now();
    auto dduration_2 = duration_cast<microseconds>(dend_2 - dstart_2);
    cout<< "Deque input in the back and the front: " << dduration_2.count() << " microseconds" << endl;

    auto lstart_2 = chrono::system_clock::now();
    push_pulll(input, ltest);
    auto lend_2 = chrono::system_clock::now();
    auto lduration_2 = duration_cast<microseconds>(lend_2 - lstart_2);
    cout<< "List input in the back and the front: " << lduration_2.count() << " microseconds" << endl;

    vtest.clear();
    dtest.clear();
    ltest.clear();

    cout << "#######################INPUT SORTED#######################"<<endl;

    auto vstart_3 = chrono::system_clock::now();
    sortedv(input, vtest);
    auto vend_3 = chrono::system_clock::now();
    auto vduration_3 = duration_cast<microseconds>(vend_3 - vstart_3);
    cout<<"Vector sorted: " << vduration_3.count() << " microseconds" << endl;

    auto dstart_3 = chrono::system_clock::now();
    sortedd(input, dtest);
    auto dend_3 = chrono::system_clock::now();
    auto dduration_3 = duration_cast<microseconds>(dend_3 - dstart_3);
    cout<<"Deque sorted: " << dduration_3.count() << " microseconds" << endl;

    auto lstart_3 = chrono::system_clock::now();
    sortedl(input, ltest);
    auto lend_3 = chrono::system_clock::now();
    auto lduration_3 = duration_cast<microseconds>(lend_3 - lstart_3);
    cout<<"List sorted: " << lduration_3.count() << " microseconds" << endl;
    return 0;

}

void pushv(vector<int>& input, vector<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.push_back(input[i]);
    }
}
void pushd(vector<int>& input, deque<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.push_back(input[i]);
    }
}
void pushl(vector<int>& input, list<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.push_back(input[i]);
    }
}

void push_pullv(vector<int>& input, vector<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        if(i % 2 == 0)
        {
        test.insert(test.begin(), input[i]);
        }
        else
        {
        test.push_back(input[i]);
        }
    }
}
void push_pulld(vector<int>& input, deque<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        if(i % 2 == 0)
        test.push_front(input[i]);
        else
        test.push_back(input[i]);
    }
}
void push_pulll(vector<int>& input, list<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        if(i % 2 == 0)
        test.push_front(input[i]);
        else
        test.push_back(input[i]);
    }
}

void sortedv(vector<int>& input, vector<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.insert(upper_bound(test.begin(), test.end(), input[i]), input[i]);
    }
}
void sortedd(vector<int>& input, deque<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.insert(upper_bound(test.begin(), test.end(), input[i]), input[i]);
    }
}
void sortedl(vector<int>& input, list<int>& test)
{
    for(int i = 0; i < N; ++i)
    {
        test.insert(upper_bound(test.begin(), test.end(), input[i]), input[i]);
    }
}
