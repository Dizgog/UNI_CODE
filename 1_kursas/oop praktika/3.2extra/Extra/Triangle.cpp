#include <iostream>
#define M_PI           3.14159265358979323846
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Triangle.hpp"

using namespace std;

Triangle::Triangle()
//member initialization list - 1 budas priskirti reiksmes laukams
//Ps. Tokio dedault konstr neturetu buti, tai tik pvz
 : A(0,0),
   B(1,0),
   C(0,1),
   AB(1), AC(1), BC(sqrt(2))

{
}

Triangle::Triangle(Point A, Point B, Point C)
{
    this -> A = A;  //priskyrias konstruktoriuje - 2 budas priskirti reiksmes laukams
    if ((B.x == A.x) && (B.y == A.y))
        cout << "Netinkamas taskas B" << endl;
    else
    {
        this -> B = B;
        if ( ((C.x == A.x) && (C.y == A.y)) || ((C.x == B.x) && (C.y == B.y)) )
            cout << "Netinkamas taskas C" << endl;
        else
        {
            this -> C = C;
            setAB();  //kreipimasis i setteri - 3 budas priskirti reiksmes laukams
            setAC();
            setBC();
        }

    }
}


Triangle::Triangle(Point A, Point B, float angle1, float angle2)
{
    if ((B.x == A.x) && (B.y == A.y))
        cout << "Netinkamas taskas B" << endl;
    else if ( (angle1 <= 0) || (angle2 <= 0) || (angle1 + angle2 >= 180) )
        cout << "Netinkami kampai" << endl;
    else
    {
        this -> A = A;
        this -> B = B;
        angle1 *= (M_PI/180);
        angle2 *= (M_PI/180);
        float u=B.x-A.x;
        float v=B.y-A.y;
        float a3=d(A,B);
        float angle3=M_PI-angle1-angle2;
        float a2 = a3*sin(angle2)/sin(angle3);
        float RHS1 = A.x*u+A.y*v+a2*a3*cos(angle1);
        float RHS2 = B.y*u-B.x*v-a2*a3*sin(angle1);
        C.x = pow(a3,-2)*(u*RHS1-v*RHS2);
        C.y = pow(a3,-2)*(v*RHS1+u*RHS2);
        setAB();
        setAC();
        setBC();
    }
}


Triangle::~Triangle()
{
    //dtor
}

void Triangle::setA(Point A)
{

    //Senas budas: anksciau naudojome spausdinima
    /*
    if ( ((A.x == B.x) && (A.y == B.y)) || ((A.x == C.x) && (A.y == C.y)) )
        cout << "Netinkamas taskas A" << endl;
    else {..}
    */

    //Negrazus nenaudotinas budas: mesti bet ka, pvz skaiciu
    /*
    if ( ((A.x == B.x) && (A.y == B.y)) || ((A.x == C.x) && (A.y == C.y)) )
        throw 1;
    else {..}
    */

    if ((A.x == B.x) && (A.y == B.y))
        throw invalid_argument("Taskas A negali buti lygus B.");
    else if ((A.x == C.x) && (A.y == C.y))
        throw invalid_argument("Taskas A negali buti lygus C.");
    else
    {
        this -> A = A;
        setAB();
        setAC();
    }

}

void Triangle::setB(Point B)
{
    if ( ((B.x == A.x) && (B.y == A.y)) || ((B.x == C.x) && (B.y == C.y)) )
        cout << "Netinkamas taskas B" << endl;
    else
    {
        this -> B = B;
        setAB();
        setBC();
    }
}

void Triangle::setC(Point C)
{
    if ( ((C.x == B.x) && (C.y == B.y)) || ((C.x == A.x) && (C.y == A.y)) )
        cout << "Netinkamas taskas C" << endl;
    else
    {
        this -> C = C;
        setAC();
        setBC();
    }
}

void Triangle::setAB()
{
    AB = d(A, B);
}

void Triangle::setAC()
{
    AC = d(A, C);
}

void Triangle::setBC()
{
    BC = d(B, C);
}


Point Triangle::getA()
{
    return A;
}

Point Triangle::getB()
{
    return B;
}

Point Triangle::getC()
{
    return C;
}

float Triangle::getAB()
{
    return AB;
}

float Triangle::getAC()
{
    return AC;
}

float Triangle::getBC()
{
    return BC;
}

float Triangle::d(Point P1, Point P2)
{
    return sqrt(pow(P1.x - P2.x, 2)+pow(P1.y - P2.y, 2));
}

float Triangle::ds(Point P1, Point P2)
{
    return pow(P1.x - P2.x, 2)+pow(P1.y - P2.y, 2);
}

bool Triangle::isRight()
{
    return (ds(A,B) == ds(A,C) + ds(C,B)) ||
        (ds(A,C) == ds(A,B) + ds(C,B)) ||
        (ds(C,B) == ds(A,B) + ds(A,C));
}

void Triangle::scale(float factor)
{
    if (factor == 0)
        cout << "Negalima skeilinti 0 kartu, nes sugadinamas trikampis" << endl;
    else
    {
        A.x *= factor;
        A.y *= factor;
        B.x *= factor;
        B.y *= factor;
        C.x *= factor;
        C.y *= factor;
        setAB();
        setAC();
        setBC();
        //alternatyviai
        //Point scalePoint(0,0);
        //scale(factor, scalePoint);
    }
}

void Triangle::scale(float factor, Point scalePoint)
{
    if (factor == 0)
        cout << "Negalima skeilinti 0 kartu, nes sugadinamas trikampis" << endl;
    else
    {
        A.x = factor * (A.x - scalePoint.x) + scalePoint.x;
        A.y = factor * (A.y - scalePoint.y) + scalePoint.y;
        B.x = factor * (B.x - scalePoint.x) + scalePoint.x;
        B.y = factor * (B.y - scalePoint.y) + scalePoint.y;
        C.x = factor * (C.x - scalePoint.x) + scalePoint.x;
        C.y = factor * (C.y - scalePoint.y) + scalePoint.y;
        setAB();
        setAC();
        setBC();
    }
}

string Triangle::toString()
{
    stringstream buffer;
    buffer << "A: " << A.x << " " << A.y;
    buffer << " B: " << B.x << " " << B.y;
    buffer << " C: " << C.x << " " << C.y;
    buffer << " ilgiai: " << AB << " " << AC << " " << BC;
    return buffer.str();
}
