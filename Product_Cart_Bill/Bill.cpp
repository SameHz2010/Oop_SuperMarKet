#include "../Class Headers/Bill.h"

using namespace std;

Bill::Bill()
{
     invoiceId = "";
     customerId = "";
     subtotal = 0.0f;
     discount = 0.0f;
     tax = 0.0f;
     total = 0.0f;
     date = "";
     paymentMethod = "Cash"; // Default payment method
}

void Bill::generateInvoice(const Cart &cart, float discountRate, const string &employeeId)
{
     items = cart.getItems();
     customerId = cart.getCustomerId();

     invoiceId = "INV" + to_string(rand() % 100000);

     time_t now = time(0);
     tm *ltm = localtime(&now);
     char buffer[20];
     strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", ltm);
     date = string(buffer);

     subtotal = cart.getTotal();
     discount = subtotal * discountRate;
     tax = (subtotal - discount) * 0.1f; // Thuế 10%
     total = subtotal - discount + tax;

     this->employeeId = employeeId;
}

void Bill::out() const
{
     cout << "========== INVOICE ==========" << endl;
     cout << "Invoice ID      : " << invoiceId << endl;
     cout << "Customer ID     : " << customerId << endl;
     cout << "Date            : " << date << endl;
     cout << "Payment Method  : " << paymentMethod << endl;
     cout << "-----------------------------" << endl;

     cout << left << setw(15) << "Product ID"
          << setw(10) << "Qty"
          << setw(10) << "Price"
          << setw(10) << "Subtotal" << endl;

     for (const auto &item : items)
     {
          cout << left << setw(15) << item.getProductId()
               << setw(10) << item.getQuantity()
               << setw(10) << fixed << setprecision(2) << item.getProduct().getPrice()
               << setw(10) << item.getSubtotal() << endl;
     }

     cout << "-----------------------------" << endl;
     cout << "Subtotal        : " << fixed << setprecision(2) << subtotal << endl;
     cout << "Discount        : " << discount << endl;
     cout << "Tax (10%)       : " << tax << endl;
     cout << "Total           : " << total << endl;
     cout << "=============================" << endl;
}

// Getters
string Bill::getInvoiceId() const
{
     return invoiceId;
}

string Bill::getCustomerId() const
{
     return customerId;
}

const vector<CartItem> &Bill::getItems() const
{
     return items;
}

float Bill::getSubtotal() const
{
     return subtotal;
}

float Bill::getDiscount() const
{
     return discount;
}

float Bill::getTax() const
{
     return tax;
}

float Bill::getTotal() const
{
     return total;
}

string Bill::getDate() const
{
     return date;
}

string Bill::getPaymentMethod() const
{
     return paymentMethod;
}

// Setter
void Bill::setPaymentMethod(const string &method)
{
     paymentMethod = method;
}