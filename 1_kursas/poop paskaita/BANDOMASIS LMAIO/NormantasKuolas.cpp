#include <iostream>
#include <string>
using namespace std;

std::string myTransform(std::string str)
{
    int pos, coun = 0;
    for (int i=0; i < str.length(); i++)
    {
        if (islower(str[i]))
        str[i] = str[i] - 32;

        if(str[i]==' '&&str[i]==str[i-1])
        {
            str.erase( str.begin() + i );
        }
    }


    for(int i=str.size()-1; i >= 0; i-- )
    {
        if(str[i]==' '&&str[i]==str[i-1])
        {
            str.erase( str.begin() + i );
        }
    }

    for (int i=0; i < str.length(); i++)
    {
        coun = 0;
        while(isdigit(str[i]))
        {
            coun++;
            str.erase (i,1);
        }
        if(coun > 0)
        {
         string str1 = to_string(coun);
            str.insert(i,str1);
        }
    }

    return str;
}
