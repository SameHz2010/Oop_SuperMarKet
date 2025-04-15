#include "../Class Headers/Supermarket.h"

Supermarket::Supermarket() {}

string Supermarket::generateId(const string &prefix)
{
    // In this example, we are just generating an ID using a prefix and current size of vector as a simple approach.
    return prefix + to_string(inventory.size() + 1);
}

int Supermarket::findProductIndex(const string &id)
{
    for (int i = 0; i < inventory.size(); ++i)
    {
        if (inventory[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

void Supermarket::addProduct()
{
    Product newProduct;
    newProduct.in();
    inventory.push_back(newProduct);
    cout << "Product added successfully!" << endl;
}

void Supermarket::editProduct()
{
    string id;
    cout << "Enter product ID to edit: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index != -1)
    {
        inventory[index].in();
        cout << "Product updated successfully!" << endl;
    }
    else
    {
        cout << "Product not found!" << endl;
    }
}

void Supermarket::removeProduct()
{
    string id;
    cout << "Enter product ID to remove: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index != -1)
    {
        inventory.erase(inventory.begin() + index);
        cout << "Product removed successfully!" << endl;
    }
    else
    {
        cout << "Product not found!" << endl;
    }
}

void Supermarket::outProducts() const
{
    if (inventory.empty())
    {
        cout << "No products in the inventory!" << endl;
        return;
    }

    for (const auto &product : inventory)
    {
        product.out();
        cout << "---------------------------" << endl;
    }
}

void Supermarket::searchProductById()
{
    string id;
    cout << "Enter product ID to search: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index != -1)
    {
        inventory[index].out();
    }
    else
    {
        cout << "Product not found!" << endl;
    }
}

void Supermarket::searchProductByName()
{
    string name;
    cout << "Enter product name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (const auto &product : inventory)
    {
        if (product.getName() == name)
        {
            product.out();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No products found with that name!" << endl;
    }
}

void Supermarket::updateProductQuantity()
{
    string id;
    cout << "Enter product ID to update quantity: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index != -1)
    {
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        inventory[index].updateQuantity(newQuantity);
        cout << "Product quantity updated successfully!" << endl;
    }
    else
    {
        cout << "Product not found!" << endl;
    }
}

int Supermarket::findBillIndex(const string &id)
{
    for (int i = 0; i < bills.size(); ++i)
    {
        if (bills[i].getInvoiceId() == id)
            return i;
    }
    return -1; // Không tìm thấy
}

void Supermarket::createBill()
{
    string customerId, employeeId;
    cout << "Enter Customer ID for the bill: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end() || activeCarts[customerId].isEmpty())
    {
        cout << "No active cart for this customer or cart is empty.\n";
        return;
    }

    cout << "Enter Employee ID for the bill: ";
    getline(cin >> ws, employeeId);

    // Generate Bill ID (For simplicity, we use a random ID generator or sequential logic)
    string invoiceId = generateId("BILL");

    float discountRate = 0.0f; // Discount logic can be customized
    Bill newBill;
    newBill.generateInvoice(activeCarts[customerId], discountRate, employeeId);

    bills.push_back(newBill);
    cout << "Bill created!\n";
}

void Supermarket::outBill()
{
    string invoiceId;
    cout << "Enter Invoice ID to view bill: ";
    getline(cin >> ws, invoiceId);

    int index = findBillIndex(invoiceId);
    if (index == -1)
    {
        cout << "Bill not found!\n";
        return;
    }

    bills[index].out();
}

void Supermarket::searchBillById()
{
    string invoiceId;
    cout << "Enter Invoice ID to search: ";
    getline(cin >> ws, invoiceId);

    int index = findBillIndex(invoiceId);
    if (index == -1)
    {
        cout << "Bill not found!\n";
        return;
    }

    bills[index].out();
}

void Supermarket::searchBillsByCustomer()
{
    string customerId;
    cout << "Enter Customer ID to search bills: ";
    getline(cin >> ws, customerId);

    bool found = false;
    for (const Bill &bill : bills)
    {
        if (bill.getCustomerId() == customerId)
        {
            bill.out();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No bills found for this customer.\n";
    }
}

void Supermarket::searchBillsByDate()
{
    string date;
    cout << "Enter date (YYYY-MM-DD) to search bills: ";
    getline(cin >> ws, date);

    bool found = false;
    for (const Bill &bill : bills)
    {
        if (bill.getDate() == date)
        {
            bill.out();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No bills found for this date.\n";
    }
}

void Supermarket::generateSalesReport()
{
    float totalSales = 0.0f;
    for (const Bill &bill : bills)
    {
        totalSales += bill.getTotal();
    }

    cout << "Total Sales: " << totalSales << " VND\n";
}

void Supermarket::createCart()
{
    string customerId;
    cout << "Enter Customer ID to create a cart: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) != activeCarts.end())
    {
        cout << "Cart already exists for this customer.\n";
        return;
    }

    Cart newCart;
    newCart.setCustomerId(customerId);
    activeCarts[customerId] = newCart;
    cout << "Cart created!\n";
}

void Supermarket::addToCart()
{
    string customerId, productId;
    int quantity;
    cout << "Enter Customer ID: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "No active cart for this customer.\n";
        return;
    }

    cout << "Enter Product ID to add: ";
    getline(cin >> ws, productId);

    int index = findProductIndex(productId);
    if (index == -1)
    {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > inventory[index].getQuantity())
    {
        cout << "Invalid quantity!\n";
        return;
    }

    activeCarts[customerId].addProduct(inventory[index], quantity);
    cout << "Product added to cart!\n";
}

void Supermarket::removeFromCart()
{
    string customerId, productId;
    cout << "Enter Customer ID: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "No active cart for this customer.\n";
        return;
    }

    cout << "Enter Product ID to remove: ";
    getline(cin >> ws, productId);

    if (!activeCarts[customerId].removeProduct(productId))
    {
        cout << "Product not found in cart!\n";
    }
    else
    {
        cout << "Product removed from cart.\n";
    }
}

void Supermarket::updateCartItemQuantity()
{
    string customerId, productId;
    int newQuantity;
    cout << "Enter Customer ID: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "No active cart for this customer.\n";
        return;
    }

    cout << "Enter Product ID: ";
    getline(cin >> ws, productId);

    cout << "Enter new quantity: ";
    cin >> newQuantity;

    if (!activeCarts[customerId].updateProductQuantity(productId, newQuantity))
    {
        cout << "Product not found in cart or invalid quantity!\n";
    }
    else
    {
        cout << "Cart updated!\n";
    }
}

void Supermarket::outCart()
{
    string customerId;
    cout << "Enter Customer ID to view cart: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "No active cart for this customer.\n";
        return;
    }

    activeCarts[customerId].out();
}

void Supermarket::clearCart()
{
    string customerId;
    cout << "Enter Customer ID to clear cart: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "No active cart for this customer.\n";
        return;
    }

    activeCarts[customerId].clear();
    cout << "Cart cleared!\n";
}

void Supermarket::pause()
{
    cout << "Nhan phim Enter de tiep tuc...";
    cin.ignore();
    cin.get();
}

// ======= CUSTOMER FUNCTIONS =======

void Supermarket::addCustomer(vector<Customer> &customers)
{
    Customer c;
    c.in();
    customers.push_back(c);
}

void Supermarket::editCustomer(vector<Customer> &customers)
{
    string id;
    cout << "Nhap ID khach hang can sua: ";
    cin >> id;
    bool found = false;
    for (auto &c : customers)
    {
        if (c.getId() == id)
        {
            cout << "Thong tin cu:\n";
            c.out();
            cout << "\nNhap thong tin moi:\n";
            c.in();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay khach hang!\n";
}

void Supermarket::deleteCustomer(vector<Customer> &customers)
{
    string id;
    cout << "Nhap ID khach hang can xoa: ";
    cin >> id;
    auto it = remove_if(customers.begin(), customers.end(), [&](Customer &c)
                        { return c.getId() == id; });
    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        cout << "Da xoa thanh cong!\n";
    }
    else
    {
        cout << "Khong tim thay khach hang!\n";
    }
}

void Supermarket::searchCustomer(const vector<Customer> &customers)
{
    int choice;
    cout << "1. Tim theo ID\n2. Tim theo ten\nChon: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string id;
        cout << "Nhap ID: ";
        cin >> id;
        for (const auto &c : customers)
        {
            if (c.getId() == id)
            {
                c.out();
                return;
            }
        }
    }
    else
    {
        string name;
        cout << "Nhap ten: ";
        getline(cin, name);
        for (const auto &c : customers)
        {
            if (c.getName().find(name) != string::npos)
            {
                c.out();
                cout << "-----------------\n";
            }
        }
    }
}

void Supermarket::displayCustomers(const vector<Customer> &customers)
{
    cout << "--- Danh sach khach hang ---\n";
    for (const auto &c : customers)
    {
        c.out();
        cout << "-----------------\n";
    }
}

// ======= EMPLOYEE FUNCTIONS =======

void Supermarket::addEmployee(vector<Employee> &employees)
{
    Employee e;
    e.in();
    employees.push_back(e);
}

void Supermarket::editEmployee(vector<Employee> &employees)
{
    string id;
    cout << "Nhap ID nhan vien can sua: ";
    cin >> id;
    bool found = false;
    for (auto &e : employees)
    {
        if (e.getId() == id)
        {
            cout << "Thong tin cu:\n";
            e.out();
            cout << "\nNhap thong tin moi:\n";
            e.in();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay nhan vien!\n";
}

void Supermarket::deleteEmployee(vector<Employee> &employees)
{
    string id;
    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
    auto it = remove_if(employees.begin(), employees.end(), [&](Employee &e)
                        { return e.getId() == id; });
    if (it != employees.end())
    {
        employees.erase(it, employees.end());
        cout << "Da xoa thanh cong!\n";
    }
    else
    {
        cout << "Khong tim thay nhan vien!\n";
    }
}

void Supermarket::searchEmployee(const vector<Employee> &employees)
{
    int choice;
    cout << "1. Tim theo ID\n2. Tim theo ten\nChon: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string id;
        cout << "Nhap ID: ";
        cin >> id;
        for (const auto &e : employees)
        {
            if (e.getId() == id)
            {
                e.out();
                return;
            }
        }
    }
    else
    {
        string name;
        cout << "Nhap ten: ";
        getline(cin, name);
        for (const auto &e : employees)
        {
            if (e.getName().find(name) != string::npos)
            {
                e.out();
                cout << "-----------------\n";
            }
        }
    }
}

void Supermarket::displayEmployees(const vector<Employee> &employees)
{
    cout << "--- Danh sach nhan vien ---\n";
    for (const auto &e : employees)
    {
        e.out();
        cout << "-----------------\n";
    }
}

void Supermarket::promoteEmployee(vector<Employee> &employees)
{
    string id, newPos;
    cout << "Nhap ID nhan vien: ";
    cin >> id;
    cin.ignore();
    cout << "Nhap chuc vu moi: ";
    getline(cin, newPos);
    for (auto &e : employees)
    {
        if (e.getId() == id)
        {
            e.promote(newPos);
            cout << "Da phan quyen thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien!\n";
}

int main()
{
    Supermarket supermarket;
    int choice;
    vector<Customer> customers;
    vector<Employee> employees;

    do
    {
        cout << "===============================" << endl;
        cout << "Supermarket Management System" << endl;
        cout << "===============================" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Edit Product" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Display All Products" << endl;
        cout << "5. Search Product by ID" << endl;
        cout << "6. Search Product by Name" << endl;
        cout << "7. Update Product Quantity" << endl;
        cout << "8. Create Cart" << endl;
        cout << "9. Add to Cart" << endl;
        cout << "10. Remove from Cart" << endl;
        cout << "11. Update Cart Item Quantity" << endl;
        cout << "12. Display Cart" << endl;
        cout << "13. Clear Cart" << endl;
        cout << "14. Create Bill" << endl;
        cout << "15. View Bill" << endl;
        cout << "16. Search Bill by ID" << endl;
        cout << "17. Search Bills by Customer" << endl;
        cout << "18. Search Bills by Date" << endl;
        cout << "19. Generate Sales Report" << endl;
        cout << "20. Add Customer" << endl;
        cout << "21. Edit Customer" << endl;
        cout << "22. Delete Customer" << endl;
        cout << "23. Search Customer" << endl;
        cout << "24. Display Customers" << endl;
        cout << "25. Add Employee" << endl;
        cout << "26. Edit Employee" << endl;
        cout << "27. Delete Employee" << endl;
        cout << "28. Search Employee" << endl;
        cout << "29. Display Employees" << endl;
        cout << "30. Promote Employee" << endl;
        cout << "31. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice)
        {
        case 1:
            supermarket.addProduct();
            break;
        case 2:
            supermarket.editProduct();
            break;
        case 3:
            supermarket.removeProduct();
            break;
        case 4:
            supermarket.outProducts();
            break;
        case 5:
            supermarket.searchProductById();
            break;
        case 6:
            supermarket.searchProductByName();
            break;
        case 7:
            supermarket.updateProductQuantity();
            break;
        case 8:
            supermarket.createCart();
            break;
        case 9:
            supermarket.addToCart();
            break;
        case 10:
            supermarket.removeFromCart();
            break;
        case 11:
            supermarket.updateCartItemQuantity();
            break;
        case 12:
            supermarket.outCart();
            break;
        case 13:
            supermarket.clearCart();
            break;
        case 14:
            supermarket.createBill();
            break;
        case 15:
            supermarket.outBill();
            break;
        case 16:
            supermarket.searchBillById();
            break;
        case 17:
            supermarket.searchBillsByCustomer();
            break;
        case 18:
            supermarket.searchBillsByDate();
            break;
        case 19:
            supermarket.generateSalesReport();
            break;
        case 20:
            supermarket.addCustomer(customers);
            break;
        case 21:
            supermarket.editCustomer(customers);
            break;
        case 22:
            supermarket.deleteCustomer(customers);
            break;
        case 23:
            supermarket.searchCustomer(customers);
            break;
        case 24:
            supermarket.displayCustomers(customers);
            break;
        case 25:
            supermarket.addEmployee(employees);
            break;
        case 26:
            supermarket.editEmployee(employees);
            break;
        case 27:
            supermarket.deleteEmployee(employees);
            break;
        case 28:
            supermarket.searchEmployee(employees);
            break;
        case 29:
            supermarket.displayEmployees(employees);
            break;
        case 30:
            supermarket.promoteEmployee(employees);
            break;
        case 31:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;

    } while (choice != 31);

    return 0;
}
