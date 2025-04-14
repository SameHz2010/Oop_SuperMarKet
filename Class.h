#ifndef SUPERMARKET_CLASSES_H
#define SUPERMARKET_CLASSES_H

#include <bits/stdc++.h>

using namespace std;

class Person
{
protected:
    string id;
    string name;
    string phone;

public:
    Person() {}

    virtual ~Person() {}

    virtual void in() = 0;
    virtual void out() const = 0;

    string getId() const;
    string getName() const;
    void setName(const string &name);
    string getPhone() const { return phone; }
    void setPhone(const string &phone);
};

// Lớp Customer kế thừa từ Person
class Customer : public Person
{
private:
    string memberType; // Loại thành viên: "Regular", "Silver", "Gold", "Platinum"
    int loyaltyPoints;

public:
    Customer();

    void in() override;
    void out() const override;

    float getDiscountRate() const;
    void addLoyaltyPoints(int points);
    void resetLoyaltyPoints();

    string getMemberType() const;
    void setMemberType(const string &type);
    int getLoyaltyPoints() const;
};

// Lớp Employee kế thừa từ Person
class Employee : public Person
{
private:
    string position;
    float salary;
    string dateHired;

public:
    Employee() : salary(0.0) {}

    void in() override;
    void out() const override;

    // Các phương thức riêng của Employee
    void updateSalary(float newSalary);
    void promote(const string &newPosition);

    // Getter & Setter
    string getPosition() const;
    void setPosition(const string &pos);
    float getSalary() const;
    string getDateHired() const;
};

// Lớp Product
class Product
{
private:
    string id;
    string name;
    float price;
    int quantity;

public:
    Product() : price(0.0), quantity(0) {}

    void in();
    void out() const;

    // Các phương thức riêng của Product
    bool isAvailable() const;
    void updateQuantity(int newQuantity);
    bool reduceQuantity(int amount);

    // Getter & Setter
    string getId() const;
    string getName() const;
    void setName(const string &name);
    float getPrice() const;
    void setPrice(float price);
    int getQuantity() const;
};

// Lớp CartItem để lưu trữ thông tin sản phẩm trong giỏ hàng
class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem();

    void out() const;
    float getSubtotal() const;

    // Getter & Setter
    const Product &getProduct() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    string getProductId() const;
};

// Lớp Cart
class Cart
{
private:
    vector<CartItem> items;
    string customerId;

public:
    Cart() {}

    // Các phương thức của Cart
    bool addProduct(const Product &product, int quantity);
    bool removeProduct(const string &productId);
    bool updateProductQuantity(const string &productId, int newQuantity);
    void out() const;
    float getTotal() const;
    void clear();

    // Getter & Setter
    const vector<CartItem> &getItems() const;
    string getCustomerId() const;
    void setCustomerId(const string &id);
    bool isEmpty() const;
};

// Lớp Bill
class Bill
{
private:
    string invoiceId;
    string customerId;
    string employeeId;
    vector<CartItem> items;
    float subtotal;
    float discount;
    float tax;
    float total;
    string date;
    string paymentMethod;

public:
    Bill();

    void out() const;
    void generateInvoice(const Cart &cart, float discountRate, const string &empId);

    string getInvoiceId() const;
    string getCustomerId() const;
    string getEmployeeId() const;
    const vector<CartItem> &getItems() const;
    float getSubtotal() const;
    float getDiscount() const;
    float getTax() const;
    float getTotal() const;
    string getDate() const;
    string getPaymentMethod() const;
    void setPaymentMethod(const string &method);
};

// Lớp Supermarket - lớp điều phối tổng
class Supermarket
{
private:
    vector<Product> inventory;
    vector<Customer> customers;
    vector<Employee> employees;
    vector<Bill> bills;
    map<string, Cart> activeCarts; // carts mapped by customer ID

    // Phương thức helper
    string generateId(const string &prefix);
    int findProductIndex(const string &id);
    int findCustomerIndex(const string &id);
    int findEmployeeIndex(const string &id);
    int findBillIndex(const string &id);

public:
    Supermarket();

    // Phương thức quản lý sản phẩm
    void addProduct();
    void editProduct();
    void removeProduct();
    void outProducts() const;
    void searchProductById();
    void searchProductByName();
    void updateProductQuantity();

    // Phương thức quản lý khách hàng
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void outCustomers() const;
    void searchCustomerById();
    void searchCustomerByName();

    // Phương thức quản lý nhân viên
    void addEmployee();
    void editEmployee();
    void removeEmployee();
    void outEmployees() const;
    void searchEmployeeById();
    void searchEmployeeByName();

    // Phương thức quản lý giỏ hàng
    void createCart();
    void addToCart();
    void removeFromCart();
    void updateCartItemQuantity();
    void outCart();
    void clearCart();

    // Phương thức quản lý hóa đơn
    void createBill();
    void outBill();
    void searchBillById();
    void searchBillsByCustomer();
    void searchBillsByDate();
    void generateSalesReport();
};

#endif // SUPERMARKET_CLASSES_H