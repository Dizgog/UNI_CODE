#ifndef _PRODUCT_
#define _PRODUCT_
#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>

class Product{
private:
    std::string name;
    double price;
    std::string category;

public:

    Product(std::string name = "", double price = 0.0, std::string category = "")
        :name(name), price(price), category(category)
    {}
    void setName(std::string);
    void setPrice(double);
    void setCategory(std::string);

    std::string getName();
    double getPrice();
    std::string getCategory();
};

#endif