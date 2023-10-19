#include <iostream>
#include "Shop.h"
#include "Cart.h"
#include "Discount.h"
#include "Product.h"
int main()
{

   
    Shop shop;
   
    Product prod1("Soup", 2.99, "food");
    Product prod2("pistachios", 12.85, "food");
    Product prod3("Comicly large spoon", 2.55, "utensils");
    Product prod4("medieval sword", 2.28, "utensils");
    Product prod5("Fortnite", 3.74, "Games");
    Product prod6("Grand Theft Auto the fitfth", 4.45, "Games");
    

    shop.addProduct(prod1);
    shop.addProduct(prod2);
    shop.addProduct(prod3);
    shop.addProduct(prod4);
    shop.addProduct(prod5);
    shop.addProduct(prod6);

    Cart car;
    car.addItem(shop.getCatalog(0));
    car.addItem(shop.getCatalog(5));
    car.addItem(shop.getCatalog(2));
    car.addItem(shop.getCatalog(1));
    
    std :: cout << "The price of the basket without discounts : " << car.cartPrice() << std :: endl;
    
    Cart car2;
    car2.addItem(shop.getCatalog(1));
    car2.addItem(shop.getCatalog(2));
    car2.addItem(shop.getCatalog(4));
    car2.addItem(shop.getCatalog(6));
    std :: cout << "The price of the basket(2) without discounts : " << car2.cartPrice() << std :: endl;

    Cart car3;
    car3.addItem(shop.getCatalog(2));
    std :: cout << "The price of the basket(3) without discounts : " << car3.cartPrice() << std :: endl << std :: endl;

   Fixed * fixdis10 = new Fixed(10, 5);
 
    shop.setDiscount(fixdis10);
   
    std :: cout << "Price of the basket with fixed discount : " << shop.finPrice(car) << std :: endl;
    std :: cout << "Price of the basket(2) with fixed discount : " << shop.finPrice(car2) << std :: endl;
    std :: cout << "Price of the basket(3) with fixed discount : " << shop.finPrice(car3) << std :: endl << std :: endl;


    Procentage * ratDis15 = new Procentage(15, 50);

    shop.setDiscount(ratDis15);
    std :: cout << "Price of the basket with Ratiio discount : " << shop.finPrice(car) << std :: endl;
    std :: cout << "Price of the basket(2) with Ratio discount : " << shop.finPrice(car2) << std :: endl;
    std :: cout << "Price of the basket(3) with Ratio discount : " << shop.finPrice(car3) << std :: endl << std :: endl;

    delete fixdis10;
    delete ratDis15;
    return 0;
}