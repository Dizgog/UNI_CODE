#include "Circle.h"

double Circle::area() const
{
    return pi*radius*radius;
}

double Circle::perimeter() const
{
    return 2*pi*radius;
}

void Circle::print() const
{
    std::cout << "Center coordinates of the circle: ";
    Shape::print();
    std::cout << "Radius of the circle: " << radius << std::endl;
}

void Circle::draw(SDL_Renderer * renderer) const
{
   const double diameter = (radius * 2);

   double x = (radius - 1);
   double y = 0;
   double tx = 1;
   double ty = 1;
   double error = (tx - diameter);
   
   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, position.x + x, position.y - y);
      SDL_RenderDrawPoint(renderer, position.x + x, position.y + y);
      SDL_RenderDrawPoint(renderer, position.x - x, position.y - y);
      SDL_RenderDrawPoint(renderer, position.x - x, position.y + y);
      SDL_RenderDrawPoint(renderer, position.x + y, position.y - x);
      SDL_RenderDrawPoint(renderer, position.x + y, position.y + x);
      SDL_RenderDrawPoint(renderer, position.x - y, position.y - x);
      SDL_RenderDrawPoint(renderer, position.x - y, position.y + x);
   
      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}