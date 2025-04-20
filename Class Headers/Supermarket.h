#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "../Class Headers/Customer.h"
#include "../Class Headers/Employee.h"
#include "../Class Headers/Product.h"
#include "../Class Headers/Cart.h"
#include "../Class Headers/Bill.h"

class Supermarket
{
private:
    vector<Product> inventory;
    vector<Person *> people;
    vector<Bill> bills;
    map<string, Cart> activeCarts;

    int findProductIndex(const string &id);
    int findBillIndex(const string &id);

public:
    Supermarket();
    void pause();

    void addProduct();
    void editProduct();
    void removeProduct();
    void outProducts() const;
    void searchProductById();
    void searchProductByName();
    void updateProductQuantity();
    void readFileCsv_product();
    void writeFileCsv_product();

    void addCustomer();
    void editCustomer();
    void deleteCustomer();
    void displayCustomers();
    void searchCustomer();
    void readFileCsv_customer();
    void writeFileCsv_customer();

    void addEmployee();
    void editEmployee();
    void deleteEmployee();
    void displayEmployees();
    void searchEmployee();
    void promoteEmployee();
    void readFileCsv_employee();
    void writeFileCsv_employee();

    void createCart();
    void addToCart();
    void removeFromCart();
    void updateCartItemQuantity();
    void outCart();
    void clearCart();

    void createBill();
    void outBills() const;
    void searchBillById();
    void searchBillsByCustomerId();
    Product &getProductById(const string &productId);
    void payBill();
    void writeFileCsv_bill();

    void sortProducts();
    void sortCustomers();
    void sortEmployees();
    void sortData();

    void inMenu();
};

#endif
