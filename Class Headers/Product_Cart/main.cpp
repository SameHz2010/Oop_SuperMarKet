#include "Product.h"
#include "CartItem.h"
#include "Cart.h"
#include <iostream>
using namespace std;

int main() {
    // Tạo một số sản phẩm
    Product p1;
    p1.setId("1");
    p1.setName("Apple");
    p1.setPrice(10.5);
    p1.updateQuantity(100);

    Product p2;
    p2.setId("2");
    p2.setName("Banana");
    p2.setPrice(5.0);
    p2.updateQuantity(50);

    // Tạo giỏ hàng
    Cart cart;
    cart.setCustomerId("KH001");

    // Thêm sản phẩm vào giỏ
    cart.addProduct(p1, 2);
    cart.addProduct(p2, 3);

    // In thông tin giỏ hàng
    cart.out();
    // Cập nhật số lượng
    cart.updateProductQuantity(p1.getId(), 5);
    cout << "Sau khi cap nhat so luong Apple:\n";
    cart.out();

    // Xóa sản phẩm
    cart.removeProduct(p2.getId());
    cout << "\nSau khi xoa Banana:\n";
    cart.out();

    return 0;
}
