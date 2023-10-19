#include<vector>
#include"Math.h"
#include<iostream>
#include<string>
#include<string>
#include<sstream>
#include<regex>
#include<cctype>
//#include <wchar.h>
using namespace std;


bool Math::validation(string s){
    regex reg("(\\[0-9]+.[0-9]*)|(\\-[0-9]+.[0-9]*)|(\\[0-9]+)|(\\-[0-9]+)");
    if(regex_match(s,reg)){
        return true;
    }
    return false;
}
string Math::toString(Math math){
    stringstream ss;
    string s(math.num.begin(),math.num.end());
    ss<<s;
    return ss.str();
}
vector<char> Math::fromStrToVec(string s){
    vector<char> vec(s.begin(),s.end());
    return vec;
}
Math::Math(string digits){
    setVector(digits);
}
Math::Math(){
    vector<char> num={'0'};
}
void Math::setVector(string digits){

    //if(validation(digits)){
        this->num=fromStrToVec(digits);

    //}
//    else{
//        cout<<"LUL"<<endl;
//    }

}
vector<char> Math::getVector(){
    return this->num;
}
ostream& operator<<(ostream& os, const Math& dt){

    for(int i=0; i<dt.num.size(); ++i){
        os << dt.num.at(i);
    }

    return os;
}
int Math::size(){

    return num.size()-1;
}
 Math& Math::operator=(const Math& rhs){
     this->num=rhs.num;
    return *this;
}
Math& Math::operator=(Math& rhs){
    this->num=rhs.num;
    return *this;
}
Math Math::operator+(Math math){
    Math result;
    result.num=addition(this->num,math.num);
    return result;
}


Math Math::operator-(Math math){
    Math result;
    result.num=substraction(this->num,math.num);
    return result;
}

Math Math::operator*(Math math){
    Math result;
    result.num=multiply(this->num,math.num);
    return result;
}

Math Math::operator/(Math math) {
    Math result;
    result.num=divide(this->num,math.num);
    return result;
}
Math Math::operator%(Math math) {
    if((this->num[0]=='-')&&(math.num[0]!='-')){

    }
    if((this->num[0]!='-')&&(math.num[0]!='-')){
        stringstream ss;
         stringstream tmp;
        vector<char> c;
        char sym;

        Math res;
        Math result;
        int number;

        result.num=divide(this->num,math.num);
        string s(result.num.begin(),result.num.end());
        ss<<s;
        ss>>number;
        tmp<<number;

        for(int i=0; i<10; ++i){
            if(i == number){
                sym=number+48;
                c.push_back(sym);
            }
        }
        res.num=multiply(c,math.num);
        result.num=substraction(this->num,res.num);
        return result;
    }
    if((this->num[0]=='-')&&(math.num[0]=='-')){
        this->num.erase( this->num.begin());
        math.num.erase( math.num.begin());
        stringstream ss;
        stringstream tmp;
        vector<char> c;
        char sym;

        Math res;
        Math result;
        int number;

        result.num=divide(this->num,math.num);
        string s(result.num.begin(),result.num.end());
        ss<<s;
        ss>>number;
        tmp<<number;

        for(int i=0; i<10; ++i){
            if(i == number){
                sym=number+48;
                c.push_back(sym);
            }
        }
        res.num=multiply(c,math.num);
        result.num=substraction(this->num,res.num);
        if(result.num[0]=='0'){
            return result;
        }
        result.num.insert(result.num.begin(),'-');
        clear(result.num);
        return result;
    }
    if((this->num[0]!='-')&&(math.num[0]=='-')){

    }
    stringstream ss;
     stringstream tmp;
    vector<char> c;
    char sym;

    Math res;
    Math result;
    int number;

    result.num=divide(this->num,math.num);
    string s(result.num.begin(),result.num.end());
    ss<<s;
    ss>>number;
    tmp<<number;

    for(int i=0; i<10; ++i){
        if(i == number){
            sym=number+48;
            c.push_back(sym);
        }
    }
    res.num=multiply(c,math.num);
    result.num=substraction(this->num,res.num);
    return result;
}
bool Math::operator==(Math& rhs){
    return(this->num==rhs.num);
}
bool Math::operator<=(Math& rhs){
    return(this->num<=rhs.num);
}
bool Math::operator>=(Math& rhs){
    return(this->num>=rhs.num);
}
bool Math::operator!=(Math& rhs){
    return(this->num!=rhs.num);
}
bool Math::operator<(Math& rhs){
    return(this->num<rhs.num);
}
bool Math::operator>(Math& rhs){
    return(this->num>rhs.num);
}

Math Math::operator++(){
    Math result;
    Math one("1");
    result.num=addition(this->num,one.num);
    return result;
}
Math Math::operator++(int){
    Math result;
    Math one("1");
    result.num=addition(this->num,one.num);
    return result;
}

Math Math::operator--(){
    Math result;
    Math one("1");
    result.num=addition(this->num,one.num);
    return result;
}
Math Math::operator--(int){
    Math result;
    Math one("1");
    result.num=substraction(this->num,one.num);
    return result;
}
Math Math::operator+=(Math math){
    Math result;
    result.num=addition(this->num,math.num);
    return result;
}
Math Math::operator-=(Math math){
    Math result;
    result.num=substraction(this->num,math.num);
    return result;
}
Math Math::operator*=(Math math){
    Math result;
    result.num=multiply(this->num,math.num);
    return result;
}
Math Math::operator/=(Math math){
    Math result;
    result.num=divide(this->num,math.num);
    return result;
}
void Math::check(vector<char> &num) {
    bool pa=false;
    for(auto i:num){
            if(i=='.')
                return;
    }
    if(!pa){
        num.push_back('.');
        num.push_back('0');
    }
    return;
}


void Math::clear(vector<char> &c){
    if(c[0]=='-'){
            int i=0;
        while (c[i+1] == '0')
            c.erase(c.begin()+1);
    }
    while (c.front() == '0')
        c.erase(c.begin());
    if(c[0]=='-'){
        if (c[1] == '.')
            c.insert(c.begin()+1,'0');
        if (c[1] == '-')
            c.erase(c.begin()+1);
    }
    if (c.front() == '.')
        c.insert(c.begin(),'0');
    while (c.back() == '0')
        c.pop_back();
    if (c.back() == '.')
        c.insert(c.end(),'0');
}

unsigned long long int Math::comma(vector<char> &a, vector<char> &b){
    for(unsigned long long int i=a.size(); i > 0; i--){
        if(a[i-1]=='.'){
            a.erase(a.begin()+i-1);
            b.erase(b.begin()+i-1);
            return (a.size()-i+1);
        }
    }
}

void Math::alignment(vector<char> &a, vector<char> &b){
    unsigned long long int pa=0,za=0,pb=0,zb=0;
    for(unsigned long long int i=0;i<a.size();i++)
        if(a[i]=='.'){
            za=a.size()-1-i;
            pa=i;
            break;
        }
    for(unsigned long long int i=0;i<b.size();i++)
        if(b[i]=='.'){
            zb=b.size()-1-i;
            pb=i;
            break;
        }
    pb<pa ? b.insert(b.begin(), pa - pb, '0') : a.insert(a.begin(), pb - pa, '0');
    zb<za ? b.insert(b.end(), za - zb, '0') : a.insert(a.end(), zb - za, '0');
}

bool Math::isBigger(std::vector<char> &a, std::vector<char> &b) {
    alignment(a,b);
    for(unsigned long long int i=0;i<a.size();i++){
        if(a[i]<b[i]){
            return true;
        }else if(a[i]>b[i]){
            return false;
        }
    }
    return false;
}



vector<char> Math::substraction(std::vector<char> a, std::vector<char> b) {
    if((a[0]!='-')&&(b[0]!='-')){
            bool minus=false;
        check(a);
        check(b);
        if(isBigger(a,b)){
            a.swap(b);
            minus=true;
        }
        auto z=comma(a, b);
        for(unsigned long long int i=a.size(); i > 0; i--){
            long long int j= i - 2;
            int x=a[i-1]-b[i-1];
            if(x>=0){
                b[i-1]= static_cast<char>(x + '0');
            }else{
                b[i-1]= static_cast<char>(x + 10 + '0');
                while(a[j]=='0') {
                    a[j] = '9';
                    j--;
                }
                a[j]--;
            }
        }
        b.insert((b.end()-z),'.');
        clear(b);
        if(minus) b.insert(b.begin(),'-');
        return b;
    }
    if((a[0]=='-')&&(b[0]=='-')){
        b.erase(b.begin());
        a=addition(a,b);
        return a;

    }
    if((a[0]!='-')&&(b[0]=='-')){
            b.erase(b.begin());
            return addition(a,b);


    }

    if((a[0]=='-')&&(b[0]!='-')){
         a.erase(a.begin());
         a=addition(a,b);
         a.insert(a.begin(),'-');
         clear(a);
         return a;
    }
}


std::vector<char> Math::addition(std::vector<char> a, std::vector<char> b) {

    if((a[0]!='-')&&(b[0]=='-')){
        b.erase(b.begin());
        a=substraction(a,b);
        return a;
    }
    if((a[0]=='-')&&(b[0]!='-')){
        a.erase(a.begin());
        a=substraction(a,b);
        a.insert(a.begin(),'-');
        clear(a);
        return a;
    }
    if((a[0]!='-')&&(b[0]!='-')){
        check(a);
        check(b);
        alignment(a,b);
        a.insert(a.begin(),'0');
        b.insert(b.begin(),'0');
        auto z=comma(a,b);
        int x=0;
        for(unsigned long long int i=a.size();i>0;i--){
            x=a[i-1] + b[i-1] - 96;
            a[i-1]= static_cast<char>(x % 10 + '0');
            if(x>=10) a[i-2]++;
        }
        a.insert((a.end()-z),'.');
        clear(a);
        return a;
    }
    if((a[0]=='-')&&(b[0]=='-')){
        a.erase(a.begin());
        b.erase(b.begin());
        check(a);
        check(b);
        alignment(a,b);
        a.insert(a.begin(),'0');
        b.insert(b.begin(),'0');
        auto z=comma(a,b);
        int x=0;
        for(unsigned long long int i=a.size();i>0;i--){
            x=a[i-1] + b[i-1] - 96;
            a[i-1]= static_cast<char>(x % 10 + '0');
            if(x>=10) a[i-2]++;
        }
        a.insert((a.end()-z),'.');
        a.insert(a.begin(),'-');
        clear(a);
        return a;
    }

}


std::vector<char> Math::multiply(std::vector<char> a, std::vector<char> b) {


       if((a[0]=='-')&&(b[0]=='-')){
        a.erase(a.begin());
        b.erase(b.begin());

        check(a);
        check(b);
        alignment(a,b);
        auto x=comma(a,b);
        unsigned long long int m = a.size(), n = b.size();
        std::vector<int> dp(m+n,0);
        for ( long long int i = m-1; i >= 0; i-- ) {
            for ( long long int j = n-1; j >= 0; j-- ) {
                dp[m+n-i-j-2] += (a[i]-'0')*(b[j]-'0');
                dp[m+n-i-j-1] += dp[m+n-i-j-2]/10;
                dp[m+n-i-j-2] %= 10;
            }
        }
        a.clear();
        for ( long long int i = m+n-1; i >= 0; i-- )
              a.push_back(static_cast<char &&>(dp[i] + '0'));
                a.insert((a.end()-2*x),'.');
                clear(a);
                return a;


    }
    if((a[0]=='-')&&(b[0]!='-')){
        a.erase(a.begin());
        check(a);
        check(b);
        alignment(a,b);
        auto x=comma(a,b);
        unsigned long long int m = a.size(), n = b.size();
        std::vector<int> dp(m+n,0);
        for ( long long int i = m-1; i >= 0; i-- ) {
            for ( long long int j = n-1; j >= 0; j-- ) {
                dp[m+n-i-j-2] += (a[i]-'0')*(b[j]-'0');
                dp[m+n-i-j-1] += dp[m+n-i-j-2]/10;
                dp[m+n-i-j-2] %= 10;
            }
        }
        a.clear();
        for ( long long int i = m+n-1; i >= 0; i-- )
                a.push_back(static_cast<char &&>(dp[i] + '0'));
                a.insert((a.end()-2*x),'.');
                a.insert(a.begin(),'-');
                clear(a);
                return a;
    }

      if((a[0]!='-')&&(b[0]=='-')){
        b.erase(b.begin());
        check(a);
        check(b);
        alignment(a,b);
        auto x=comma(a,b);
        unsigned long long int m = a.size(), n = b.size();
        std::vector<int> dp(m+n,0);
        for ( long long int i = m-1; i >= 0; i-- ) {
            for ( long long int j = n-1; j >= 0; j-- ) {
                dp[m+n-i-j-2] += (a[i]-'0')*(b[j]-'0');
                dp[m+n-i-j-1] += dp[m+n-i-j-2]/10;
                dp[m+n-i-j-2] %= 10;
            }
        }
        a.clear();
        for ( long long int i = m+n-1; i >= 0; i-- )
                a.push_back(static_cast<char &&>(dp[i] + '0'));
                a.insert((a.end()-2*x),'.');
                a.insert(a.begin(),'-');
                clear(a);
                return a;
    }

        if((a[0]!='-')&&(b[0]!='-')){
            check(a);
            check(b);
            alignment(a,b);
            auto x=comma(a,b);
            unsigned long long int m = a.size(), n = b.size();
            std::vector<int> dp(m+n,0);
            for ( long long int i = m-1; i >= 0; i-- ) {
                for ( long long int j = n-1; j >= 0; j-- ) {
                    dp[m+n-i-j-2] += (a[i]-'0')*(b[j]-'0');
                    dp[m+n-i-j-1] += dp[m+n-i-j-2]/10;
                    dp[m+n-i-j-2] %= 10;
                }
            }
            a.clear();
            for ( long long int i = m+n-1; i >= 0; i-- )
                  a.push_back(static_cast<char &&>(dp[i] + '0'));
                    a.insert((a.end()-2*x),'.');
                    clear(a);
                    return a;


        }



}

std::vector<char> Math::divide(std::vector<char> a, std::vector<char> b){

    if((a[0]=='-')&&(b[0]=='-')){
        a.erase(a.begin());
        b.erase(b.begin());


            vector<char> zero={{'0'},{'.'},{'0'}};
        check(a);
        check(b);
        alignment(b,zero);
        if(b==zero) {
            cout<<"You just tried to divide by zero, please don't do that."<<endl;
            return {{'0'},{'.'},{'0'}};}
        unsigned long long int x;
        for(unsigned long long int i=0;i<b.size();i++)
            if(b[i]=='.'){
                x=b.size()-1-i;
                b.erase(b.end()-x-1);
                break;
            }
        for(unsigned long long int i=0;i<a.size();i++)
            if(a[i]=='.'){
                x+=i;
                a.erase(a.begin()+i);
                break;
        }
        vector<char> w(a.size()+100,'0'), c;
        for(unsigned long long int i=0;i<100;i++) a.push_back('0');
        for(unsigned long long int i=0;i<a.size();i++){
        c.push_back(a[i]);
        check(c);
        check(b);
        while(!isBigger(c,b)){
            c=substraction(c,b);
            w[i]++;
        }
        c.pop_back();
        c.pop_back();
        }

        w.insert(w.begin()+x,'.');
        clear(w);
        return w;
    }
     if((a[0]=='-')&&(b[0]!='-')){
            a.erase(a.begin());

            vector<char> zero={{'0'},{'.'},{'0'}};
        check(a);
        check(b);
        alignment(b,zero);
        if(b==zero) {
            cout<<"You just tried to divide by zero, please don't do that."<<endl;
            return {{'0'},{'.'},{'0'}};}
        unsigned long long int x;
        for(unsigned long long int i=0;i<b.size();i++)
            if(b[i]=='.'){
                x=b.size()-1-i;
                b.erase(b.end()-x-1);
                break;
            }
        for(unsigned long long int i=0;i<a.size();i++)
            if(a[i]=='.'){
                x+=i;
                a.erase(a.begin()+i);
                break;
        }
        vector<char> w(a.size()+100,'0'), c;
        for(unsigned long long int i=0;i<100;i++) a.push_back('0');
        for(unsigned long long int i=0;i<a.size();i++){
        c.push_back(a[i]);
        check(c);
        check(b);
        while(!isBigger(c,b)){
            c=substraction(c,b);
            w[i]++;
        }
        c.pop_back();
        c.pop_back();
        }

        w.insert(w.begin()+x,'.');
        w.insert(w.begin(),'-');
        clear(w);
        return w;
     }
         if((a[0]!='-')&&(b[0]=='-')){
            b.erase(b.begin());

            vector<char> zero={{'0'},{'.'},{'0'}};
        check(a);
        check(b);
        alignment(b,zero);
        if(b==zero) {
            cout<<"You just tried to divide by zero, please don't do that."<<endl;
            return {{'0'},{'.'},{'0'}};}
        unsigned long long int x;
        for(unsigned long long int i=0;i<b.size();i++)
            if(b[i]=='.'){
                x=b.size()-1-i;
                b.erase(b.end()-x-1);
                break;
            }
        for(unsigned long long int i=0;i<a.size();i++)
            if(a[i]=='.'){
                x+=i;
                a.erase(a.begin()+i);
                break;
        }
        vector<char> w(a.size()+100,'0'), c;
        for(unsigned long long int i=0;i<100;i++) a.push_back('0');
        for(unsigned long long int i=0;i<a.size();i++){
        c.push_back(a[i]);
        check(c);
        check(b);
        while(!isBigger(c,b)){
            c=substraction(c,b);
            w[i]++;
        }
        c.pop_back();
        c.pop_back();
        }

        w.insert(w.begin()+x,'.');
        w.insert(w.begin(),'-');
        clear(w);
        return w;
     }

       if((a[0]!='-')&&(b[0]!='-')){
           vector<char> zero={{'0'},{'.'},{'0'}};
            check(a);
            check(b);
            alignment(b,zero);
            if(b==zero) {
                cout<<"You just tried to divide by zero, please don't do that."<<endl;
                return {{'0'},{'.'},{'0'}};}
            unsigned long long int x;
            for(unsigned long long int i=0;i<b.size();i++)
                if(b[i]=='.'){
                    x=b.size()-1-i;
                    b.erase(b.end()-x-1);
                    break;
                }
            for(unsigned long long int i=0;i<a.size();i++)
                if(a[i]=='.'){
                    x+=i;
                    a.erase(a.begin()+i);
                    break;
            }
            vector<char> w(a.size()+100,'0'), c;
            for(unsigned long long int i=0;i<100;i++) a.push_back('0');
            for(unsigned long long int i=0;i<a.size();i++){
            c.push_back(a[i]);
            check(c);
            check(b);
            while(!isBigger(c,b)){
                c=substraction(c,b);
                w[i]++;
            }
            c.pop_back();
            c.pop_back();
            }

            w.insert(w.begin()+x,'.');
            clear(w);
            return w;
    }

}
