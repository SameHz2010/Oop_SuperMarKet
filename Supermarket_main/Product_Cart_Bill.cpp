#include "../Class Headers/Product.h"
#include "../Class Headers/Bill.h"
#include "../Class Headers/Cart.h"
#include "../Class Headers/CartItem.h"

Product::Product()
{
     id = "";
     name = "";
     price = 0.0;
     quantity = 0;
}

void Product::in()
{
     cout << "Enter product ID: ";
     cin >> id;

     cout << "Enter product name: ";
     cin.ignore(); // Dọn sạch buffer để tránh lỗi khi nhập chuỗi
     getline(cin, name);

     cout << "Enter product price: ";
     cin >> price;

     cout << "Enter product quantity: ";
     cin >> quantity;
}

void Product::out() const
{
     cout << "ID: " << id << ", Name: " << name
          << ", Price: " << price << ", Quantity: " << quantity << endl;
}

bool Product::isAvailable() const
{
     return quantity > 0;
}

void Product::updateQuantity(int newQuantity)
{
     if (newQuantity >= 0)
     {
          quantity = newQuantity;
     }
     else
     {
          cout << "Quantity cannot be negative!" << endl;
     }
}

bool Product::reduceQuantity(int amount)
{
     if (quantity >= amount)
     {
          quantity -= amount;
          return true;
     }
     cout << "Not enough stock!" << endl; // Thông báo lỗi khi không đủ số lượng
     return false;
}

string Product::getId() const
{
     return id;
}

string Product::getName() const
{
     return name;
}

void Product::setName(const string &name)
{
     this->name = name;
}

void Product::setId(const string &id)
{
     this->id = id;
}

float Product::getPrice() const
{
     return price;
}

void Product::setPrice(float price)
{
     if (price >= 0)
     {
          this->price = price;
     }
     else
     {
          cout << "Price cannot be negative!" << endl;
     }
}

int Product::getQuantity() const
{
     return quantity;
}

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

Cart::Cart()
{
     customerId = "";
}

bool Cart::addProduct(const Product &product, int quantity)
{
     for (auto &item : items)
     {
          if (item.getProductId() == product.getId())
          {
               item.setQuantity(item.getQuantity() + quantity);
               return true;
          }
     }
     CartItem newItem;
     newItem = CartItem(product, quantity); // cần constructor tương ứng trong CartItem
     items.push_back(newItem);
     return true;
}

bool Cart::removeProduct(const string &productId)
{
     for (auto it = items.begin(); it != items.end(); ++it)
     {
          if (it->getProductId() == productId)
          {
               items.erase(it);
               return true;
          }
     }
     return false;
}

bool Cart::updateProductQuantity(const string &productId, int newQuantity)
{
     for (auto &item : items)
     {
          if (item.getProductId() == productId)
          {
               item.setQuantity(newQuantity);
               return true;
          }
     }
     return false;
}

void Cart::out() const
{
     cout << "Cart for customer ID: " << customerId << endl;
     for (const auto &item : items)
     {
          item.out();
     }
     cout << "Total: " << getTotal() << endl;
}

float Cart::getTotal() const
{
     float total = 0.0;
     for (const auto &item : items)
     {
          total += item.getSubtotal();
     }
     return total;
}

void Cart::clear()
{
     items.clear();
}

const vector<CartItem> &Cart::getItems() const
{
     return items;
}

string Cart::getCustomerId() const
{
     return customerId;
}

void Cart::setCustomerId(const string &id)
{
     customerId = id;
}

bool Cart::isEmpty() const
{
     return items.empty();
}

CartItem::CartItem()
{
     quantity = 0;
}

CartItem::CartItem(const Product &product, int quantity)
{
     this->product = product;
     this->quantity = quantity;
}

void CartItem::out() const
{
     product.out();
     cout << "Quantity in cart: " << quantity << endl;
     cout << "Subtotal: " << getSubtotal() << endl;
}

float CartItem::getSubtotal() const
{
     return product.getPrice() * quantity;
}

const Product &CartItem::getProduct() const
{
     return product;
}

int CartItem::getQuantity() const
{
     return quantity;
}

void CartItem::setQuantity(int quantity)
{
     this->quantity = quantity;
}

string CartItem::getProductId() const
{
     return product.getId();
}