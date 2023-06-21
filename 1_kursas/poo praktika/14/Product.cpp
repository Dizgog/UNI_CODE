#include "Product.h"

void Product::setName(std::string name)
{
    this -> name = name;
}
void Product::setPrice(double price)
{
    this -> price = price;
}
void Product::setCategory(std::string category)
{
    this -> category = category;
}

std::string Product::getName()
{
    return name;
}
double Product::getPrice()
{
    return price;
}
std::string Product::getCategory()
{
    return category;
}