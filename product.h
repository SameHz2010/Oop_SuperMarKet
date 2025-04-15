#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string id;
    std::string name;
    double price;
    int quantityInStock;

public:
    Product();
    Product(std::string id, std::string name, double price, int quantity);
    void setQuantity(int quantity);
    void setPrice(double price);

    std::string getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void display() const;
};

#endif
