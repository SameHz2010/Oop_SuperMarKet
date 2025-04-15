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
     cin.ignore();
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
     cout << "Not enough stock!" << endl;
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
