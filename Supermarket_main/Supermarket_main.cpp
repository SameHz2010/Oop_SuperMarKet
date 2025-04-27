#include "../Class Headers/Supermarket.h"

Supermarket::Supermarket() {}

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
    cout << "-------------------------------------------------------------" << endl;
    cout << "Product added successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product updated successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found!" << endl;
        cout << "-------------------------------------------------------------" << endl;
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product removed successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::outProducts() const
{
    cout << "----------------------- Product List ------------------------" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity" << endl;

    if (inventory.empty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No products in the inventory!" << endl;
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    for (const auto &product : inventory)
    {
        product.out();
    }
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::writeFileCsv_product()
{
    ofstream outFile("../Data_csv/data_product.csv");
    if (!outFile)
    {
        cerr << "Failed to open file for writing!" << endl;
        return;
    }

    outFile << "ID,Name,Price,Quantity\n";
    for (const auto &product : inventory)
    {
        outFile << product.getId() << ","
                << product.getName() << ","
                << product.getPrice() << ","
                << product.getQuantity() << "\n";
    }

    outFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Saved " << inventory.size() << " products to file CSV." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::readFileCsv_product()
{
    ifstream inFile("../Data_csv/data_product.csv");
    if (!inFile)
    {
        cerr << "Failed to open file for reading!" << endl;
        return;
    }

    inventory.clear();

    string line;
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string id, name, priceStr, quantityStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr, ',');

        Product p;
        p.setId(id);
        p.setName(name);
        p.setPrice(stof(priceStr));
        p.updateQuantity(atoi(quantityStr.c_str()));

        inventory.push_back(p);
    }

    inFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Loaded " << inventory.size() << " products from file CSV" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::searchProductById()
{
    string id;
    cout << "Enter product ID to search: ";
    cin >> id;
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity" << endl;

    int index = findProductIndex(id);
    if (index != -1)
    {
        inventory[index].out();
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::searchProductByName()
{
    string name;
    cout << "Enter product name to search: ";
    getline(cin, name);
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity" << endl;

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
        cout << "-------------------------------------------------------------" << endl;
        cout << "No products found with that name!" << endl;
        cout << "-------------------------------------------------------------" << endl;
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product quantity updated successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::addCustomer()
{
    Customer *customer = new Customer();
    customer->in();
    people.push_back(customer);
}

void Supermarket::editCustomer()
{
    string id;
    cout << "Enter the ID of the customer to edit: ";
    cin >> id;
    bool found = false;

    for (auto &p : people)
    {
        Customer *customer = dynamic_cast<Customer *>(p);
        if (customer && customer->getId() == id)
        {
            cout << "Current information:\n";
            customer->out();
            cout << "\nEnter the new information:\n";
            customer->in();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customer not found!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customer updated successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::deleteCustomer()
{
    string id;
    cout << "Enter the ID of the customer to delete: ";
    cin >> id;
    bool found = false;

    for (auto it = people.begin(); it != people.end();)
    {
        Customer *customer = dynamic_cast<Customer *>(*it);
        if (customer && customer->getId() == id)
        {
            delete customer;
            it = people.erase(it);
            found = true;
        }
        else
        {
            ++it;
        }
    }

    if (found)
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customer deleted successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customer not found!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::searchCustomer()
{
    int choice;
    cout << "1. Search by ID\n2. Search by name\nChoose: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        string id;
        cout << "Enter ID: ";
        cin >> id;
        for (const auto &p : people)
        {
            Customer *customer = dynamic_cast<Customer *>(p);
            if (customer && customer->getId() == id)
            {
                customer->out();
                return;
            }
        }
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customer not found!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cout << "Enter name: ";
        getline(cin, name);
        bool found = false;
        for (const auto &p : people)
        {
            Customer *customer = dynamic_cast<Customer *>(p);
            if (customer && customer->getName().find(name) != string::npos)
            {
                customer->out();
                cout << "-------------------------------------------------------------\n";
                found = true;
            }
        }
        if (!found)
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "No customers found with the given name.\n";
            cout << "-------------------------------------------------------------" << endl;
        }
    }
    else
    {
        cout << "Enter a valid choice." << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::displayCustomers()
{
    cout << "------------------- Customer List --------------------\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Phone"
         << setw(15) << "MemberType" << setw(10) << "LoyaltyPoint" << endl;
    for (const auto &p : people)
    {
        Customer *customer = dynamic_cast<Customer *>(p);
        if (customer)
        {
            customer->out();
        }
    }
    cout << "-------------------------------------------------------------\n";
}

void Supermarket::writeFileCsv_customer()
{
    const string filePath = "../Data_csv/data_customer.csv";
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cerr << "Failed to open " << filePath << " for writing!" << endl;
        return;
    }

    outFile << "ID,Name,Phone,MemberType,LoyaltyPoints\n";

    int count = 0;
    for (const auto &p : people)
    {
        if (Customer *customer = dynamic_cast<Customer *>(p))
        {
            outFile << customer->getId() << ","
                    << customer->getName() << ","
                    << customer->getPhone() << ","
                    << customer->getMemberType() << ","
                    << customer->getLoyaltyPoints() << "\n";
            count++;
        }
    }

    outFile.close();

    cout << "-------------------------------------------------------------" << endl;
    cout << "Saved " << count << " customers to data_customer.csv" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::readFileCsv_customer()
{
    for (auto it = people.begin(); it != people.end();)
    {
        Customer *customer = dynamic_cast<Customer *>(*it);
        if (customer)
        {
            delete customer;
            it = people.erase(it);
        }
        else
            ++it;
    }

    ifstream inFile("../Data_csv/data_customer.csv");
    if (!inFile)
    {
        cerr << "Failed to open data_customer.csv for reading!" << endl;
        return;
    }

    string line;
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string id, name, phone, memberType, loyaltyPointsStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, memberType, ',');
        getline(ss, loyaltyPointsStr);

        int loyaltyPoints = 0;
        try
        {
            loyaltyPoints = stoi(loyaltyPointsStr);
        }
        catch (const exception &e)
        {
            cerr << "Error converting loyalty points for customer with ID " << id << ": " << e.what() << endl;
            continue;
        }

        Customer *customer = new Customer();
        customer->setId(id);
        customer->setName(name);
        customer->setPhone(phone);
        customer->setMemberType(memberType);
        customer->addLoyaltyPoints(loyaltyPoints);

        people.push_back(customer);
    }

    inFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Loaded customers from data_customer.csv" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::addEmployee()
{
    Employee *e = new Employee();
    e->in();
    people.push_back(e);
    cout << "-------------------------------------------------------------" << endl;
    cout << "Employee added successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::editEmployee()
{
    string id;
    cout << "Enter employee ID to edit: ";
    cin >> id;
    bool found = false;
    for (auto &p : people)
    {
        Employee *e = dynamic_cast<Employee *>(p);
        if (e && e->getId() == id)
        {
            cout << "Current info:\n";
            e->out();
            cout << "\nEnter new information:\n";
            e->in();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employee not found!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employee updated successfully!" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::deleteEmployee()
{
    string id;
    cout << "Enter employee ID to delete: ";
    cin >> id;
    auto it = remove_if(people.begin(), people.end(), [&](Person *p)
                        { 
                            Employee* e = dynamic_cast<Employee*>(p);
                            return e && e->getId() == id; });
    if (it != people.end())
    {
        people.erase(it, people.end());
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employee deleted successfully!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employee not found!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::searchEmployee()
{
    int choice;
    cout << "1. Search by ID\n2. Search by Name\nChoose: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string id;
        cout << "Enter ID: ";
        cin >> id;
        for (const auto &p : people)
        {
            Employee *e = dynamic_cast<Employee *>(p);
            if (e && e->getId() == id)
            {
                e->out();
                return;
            }
        }
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employee not found!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        string name;
        cout << "Enter name: ";
        getline(cin, name);
        for (const auto &p : people)
        {
            Employee *e = dynamic_cast<Employee *>(p);
            if (e && e->getName().find(name) != string::npos)
            {
                e->out();
                cout << "-----------------\n";
            }
        }
    }
}

void Supermarket::displayEmployees()
{
    cout << "---------------------- Employee List -------------------------\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Phone"
         << setw(20) << "Position" << setw(15) << "Salary" << setw(10) << "DateHired" << endl;
    for (const auto &p : people)
    {
        Employee *e = dynamic_cast<Employee *>(p);
        if (e)
        {
            e->out();
        }
    }
    cout << "-------------------------------------------------------------\n";
}

void Supermarket::promoteEmployee()
{
    string id, newPos;
    double newSalary;
    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter new position: ";
    getline(cin, newPos);
    cout << "Enter new salary: ";
    cin >> newSalary;

    for (auto &p : people)
    {
        Employee *e = dynamic_cast<Employee *>(p);
        if (e && e->getId() == id)
        {
            e->setPosition(newPos);
            e->setSalary(newSalary);
            cout << "-------------------------------------------------------------" << endl;
            cout << "Employee promoted successfully!\n";
            cout << "-------------------------------------------------------------" << endl;
            return;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "Employee not found!\n";
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::writeFileCsv_employee()
{
    ofstream outFile("../Data_csv/data_employee.csv");
    if (!outFile)
    {
        cerr << "Failed to open data_employee.csv for writing!" << endl;
        return;
    }

    outFile << "ID,Name,Phone,Position,Salary,DateHired\n";
    for (const auto &p : people)
    {
        Employee *e = dynamic_cast<Employee *>(p);
        if (e)
        {
            outFile << e->getId() << ","
                    << e->getName() << ","
                    << e->getPhone() << ","
                    << e->getPosition() << ","
                    << e->getSalary() << ","
                    << e->getDateHired() << "\n";
        }
    }

    outFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Saved employees to data_employee.csv" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::readFileCsv_employee()
{
    for (auto it = people.begin(); it != people.end();)
    {
        Employee *employee = dynamic_cast<Employee *>(*it);
        if (employee)
        {
            delete employee;
            it = people.erase(it);
        }
        else
            ++it;
    }

    ifstream inFile("../Data_csv/data_employee.csv");
    if (!inFile)
    {
        cerr << "Failed to open data_employee.csv for reading!" << endl;
        return;
    }

    string line;
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string id, name, phone, position, salaryStr, dateHired;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, position, ',');
        getline(ss, salaryStr, ',');
        getline(ss, dateHired, ',');

        float salary = 0.0f;
        try
        {
            salary = stof(salaryStr);
        }
        catch (const exception &e)
        {
            cerr << "Error converting salary for employee with ID " << id << ": " << e.what() << endl;
            continue;
        }

        Employee *e = new Employee();
        e->setId(id);
        e->setName(name);
        e->setPhone(phone);
        e->setPosition(position);
        e->setSalary(salary);
        e->setDateHired(dateHired);

        people.push_back(e);
    }

    inFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Loaded employees from data_employee.csv" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::createCart()
{
    string customerId;
    cout << "Enter Customer ID to create a cart: ";
    getline(cin >> ws, customerId);

    bool customerExists = false;
    for (const auto &p : people)
    {
        Customer *customer = dynamic_cast<Customer *>(p);
        if (customer && customer->getId() == customerId)
        {
            customerExists = true;
            break;
        }
    }

    if (!customerExists)
    {
        Customer newCustomer;
        cout << "Customer not found. Please enter customer details.\n";
        newCustomer.in();
        people.push_back(new Customer(newCustomer));
        cout << "New customer added.\n";
    }

    if (activeCarts.find(customerId) != activeCarts.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Cart already exists for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    Cart newCart;
    newCart.setCustomerId(customerId);
    activeCarts[customerId] = newCart;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Cart created!\n";
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::addToCart()
{
    string customerId, productId;
    int quantity;
    cout << "Enter Customer ID: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No active cart for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << "Enter Product ID to add: ";
    getline(cin >> ws, productId);

    int index = findProductIndex(productId);
    if (index == -1)
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found!\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > inventory[index].getQuantity())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Invalid quantity!\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    activeCarts[customerId].addProduct(inventory[index], quantity);
    cout << "-------------------------------------------------------------" << endl;
    cout << "Product added to cart!\n";
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::removeFromCart()
{
    string customerId, productId;
    cout << "Enter Customer ID: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No active cart for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << "Enter Product ID to remove: ";
    getline(cin >> ws, productId);

    if (!activeCarts[customerId].removeProduct(productId))
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found in cart!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product removed from cart.\n";
        cout << "-------------------------------------------------------------" << endl;
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "No active cart for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << "Enter Product ID: ";
    getline(cin >> ws, productId);

    cout << "Enter new quantity: ";
    cin >> newQuantity;

    if (!activeCarts[customerId].updateProductQuantity(productId, newQuantity))
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Product not found in cart or invalid quantity!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Cart updated!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::outCart()
{
    string customerId;
    cout << "Enter Customer ID to view cart: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No active cart for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    activeCarts[customerId].out();
    cout << "--------------------------" << endl;
}

void Supermarket::clearCart()
{
    string customerId;
    cout << "Enter Customer ID to clear cart: ";
    getline(cin >> ws, customerId);

    if (activeCarts.find(customerId) == activeCarts.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No active cart for this customer.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    activeCarts[customerId].clear();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Cart cleared!\n";
    cout << "-------------------------------------------------------------" << endl;
}

int Supermarket::findBillIndex(const string &id)
{
    for (int i = 0; i < bills.size(); ++i)
    {
        if (bills[i].getInvoiceId() == id)
            return i;
    }
    return -1;
}

void Supermarket::createBill()
{
    string customerId;
    string employeeId;

    cout << "\n=== CREATE BILL ===\n";
    cout << "Enter customer ID: ";
    cin >> customerId;

    if (activeCarts.find(customerId) == activeCarts.end() || activeCarts[customerId].isEmpty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Cart not found or is empty for this customer!\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    string paymentMethod;
    cout << "Enter payment method (Cash/Card): ";
    cin >> paymentMethod;

    cout << "Enter employee ID: ";
    cin >> employeeId;

    Bill newBill;
    newBill.generateInvoice(activeCarts[customerId], 0.0f, employeeId);
    newBill.setPaymentMethod(paymentMethod);

    float discountRate;
    cout << "Enter discount rate (e.g., 0.1 for 10%): ";
    cin >> discountRate;
    newBill.setDiscount(discountRate);
    newBill.generateInvoice(activeCarts[customerId], discountRate, employeeId);

    bills.push_back(newBill);

    cout << "-------------------------------------------------------------" << endl;
    cout << "\nInvoice created successfully!\n";
    newBill.out();
    cout << "-------------------------------------------------------------" << endl;
    cout << "\nCart remains for future use.\n";
}

void Supermarket::outBills() const
{
    cout << "\n=== ALL INVOICES ===\n";

    if (bills.empty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No bills found.\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    for (size_t i = 0; i < bills.size(); ++i)
    {
        cout << "\n------ BILL #" << (i + 1) << " ------\n";
        bills[i].out();
    }
}

void Supermarket::searchBillById()
{
    string id;
    cout << "Enter invoice ID to search: ";
    cin >> id;

    for (const auto &bill : bills)
    {
        if (bill.getInvoiceId() == id)
        {
            bill.out();
            return;
        }
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "No invoice found with ID: " << id << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::searchBillsByCustomerId()
{
    string customerId;
    cout << "Enter Customer ID to search bills: ";
    getline(cin >> ws, customerId);

    vector<Bill> foundBills;

    for (const Bill &bill : bills)
    {
        if (bill.getCustomerId() == customerId)
        {
            foundBills.push_back(bill);
        }
    }

    if (foundBills.empty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No bills found for customer ID: " << customerId << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "\nFound " << foundBills.size() << " bill(s) for customer ID: " << customerId << "\n\n";
        for (const auto &bill : foundBills)
        {
            bill.out();
            cout << "-----------------------------\n";
        }
    }
}

Product &Supermarket::getProductById(const string &productId)
{
    for (auto &product : inventory)
    {
        if (product.getId() == productId)
        {
            return product;
        }
    }
    throw runtime_error("Product not found!");
}

void Supermarket::payBill()
{
    string invoiceId;
    cout << "\n=== PAY BILL ===\n";
    cout << "Enter invoice ID: ";
    cin >> invoiceId;

    auto it = find_if(bills.begin(), bills.end(), [&invoiceId](const Bill &bill)
                      { return bill.getInvoiceId() == invoiceId; });

    if (it == bills.end())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Invoice not found!\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    Bill &billToPay = *it;

    for (const auto &item : billToPay.getItems())
    {
        try
        {
            Product &product = getProductById(item.getProductId());
            if (product.getQuantity() < item.getQuantity())
            {
                cout << "Not enough stock for product ID: " << item.getProductId() << endl;
                return;
            }
            product.reduceQuantity(item.getQuantity());
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            return;
        }
    }

    string customerId = billToPay.getCustomerId();
    activeCarts[customerId].clear();

    cout << "-------------------------------------------------------------" << endl;
    cout << "\nPayment successful for Invoice: " << invoiceId << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::writeFileCsv_bill()
{
    ofstream outFile("../Data_csv/data_bill.csv");
    if (!outFile)
    {
        cout << "Failed to open bills.csv" << endl;
        return;
    }

    outFile << "InvoiceID,CustomerID,Date,PaymentMethod,Subtotal,Discount,Tax,Total\n";
    for (const auto &bill : bills)
    {
        outFile << bill.getInvoiceId() << ","
                << bill.getCustomerId() << ","
                << bill.getDate() << ","
                << bill.getPaymentMethod() << ","
                << bill.getSubtotal() << ","
                << bill.getDiscount() << ","
                << bill.getTax() << ","
                << bill.getTotal() << "\n";
    }

    outFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Bills saved to bills.csv successfully." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

bool compareProduct(const Product &a, const Product &b, int sortType, bool ascending)
{
    if (!ascending)
        return compareProduct(b, a, sortType, true);

    switch (sortType)
    {
    case 1:
        return a.getId() < b.getId();
    case 2:
        return a.getPrice() < b.getPrice();
    default:
        return a.getId() < b.getId();
    }
}

bool compareCustomer(const Customer *a, const Customer *b, int sortType, bool ascending)
{
    bool result = false;

    switch (sortType)
    {
    case 1:
        result = a->getId() < b->getId();
        break;
    case 2:
        result = a->getName() < b->getName();
        break;
    case 3:
        result = a->getMemberType() < b->getMemberType();
        break;
    case 4:
        result = a->getLoyaltyPoints() < b->getLoyaltyPoints();
        break;
    default:
        result = a->getId() < b->getId();
        break;
    }

    return ascending ? result : !result;
}

bool compareEmployee(const Employee *a, const Employee *b, int sortType, bool ascending)
{
    bool result = false;

    switch (sortType)
    {
    case 1:
        result = a->getId() < b->getId();
        break;
    case 2:
    {
        map<string, int> positionRank = {
            {"Manager", 1},
            {"Assistant Manager", 2},
            {"Supervisor", 3},
            {"Staff", 4}};

        int rankA = positionRank.count(a->getPosition()) ? positionRank[a->getPosition()] : 999;
        int rankB = positionRank.count(b->getPosition()) ? positionRank[b->getPosition()] : 999;

        result = rankA > rankB;
        break;
    }
    case 3:
        result = a->getSalary() < b->getSalary();
        break;
    case 4:
    {
        string dateA = a->getDateHired();
        string dateB = b->getDateHired();
        int dayA = stoi(dateA.substr(0, 2));
        int monthA = stoi(dateA.substr(3, 2));
        int yearA = stoi(dateA.substr(6, 4));
        int dayB = stoi(dateB.substr(0, 2));
        int monthB = stoi(dateB.substr(3, 2));
        int yearB = stoi(dateB.substr(6, 4));

        if (yearA != yearB)
            result = yearA > yearB;
        else if (monthA != monthB)
            result = monthA > monthB;
        else
            result = dayA > dayB;
        break;
    }
    default:
        result = a->getId() < b->getId();
        break;
    }

    return ascending ? result : !result;
}

void Supermarket::sortProducts()
{
    int sortType;
    bool ascending;
    cout << "Sort Products by:\n1. ID\n2. Price\nEnter your choice: ";
    cin >> sortType;
    cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
    cin >> ascending;

    sort(inventory.begin(), inventory.end(), [sortType, ascending](const Product &a, const Product &b)
         { return compareProduct(a, b, sortType, ascending); });

    cout << "-------------------------------------------------------------" << endl;
    cout << "Products sorted.\n";
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::sortCustomers()
{
    if (people.empty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No customers to sort!" << endl;
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    int choice;
    cout << "Sort customers by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Member Type\n";
    cout << "4. Loyalty Points\n";
    cout << "Enter your choice: ";
    cin >> choice;

    bool ascending = true;
    int orderChoice;
    cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
    cin >> orderChoice;
    cin.ignore();

    if (orderChoice == 0)
    {
        ascending = false;
    }

    vector<Customer *> customerList;
    for (Person *p : people)
    {
        if (Customer *cust = dynamic_cast<Customer *>(p))
        {
            customerList.push_back(cust);
        }
    }

    sort(customerList.begin(), customerList.end(), [choice, ascending](const Customer *a, const Customer *b)
         { return compareCustomer(a, b, choice, ascending); });

    vector<Person *> sortedPeople;
    for (Person *p : people)
    {
        if (!dynamic_cast<Customer *>(p))
        {
            sortedPeople.push_back(p);
        }
    }
    sortedPeople.insert(sortedPeople.end(), customerList.begin(), customerList.end());
    people = sortedPeople;

    cout << "-------------------------------------------------------------" << endl;
    cout << "Customers sorted successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::sortEmployees()
{
    if (people.empty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "No employees to sort!" << endl;
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    int choice;
    cout << "Sort employees by:\n";
    cout << "1. ID\n";
    cout << "2. Position (Manager > Assistant Manager > ... > Staff)\n";
    cout << "3. Salary\n";
    cout << "4. Date Hired (DD-MM-YYYY)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    bool ascending = true;
    int orderChoice;
    cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
    cin >> orderChoice;
    cin.ignore();

    if (orderChoice == 0)
    {
        ascending = false;
    }

    vector<Employee *> employeeList;
    for (Person *p : people)
    {
        if (Employee *emp = dynamic_cast<Employee *>(p))
        {
            employeeList.push_back(emp);
        }
    }

    sort(employeeList.begin(), employeeList.end(), [choice, ascending](const Employee *a, const Employee *b)
         { return compareEmployee(a, b, choice, ascending); });

    vector<Person *> sortedPeople;
    for (Person *p : people)
    {
        if (!dynamic_cast<Employee *>(p))
        {
            sortedPeople.push_back(p);
        }
    }
    sortedPeople.insert(sortedPeople.end(), employeeList.begin(), employeeList.end());
    people = sortedPeople;

    cout << "-------------------------------------------------------------" << endl;
    cout << "Employees sorted successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::sortData()
{
    int choice;
    cout << "1. Sort Products\n2. Sort Customers\n3. Sort Employees\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        sortProducts();
        break;
    case 2:
        sortCustomers();
        break;
    case 3:
        sortEmployees();
        break;
    default:
        cout << "-------------------------------------------------------------" << endl;
        cout << "Invalid choice.\n";
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::inMenu()
{
    Supermarket supermarket;
    vector<Customer> customers;
    vector<Employee> employees;
    int choice;

    do
    {
        cout << "=============================================================" << endl;
        cout << "\t\tSupermarket Management System" << endl;
        cout << "=============================================================" << endl;
        cout << "\t\t-----Product-----" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Edit Product" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Display All Products" << endl;
        cout << "5. Search Product by ID" << endl;
        cout << "6. Search Product by Name" << endl;
        cout << "7. Update Product Quantity" << endl;
        cout << "8. Read List Product from data_product.csv" << endl;
        cout << "9. Write list Product to data_product.csv" << endl;
        cout << "\t\t----Cart & Bill----" << endl;
        cout << "10. Create Cart" << endl;
        cout << "11. Add to Cart" << endl;
        cout << "12. Remove from Cart" << endl;
        cout << "13. Update Cart Item Quantity" << endl;
        cout << "14. Display Cart" << endl;
        cout << "15. Clear Cart" << endl;
        cout << "16. Create Bill" << endl;
        cout << "17. View Bill" << endl;
        cout << "18. Search Bill by InvoiceID" << endl;
        cout << "19. Search Bills by CustomerID" << endl;
        cout << "20. Checkout Bill" << endl;
        cout << "21. Write Bill to data_bill.csv" << endl;
        cout << "\t\t-----Customer-----" << endl;
        cout << "22. Add Customer" << endl;
        cout << "23. Edit Customer" << endl;
        cout << "24. Delete Customer" << endl;
        cout << "25. Search Customer" << endl;
        cout << "26. Display Customers" << endl;
        cout << "27. Read List Product from data_customer.csv" << endl;
        cout << "28. Write list Product to data_customer.csv" << endl;
        cout << "\t\t-----Employee-----" << endl;
        cout << "29. Add Employee" << endl;
        cout << "30. Edit Employee" << endl;
        cout << "31. Delete Employee" << endl;
        cout << "32. Search Employee" << endl;
        cout << "33. Display Employees" << endl;
        cout << "34. Promote Employee" << endl;
        cout << "35. Read List Product from data_employee.csv" << endl;
        cout << "36. Write List Product to data_employee.csv" << endl;
        cout << "\t\t-------Other------" << endl;
        cout << "37. Sort Data(Product/ Customer/ Employee)" << endl;
        cout << "38. Exit!" << endl;
        cout << "-------------------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------------------------------------------\n";
        cin.ignore();

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
            supermarket.readFileCsv_product();
            break;
        case 9:
            supermarket.writeFileCsv_product();
            break;
        case 10:
            supermarket.createCart();
            break;
        case 11:
            supermarket.addToCart();
            break;
        case 12:
            supermarket.removeFromCart();
            break;
        case 13:
            supermarket.updateCartItemQuantity();
            break;
        case 14:
            supermarket.outCart();
            break;
        case 15:
            supermarket.clearCart();
            break;
        case 16:
            supermarket.createBill();
            break;
        case 17:
            supermarket.outBills();
            break;
        case 18:
            supermarket.searchBillById();
            break;
        case 19:
            supermarket.searchBillsByCustomerId();
            break;
        case 20:
            supermarket.payBill();
            break;
        case 21:
            supermarket.writeFileCsv_bill();
            break;
        case 22:
            supermarket.addCustomer();
            break;
        case 23:
            supermarket.editCustomer();
            break;
        case 24:
            supermarket.deleteCustomer();
            break;
        case 25:
            supermarket.searchCustomer();
            break;
        case 26:
            supermarket.displayCustomers();
            break;
        case 27:
            supermarket.readFileCsv_customer();
            break;
        case 28:
            supermarket.writeFileCsv_customer();
            break;
        case 29:
            supermarket.addEmployee();
            break;
        case 30:
            supermarket.editEmployee();
            break;
        case 31:
            supermarket.deleteEmployee();
            break;
        case 32:
            supermarket.searchEmployee();
            break;
        case 33:
            supermarket.displayEmployees();
            break;
        case 34:
            supermarket.promoteEmployee();
            break;
        case 35:
            supermarket.readFileCsv_employee();
            break;
        case 36:
            supermarket.writeFileCsv_employee();
            break;
        case 37:
            supermarket.sortData();
            break;
        case 38:
            cout << "Exiting program..." << endl;
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (true);
}

int main()
{
    Supermarket spmk;
    spmk.inMenu();
}
