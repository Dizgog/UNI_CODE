#ifndef _SHOP_
#define _sHOP_
#include "Discount.h"

class Shop{
private:
    std::vector<Product> catalogue;
	Discount* discount;

public:
    
    void setProduct(std::vector<Product>&);
    void setDiscount(Discount* discount);

    void addProduct(Product&);

    double finPrice(Cart&);

    Product& getCatalog(int i);
};

#endif