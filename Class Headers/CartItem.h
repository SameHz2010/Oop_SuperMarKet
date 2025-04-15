#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem();
    CartItem(const Product &product, int quantity);

    void out() const;
    float getSubtotal() const;

    const Product &getProduct() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    string getProductId() const;
};

#endif
