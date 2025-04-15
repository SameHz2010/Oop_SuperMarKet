#include "../Class Headers/Bill.h"

Bill::Bill()
    : invoiceId(""),
      customerId(""),
      employeeId(""),
      subtotal(0.0f),
      discount(0.0f),
      tax(0.0f),
      total(0.0f),
      date(""),
      paymentMethod("Cash") {}

void Bill::out() const
{
    cout << "\n===================================\n";
    cout << "             INVOICE\n";
    cout << "===================================\n";
    cout << "Invoice ID     : " << invoiceId << "\n";
    cout << "Date           : " << date << "\n";
    cout << "Customer ID    : " << customerId << "\n";
    cout << "Employee ID    : " << employeeId << "\n";
    cout << "Payment Method : " << paymentMethod << "\n";
    cout << "-----------------------------------\n";
    cout << "Items:\n";
    cout << left << setw(5) << "ID"
         << setw(30) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(10) << "Total" << "\n";

    for (const auto &item : items)
    {
        float price = item.getProduct().getPrice();
        int qty = item.getQuantity();
        float total = price * qty;

        cout << left << setw(5) << item.getProduct().getId()
             << setw(30) << item.getProduct().getName()
             << setw(10) << fixed << setprecision(2) << price
             << setw(8) << qty
             << setw(10) << fixed << setprecision(2) << total << "\n";
    }

    cout << "-----------------------------------\n";
    cout << left << setw(40) << "Subtotal:"
         << right << setw(10) << fixed << setprecision(2) << subtotal << "\n";
    cout << left << setw(40) << "Discount:"
         << right << setw(10) << fixed << setprecision(2) << discount << "\n";
    cout << left << setw(40) << "Tax (10%):"
         << right << setw(10) << fixed << setprecision(2) << tax << "\n";
    cout << left << setw(40) << "Total:"
         << right << setw(10) << fixed << setprecision(2) << total << "\n";
    cout << "===================================\n";
    cout << "   Thank you for your purchase!\n";
    cout << "===================================\n";
}

void Bill::generateInvoice(const Cart &cart, float discountRate, const string &empId)
{
    // Timestamp-based invoice ID
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    ostringstream oss;
    oss << "INV-" << put_time(ltm, "%Y%m%d-%H%M%S");
    invoiceId = oss.str();

    ostringstream dateStream;
    dateStream << put_time(ltm, "%d/%m/%Y %H:%M:%S");
    date = dateStream.str();

    // Set IDs
    employeeId = empId;
    customerId = cart.getCustomerId();

    // Copy cart items
    items = cart.getItems();

    // Financial calculation
    subtotal = 0.0f;
    for (const auto &item : items)
        subtotal += item.getProduct().getPrice() * item.getQuantity();

    discount = subtotal * discountRate;
    tax = (subtotal - discount) * 0.1f; // 10% VAT
    total = subtotal - discount + tax;
}

// === Getter Methods ===
string Bill::getInvoiceId() const { return invoiceId; }
string Bill::getCustomerId() const { return customerId; }
string Bill::getEmployeeId() const { return employeeId; }
const vector<CartItem> &Bill::getItems() const { return items; }
float Bill::getSubtotal() const { return subtotal; }
float Bill::getDiscount() const { return discount; }
float Bill::getTax() const { return tax; }
float Bill::getTotal() const { return total; }
string Bill::getDate() const { return date; }
string Bill::getPaymentMethod() const { return paymentMethod; }

void Bill::setPaymentMethod(const string &method)
{
    paymentMethod = method;
}