#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include<vector>
#include<string>
#include <wchar.h>
using namespace std;

class Math{
    private:
        std::vector<char> num;
    public:
        Math(string digits);
        Math();
        void setVector(string digits);
        vector<char > getVector();
        //arithmetic operations
        Math operator+(Math math);
        Math operator-(Math math);
        Math operator*(Math math);
        Math operator/(Math math);
        Math operator%(Math math);
        // assignment operations
        Math& operator=(const Math& rhs);
        Math& operator=(Math& rhs);
        Math& operator=(string s);

        // Comparison operations
        bool operator==(Math& rhs);
        bool operator<=(Math& rhs);
        bool operator>=(Math& rhs);
        bool operator!=(Math& rhs);
        bool operator<(Math& rhs);
        bool operator>(Math& rhs);
        // Additional operations
        Math operator+=(Math math);
        Math operator-=(Math math);
        Math operator*=(Math math);
        Math operator/=(Math math);
        Math operator++();
        Math operator++(int);
        Math operator--();
        Math operator--(int);

        friend ostream& operator<<(ostream& os, const Math& dt);

        vector<char > fromStrToVec(string s);
        bool validation(string s);
        int size();
        void check(vector<char> &num);
        void alignment(vector<char > &a, vector<char > &b);
        void clear(vector<char > &c);
        unsigned long long int comma(vector<char > &a, vector<char > &b);
        bool isBigger(std::vector<char > &a, vector<char > &b);
        string toString(Math math);
        vector<char > substraction(vector<char > a, vector<char > b);
        vector<char > divide(vector<char > a, vector<char > b);
        vector<char > multiply(vector<char > a, vector<char > b);
        vector<char > addition(vector<char > a, vector<char > b);
};


#endif // MATH_H_INCLUDED
