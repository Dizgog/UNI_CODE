#include <string>

#ifndef TRIANGLE_H
#define TRIANGLE_H


//Pagalvine struktura taskui
//Pastaba: Sukurta negraziai. Turetu buti atskira klase.
struct Point {
    //default constructor
    Point ()
     : x(0), y(0)   //member initialization list
    {
    }
    //normalus konstruktorius
    Point (float x, float y)
     : x(x), y(y)
    {
    }
    float x;
    float y;
};


class Triangle
{
    public:
        //konstruktorius
        Triangle(); //default constructor. Nelabai protingas, tokio nenaudokit!
        Triangle(Point, Point, Point);
        Triangle(Point, Point, float angle1 = 90, float angle2 = 45);   // Ne visai prasmingos default reiksmes
        //destruktorius
        virtual ~Triangle();
        //seteriai
        void setA(Point);
        void setB(Point);
        void setC(Point);
        //geteriai
        Point getA();
        Point getB();
        Point getC();
        float getAB();
        float getAC();
        float getBC();
        //Darbas su trikampiu
        bool isRight();
        void scale (float = 2);  //istempti pagal koordinaciu pradzia
        void scale (float factor, Point scalePoint);  //istempti pagal taska scalePoint
        std::string toString();
    protected:
    private:
        //trikampio koordinates
        Point A;
        Point B;
        Point C;
        //atstumai tarp tasku
        float AB, AC, BC;
        //atstumu seteriai
        void setAB();
        void setAC();
        void setBC();
        //privatus darbiniai worker metodai
        float d(Point, Point);  //grazina atstuma
        float ds(Point, Point); //grazina atstuma pakleta kvadratu
};

#endif // TRIANGLE_H
