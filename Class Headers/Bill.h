#ifndef BILL_H
#define BILL_H

#include "Cart.h"

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

#endif
