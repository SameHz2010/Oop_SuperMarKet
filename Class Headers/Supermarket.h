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
    vector<Customer> customers;
    vector<Employee> employees;
    vector<Bill> bills;
    map<string, Cart> activeCarts;

    string generateId(const string &prefix);
    int findProductIndex(const string &id);
    // int findCustomerIndex(const string &id);
    // int findEmployeeIndex(const string &id);
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

    void addCustomer(vector<Customer> &customers);
    void editCustomer(vector<Customer> &customers);
    void deleteCustomer(vector<Customer> &customers);
    void displayCustomers(const vector<Customer> &customers);
    void searchCustomer(const vector<Customer> &customers);

    void addEmployee(vector<Employee> &employees);
    void editEmployee(vector<Employee> &employees);
    void deleteEmployee(vector<Employee> &employees);
    void displayEmployees(const vector<Employee> &employees);
    void searchEmployee(const vector<Employee> &employees);
    void promoteEmployee(vector<Employee> &employees);

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
