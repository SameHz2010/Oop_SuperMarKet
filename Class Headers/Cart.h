#ifndef CART_H
#define CART_H

#include "CartItem.h"

using namespace std;

class Cart
{
private:
    vector<CartItem> items;
    string customerId;

public:
    Cart();

    bool addProduct(const Product &product, int quantity);
    bool removeProduct(const string &productId);
    bool updateProductQuantity(const string &productId, int newQuantity);
    void out() const;
    float getTotal() const;
    void clear();

    const vector<CartItem> &getItems() const;
    string getCustomerId() const;
    void setCustomerId(const string &id);
    bool isEmpty() const;
};

#endif
