#include "Cart.h"

double Cart::cartPrice() const
	{
		double price = 0;
		price = std :: accumulate(cart.begin(), cart.end(), 0.0,[]( double i, Product a){return i + a.getPrice();});
		return price;
	}

void Cart::addItem(Product& product)
    {
        cart.push_back(product);
    }

void Cart::removeItem(int index)
    {
        cart.erase(cart.begin() + index);
    }

std :: vector<Product> Cart :: getCart()
{
    return cart;
}