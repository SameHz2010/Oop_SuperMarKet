#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>

class Cart {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& productId);
    void displayCart() const;
    double calculateTotal() const;
    void clearCart();
};

#endif
