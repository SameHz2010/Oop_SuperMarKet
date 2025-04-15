#include "Cart.h"
#include <iostream>

void Cart::addProduct(const Product& product) {
    products.push_back(product);
}

void Cart::removeProduct(const std::string& productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            products.erase(it);
            return;
        }
    }
}

void Cart::displayCart() const {
    if (products.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }

    for (const auto& product : products) {
        product.display();
        std::cout << "\n";
    }
}

double Cart::calculateTotal() const {
    double total = 0;
    for (const auto& product : products) {
        total += product.getPrice() * product.getQuantity();
    }
    return total;
}

void Cart::clearCart() {
    products.clear();
}
