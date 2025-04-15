#include "CartItem.h"
#include <iostream>
using namespace std;

CartItem::CartItem() {
    quantity = 0;
}

CartItem::CartItem(const Product &product, int quantity) {
    this->product = product;
    this->quantity = quantity;
}

void CartItem::out() const {
    product.out();
    cout << "Quantity in cart: " << quantity << endl;
    cout << "Subtotal: " << getSubtotal() << endl;
}

float CartItem::getSubtotal() const {
    return product.getPrice() * quantity;
}

const Product &CartItem::getProduct() const {
    return product;
}

int CartItem::getQuantity() const {
    return quantity;
}

void CartItem::setQuantity(int quantity) {
    this->quantity = quantity;
}

string CartItem::getProductId() const {
    return product.getId();
}
