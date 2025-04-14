#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "Customer.h"
#include "Employee.h"
#include "Product.h"
#include "Cart.h"
#include "Bill.h"
#include <map>
#include <vector>

class Supermarket
{
private:
    vector<Product> inventory;
    vector<Customer> customers;
    vector<Employee> employees;
    vector<Bill> bills;
    map<string, Cart> activeCarts;

    string generateId(const string &prefix);
    int findProductIndex(const string &id);
    int findCustomerIndex(const string &id);
    int findEmployeeIndex(const string &id);
    int findBillIndex(const string &id);

public:
    Supermarket();

    void addProduct();
    void editProduct();
    void removeProduct();
    void outProducts() const;
    void searchProductById();
    void searchProductByName();
    void updateProductQuantity();

    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void outCustomers() const;
    void searchCustomerById();
    void searchCustomerByName();

    void addEmployee();
    void editEmployee();
    void removeEmployee();
    void outEmployees() const;
    void searchEmployeeById();
    void searchEmployeeByName();

    void createCart();
    void addToCart();
    void removeFromCart();
    void updateCartItemQuantity();
    void outCart();
    void clearCart();

    void createBill();
    void outBill();
    void searchBillById();
    void searchBillsByCustomer();
    void searchBillsByDate();
    void generateSalesReport();
};

#endif
