#include "Cart.h"
#include <iostream>

Cart::Cart() {
    customerId = "";
}

bool Cart::addProduct(const Product &product, int quantity) {
    for (auto &item : items) {
        if (item.getProductId() == product.getId()) {
            item.setQuantity(item.getQuantity() + quantity);
            return true;
        }
    }
    CartItem newItem;
    newItem = CartItem(product, quantity); // cần constructor tương ứng trong CartItem
    items.push_back(newItem);
    return true;
}

bool Cart::removeProduct(const string &productId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getProductId() == productId) {
            items.erase(it);
            return true;
        }
    }
    return false;
}

bool Cart::updateProductQuantity(const string &productId, int newQuantity) {
    for (auto &item : items) {
        if (item.getProductId() == productId) {
            item.setQuantity(newQuantity);
            return true;
        }
    }
    return false;
}

void Cart::out() const {
    cout << "Cart for customer ID: " << customerId << endl;
    for (const auto &item : items) {
        item.out();
    }
    cout << "Total: " << getTotal() << endl;
}

float Cart::getTotal() const {
    float total = 0.0;
    for (const auto &item : items) {
        total += item.getSubtotal();
    }
    return total;
}

void Cart::clear() {
    items.clear();
}

const vector<CartItem> &Cart::getItems() const {
    return items;
}

string Cart::getCustomerId() const {
    return customerId;
}

void Cart::setCustomerId(const string &id) {
    customerId = id;
}

bool Cart::isEmpty() const {
    return items.empty();
}
