#include "shop.h"


    void Shop::setProduct(std::vector<Product>&catalogue)
    {
        this->catalogue = catalogue;
    }
    
    void Shop::setDiscount(Discount* discount)
    {
        this->discount = discount;
    }

    void Shop::addProduct(Product& pro)
    {
        catalogue.push_back(pro);
    }

    double Shop::finPrice(Cart& car)
    {
        return discount->getDiscount(car);
    }

    Product& Shop :: getCatalog(int i)
    {
    return catalogue[i];
    }