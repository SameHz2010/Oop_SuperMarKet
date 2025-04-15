#include "Product.h"
#include <iostream>

Product::Product() : id(""), name(""), price(0), quantityInStock(0) {}

Product::Product(std::string id, std::string name, double price, int quantity)
    : id(id), name(name), price(price), quantityInStock(quantity) {}

void Product::setQuantity(int quantity) {
    quantityInStock = quantity;
}

void Product::setPrice(double price) {
    this->price = price;
}

std::string Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantityInStock;
}

void Product::display() const {
    std::cout << "Product ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Price: " << price << "\n"
              << "Stock: " << quantityInStock << "\n";
}
