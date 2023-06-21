/*
Sablonine klase turi tik antraste, kurioje yra visas kodas.
Implementacija imanoma iskelti i atskira faila (paprastai .ipp ar .tpp), bet mums to nereikia
*/

#ifndef POINT_H
#define POINT_H
#include <iostream>

template <typename T >
//template < typename T = int>   //nustatytas default tipas
class Point
{

    friend std::ostream &operator<< (std::ostream &output, const Point &P)
    {
        output << P.x << " " << P.y;
        return output;
    };

    public:
        //x yr y koordinate
        T x;
        T y;

        //konstruktoriai ir destruktorius
        Point(): x(0), y(0)  {};
        Point(T x_input, T y_input) : x(x_input), y(y_input)  {};
        virtual ~Point() {};

        //Palyginimo operatoriai
        bool operator==(const Point &P) const
        {
            return x == P.x && y == P.y;
        }
        bool operator!=(const Point &P) const
        {
            return !(*this == P);
        }

        //Sumavimo operatoriai. Jie nera taip standartiskai apibrezti, bet tokie apibrezimai
        //naturalus ir todel galime naudoti
        Point operator+(const Point &P) const
        {
            Point temp;
            temp.x = x + P.x;
            temp.y = y + P.y;
            return temp;
        }

        template <typename D>
        Point operator+( const D &n) const
        {
            Point temp = *this;
            temp.x += n;
            temp.y += n;
            return temp;
        }

        //Skirtumo operatoriai.
        Point operator++(int)
        {
            Point temp = *this;
            x++;
            y++;
            return temp;
        }

        Point operator-(const Point &P) const
        {
            Point temp;
            temp.x = x - P.x;
            temp.y = y - P.y;
            return temp;
        }

        template <typename D>
        Point operator-( const D &n) const
        {
            Point temp = *this;
            temp.x -= n;
            temp.y -= n;
            return temp;
        }


        Point operator--(int)
        {
            Point temp = *this;
            x--;
            y--;
            return temp;
        }

        //Galetume apibrezti daugiau operatoriu, pvz, daugyba is skaiciaus
        /*
        template <typename D>
        friend Point operator*( const D &n, Point P)
        {
            P.x *= n;
            P.y *= n;
            return P;
        };
        */

    protected:
    private:
};

#endif // POINT_H
