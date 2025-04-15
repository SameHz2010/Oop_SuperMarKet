#include "../Class Headers/Product.h"
#include <iostream>

Product::Product()
{
    id = "";
    name = "";
    price = 0.0;
    quantity = 0;
}

void Product::in()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity: " << quantity << endl;
}

void Product::out() const
{
    cout << "ID: " << id << ", Name: " << name << "Price: "
         << price << "Quantity: " << quantity << endl;
}

bool Product::isAvailable() const
{
    return quantity > 0;
}

void Product::updateQuantity(int newQuantity)
{
    quantity = newQuantity;
}

bool Product::reduceQuantity(int amount)
{
    if (quantity >= amount)
    {
        quantity = quantity - amount;
        return true;
    }
    return false;
}

string Product::getId() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

void Product::setName(const string &name)
{
    this->name = name;
}

void Product::setId(const string &id)
{
    this->id = id;
}

float Product::getPrice() const
{
    return price;
}

void Product::setPrice(float price)
{
    this->price = price;
}

int Product::getQuantity() const
{
    return quantity;
}