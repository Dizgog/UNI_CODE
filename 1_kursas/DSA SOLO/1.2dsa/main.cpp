#include <iostream>
#include <string>
using namespace std;

string findSum(string str1, string str2);

int main()
{
   char test[51];
   char test1[51];
   cin.getline(test,51);
   //cin.clear();
   cin.getline(test1,51);
   cout<<findSum(test,test1)<<endl;
    return 0;
}


string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);


}
