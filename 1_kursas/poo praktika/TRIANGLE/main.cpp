/*
Author: Rokas Astrauskas, VU MIF
Programa skirta:
   Susipazinti su didesnes apimties klase Triangle, turincia daugiau lauku, keleta konstrokturiu,
visus setterius ir getterius
   Pavyzdziai perkrautu (overload'intu) metodu, default reiksmiu metoduose
   Default konstruktorius - konstruktorius be argumentu
   Reiksmiu priskyrimas su member initialization list
*/

#include <iostream>
#include <string>
#include "Triangle.hpp"

using namespace std;

int main()
{
    Point A(0,0), B(1,0), C(0, 1), D(1,1);
    Triangle trik(A, B, C);
    cout << "trik:  " << trik.toString() <<endl;
    trik.setA(A);
    //cout << std::fixed;
    cout << "krastiniu ilgiai: " << trik.getAB() << " " << trik.getAC() << " " << trik.getBC() <<endl;
    if (trik.isRight())
        cout << "Trikampis statusis" << endl;
    else
        cout << "Trikampis nera statusis" << endl;

    Triangle newTrik(A, B, 90, 45);
    cout << "\nSukuriamas trikampis per 2 taskus ir 2 kampus:" << endl;
    cout << newTrik.toString() << endl;

    newTrik.scale(2);
    cout << "\nTrikampis istempiamas 2 kartus:" << endl;
    cout << newTrik.toString() << endl;

    Triangle emptyTrik;
    cout << "\nSukurtas default trikampis:" << endl;
    cout << emptyTrik.toString() << endl;
}
