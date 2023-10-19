#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Point
{
    double x,y;
}   p;

void printPoint(struct Point p)
{
    printf("Set of coordinates:%9f %9f\n",p.x, p.y);
}

struct Point createPoint(double x, double y)
{
	p temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

double getDistance(struct Point p1,struct Point p2)
{
    double temp;
    temp=sqrt(pow((p2.x-p1.x),2)+pow(( p2.y-p1.y),2));
    printf("%lf", temp);
}

int main()
{
    getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));
    return 0;
}
