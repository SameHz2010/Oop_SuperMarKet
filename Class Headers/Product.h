#ifndef PRODUCT_H
#define PRODUCT_H

#include <bits/stdc++.h>

using namespace std;

class Product
{
private:
    string id;
    string name;
    float price;
    int quantity;

public:
    Product();

    void in();
    void out() const;
    bool isAvailable() const;
    void updateQuantity(int newQuantity);
    bool reduceQuantity(int amount);

    string getId() const;
    string getName() const;
    void setName(const string &name);
    void setId(const string &id);
    float getPrice() const;
    void setPrice(float price);
    int getQuantity() const;
};

#endif
