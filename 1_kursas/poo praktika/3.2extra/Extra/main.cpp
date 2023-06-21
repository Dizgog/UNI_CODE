#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Triangle.hpp"
#include "Point.hpp"

using namespace std;

int main()
{
    Point A(0,0), B(1,0), C(0, 1), D(1,1);
    Triangle trik(A, B, C);
    cout << "trik pries keiciant:  " << trik.toString() <<endl;

    bool set = false;
    while (!set)
    {
        try
        {
            Point P;
            cout << "Iveskite naujas A koordinates: " << endl;
            cin >> P.x >> P.y;
            trik.setA(P);
            set = true;
        }
        catch (invalid_argument &error)
        {
            cerr << "Klaida keiciant taska A: " << error.what() << endl;
        }
    }

    cout << "trik po pakeitimo:  " << trik.toString() <<endl <<endl;


    //Kai kurios std klases meta isimtis. Paziurekime out_of_range isimti vektoriams
    vector<Triangle> trikVec = {trik};
    cout << "Spausdinam neegzistuojanti elementa trikVec[1]: " << trikVec[1].toString() << endl;  //
    //cout << "Spausdinam elementa trikVec.at(1): " << trikVec.at(1).toString() << endl;  //programa nustoja dirbti
    try
    {
        cout << "trikVec: " << trikVec.at(1).toString() << endl;
    }
    catch (out_of_range &error)
    {
        cerr << "Klaida Bandant pasiekti trikVec.at(1): " << error.what() << endl;
    }

}
