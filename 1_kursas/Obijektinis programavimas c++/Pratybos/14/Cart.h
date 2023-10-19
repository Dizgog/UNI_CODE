#ifndef _CART_
#define _CART_
#include "Product.h"
#include <vector>

class Cart{
private:
    std::vector<Product> cart;
public:

    Cart()
	{}

    double cartPrice () const;
    void addItem(Product& product);
    void removeItem(int index);

    std :: vector<Product> getCart();
};

#endif