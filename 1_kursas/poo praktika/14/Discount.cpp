#include "Discount.h"

double Fixed::getDiscount(const Cart& cart)
	{
		double price = cart.cartPrice();
		if (price >= threshold)
		{
			price -= discount;
		}
		return price;
		
	}

double  Procentage::getDiscount(const Cart& cart)
{
    double price = cart.cartPrice();
		if (price >= threshold)
		{
			price = price * (100 - discount) / 100;
		}
        return price;
}