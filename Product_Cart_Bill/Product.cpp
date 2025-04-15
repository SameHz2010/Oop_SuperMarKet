#include "../Class Headers/Product.h"

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
