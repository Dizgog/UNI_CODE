#include <iostream>

using namespace std;


int root(double num);
int sin(double x, double y);
int Log(double n);

int main()
{
    double num, opp, hyp, Lo;
    /*
    cout << "Enter a number you want to root" << endl;
    cin >> num;
    num = root(num);
    cout << "Your number is " << num << endl;
    */
/*
    cout << "Enter the length of the opposite side from the angle" << endl;
    cin >> opp;
    cout << "Enter  the length of the hypotenuse" <<endl;
    cin >> hyp;
    cout << "The sin is " <<sin(opp,hyp) << endl;
    return 0;
*/

cout << "Enter a number you want to have a log(n) of " <<endl;
cin >> Lo;
cout << "The log(" << Lo << ") is " << Log(Lo) << endl;
}

int root(double num)
{
    int i = 1;
    for( ; ; ++i)
    {
        if(i*i>num)
        {
            --i;
            break;
        }
    }

  return i;
}

/*
int sin(double x, double y)
{
    


    return (x/y);
}
*/


int Log(double n)
{
    return (n > 1) ? 1 + Log(n / 2) : 0;
}