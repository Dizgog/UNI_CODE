#include <iostream>
#include <ostream>
#include <map>
#include <iterator>
#include <fstream>
#include <string>
#include <set>
using namespace std;

map<string, set<string>> read_manufacturers(string name);
void print_map(map<string, set<string>> const &m);
int main()
{
    map<string, set<string>> test;

    test = read_manufacturers("car_manufacturers.txt");
    print_map(test);
    return 0;
}

map<string, set<string>> read_manufacturers(string name)
{
    string cars, country;
    ifstream myfile;
    myfile.open (name);
    map<string, set<string>> car;

    while(myfile >> cars >> country)
    {
        car[country].insert(cars);
    }

    myfile.close();
    return car;
}

void print_map(map<string, set<string>> const &m)
{
  for (const auto & iter : m)
    cout << iter.first << " = " << iter.second << endl;
}
