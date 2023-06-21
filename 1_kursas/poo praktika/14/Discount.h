#ifndef _DISCOUNT_
#define _DISCOUNT_
#include "cart.h"

class Discount{
private:

public:
    virtual double getDiscount(const Cart& cart) = 0;

};

class Fixed: public Discount{
private:
    double threshold;
    double discount;
public:
Fixed(double threshold=0, double discountMoney=0)
		:threshold(threshold), discount(discountMoney)
	{}
    double getDiscount(const Cart& cart) override;

};

class Procentage: public Discount{
private:
double threshold;
	double discount;
public:
Procentage(double threshold=0, double discountMoney=0)
		:threshold(threshold), discount(discountMoney)
	{}
    double getDiscount(const Cart& cart) override;
};

#endif