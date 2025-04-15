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

void Supermarket::pause()
{
    cout << "Nhan phim Enter de tiep tuc...";
    cin.ignore();
    cin.get();
}

void Supermarket::addCustomer()
{
    Customer c;
    c.in();
    customers.push_back(c);
    cout << "-------------------------------------------------------------" << endl;
    cout << "Customer added successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::editCustomer()
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
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay khach hang!\n";
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
    cout << "Nhap ID khach hang can xoa: ";
    cin >> id;
    auto it = remove_if(customers.begin(), customers.end(), [&](Customer &c)
                        { return c.getId() == id; });
    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        cout << "-------------------------------------------------------------" << endl;
        cout << "Da xoa thanh cong!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay khach hang!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::searchCustomer()
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay khach hang!\n";
        cout << "-------------------------------------------------------------" << endl;
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
                cout << "-------------------------------------------------------------\n";
            }
        }
    }
}

void Supermarket::displayCustomers()
{
    cout << "------------------- Danh sach khach hang --------------------\n";
    for (const auto &c : customers)
    {
        c.out();
    }
    cout << "-------------------------------------------------------------\n";
}

void Supermarket::writeFileCsv_customer()
{
    ofstream outFile("../Data_csv/data_customer.csv");
    if (!outFile)
    {
        cerr << "Failed to open data_customer.csv for writing!" << endl;
        return;
    }

    outFile << "ID,Name,Phone,MemberType,LoyaltyPoints\n"; // Header
    for (const auto &customer : customers)
    {
        outFile << customer.getId() << ","
                << customer.getName() << ","
                << customer.getPhone() << ","
                << customer.getMemberType() << ","
                << customer.getLoyaltyPoints() << "\n";
    }

    outFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Saved " << customers.size() << " customers to data_customer.csv." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::readFileCsv_customer()
{
    ifstream inFile("../Data_csv/data_customer.csv");
    if (!inFile)
    {
        cerr << "Failed to open data_customer.csv for reading!" << endl;
        return;
    }

    string line;
    getline(inFile, line); // Read and discard header

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string id, name, phone, memberType, loyaltyPointsStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, memberType, ',');
        getline(ss, loyaltyPointsStr, ',');

        Customer customer;
        customer.setId(id);
        customer.setName(name);
        customer.setPhone(phone);
        customer.setMemberType(memberType);
        customer.addLoyaltyPoints(atoi(loyaltyPointsStr.c_str()));

        customers.push_back(customer);
    }

    inFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Loaded " << customers.size() << " customers from data_customer.csv." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

// ======= EMPLOYEE FUNCTIONS =======

void Supermarket::addEmployee()
{
    Employee e;
    e.in();
    employees.push_back(e);
    cout << "-------------------------------------------------------------" << endl;
    cout << "Employee added successfully!" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::editEmployee()
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
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay nhan vien!\n";
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
    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
    auto it = remove_if(employees.begin(), employees.end(), [&](Employee &e)
                        { return e.getId() == id; });
    if (it != employees.end())
    {
        employees.erase(it, employees.end());
        cout << "-------------------------------------------------------------" << endl;
        cout << "Da xoa thanh cong!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay nhan vien!\n";
        cout << "-------------------------------------------------------------" << endl;
    }
}

void Supermarket::searchEmployee()
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
        cout << "-------------------------------------------------------------" << endl;
        cout << "Khong tim thay nhan vien!\n";
        cout << "-------------------------------------------------------------" << endl;
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

void Supermarket::displayEmployees()
{
    cout << "--------------------- Danh sach nhan vien -----------------------\n";
    for (const auto &e : employees)
    {
        e.out();
    }
    cout << "-------------------------------------------------------------\n";
}

void Supermarket::promoteEmployee()
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
            e.setPosition(newPos);
            cout << "-------------------------------------------------------------" << endl;
            cout << "Da phan quyen thanh cong!\n";
            cout << "-------------------------------------------------------------" << endl;
            return;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "Khong tim thay nhan vien!\n";
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

    outFile << "ID,Name,Phone,Position,Salary,DateHired\n"; // Header including DateHired
    for (const auto &employee : employees)
    {
        outFile << employee.getId() << ","
                << employee.getName() << ","
                << employee.getPhone() << ","
                << employee.getPosition() << ","
                << employee.getSalary() << ","
                << employee.getDateHired() << "\n"; // Added DateHired
    }

    outFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Saved " << employees.size() << " employees to data_employee.csv." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::readFileCsv_employee()
{
    ifstream inFile("../Data_csv/data_employee.csv");
    if (!inFile)
    {
        cerr << "Failed to open data_employee.csv for reading!" << endl;
        return;
    }

    string line;
    getline(inFile, line); // Read and discard header

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string id, name, phone, position, salaryStr, dateHired; // Added dateHired

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, position, ',');
        getline(ss, salaryStr, ',');
        getline(ss, dateHired, ','); // Read dateHired

        Employee employee;
        employee.setId(id);
        employee.setName(name);
        employee.setPhone(phone);
        employee.setPosition(position);
        employee.setSalary(stof(salaryStr));
        employee.setDateHired(dateHired); // Set dateHired

        employees.push_back(employee);
    }

    inFile.close();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Loaded " << employees.size() << " employees from data_employee.csv." << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Supermarket::createCart()
{
    string customerId;
    cout << "Enter Customer ID to create a cart: ";
    getline(cin >> ws, customerId);

    // Kiểm tra xem khách hàng có tồn tại không
    bool customerExists = false;
    for (const auto &customer : customers)
    {
        if (customer.getId() == customerId)
        {
            customerExists = true;
            break;
        }
    }

    if (!customerExists)
    {
        // Tạo khách hàng mới (yêu cầu thêm thông tin)
        Customer newCustomer;
        cout << "Customer not found. Please enter customer details.\n";
        newCustomer.in(); // Thu thập thông tin từ người dùng
        customers.push_back(newCustomer);
        cout << "New customer added.\n";
    }

    // Tiếp tục tạo giỏ hàng
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

    activeCarts[customerId].out();
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
    return -1; // Không tìm thấy
}

void Supermarket::createBill()
{
    string customerId;
    string employeeId; // Thêm biến employeeId

    cout << "\n=== CREATE BILL ===\n";
    cout << "Enter customer ID: ";
    cin >> customerId;

    // Kiểm tra giỏ hàng tồn tại và không rỗng
    if (activeCarts.find(customerId) == activeCarts.end() || activeCarts[customerId].isEmpty())
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Cart not found or is empty for this customer!\n";
        cout << "-------------------------------------------------------------" << endl;
        return;
    }

    // Lấy thông tin phương thức thanh toán
    string paymentMethod;
    cout << "Enter payment method (Cash/Card): ";
    cin >> paymentMethod;

    // Thêm bước nhập employeeId
    cout << "Enter employee ID: ";
    cin >> employeeId;

    // Tạo hóa đơn mới với thông tin từ giỏ hàng
    Bill newBill;
    newBill.generateInvoice(activeCarts[customerId], 0.0f, employeeId); // Giảm giá ban đầu là 0

    // Đặt phương thức thanh toán cho hóa đơn
    newBill.setPaymentMethod(paymentMethod);

    // Áp dụng discount cho hóa đơn
    float discountRate;
    cout << "Enter discount rate (e.g., 0.1 for 10%): ";
    cin >> discountRate;
    newBill.setDiscount(discountRate); // Áp dụng discount vào Bill

    // Tính lại hóa đơn với discount mới
    newBill.generateInvoice(activeCarts[customerId], discountRate, employeeId); // Gọi lại với discount mới

    // Lưu hóa đơn vào danh sách hóa đơn
    bills.push_back(newBill);

    // Hiển thị hóa đơn ra màn hình
    cout << "-------------------------------------------------------------" << endl;
    cout << "\nInvoice created successfully!\n";
    newBill.out();
    cout << "-------------------------------------------------------------" << endl;

    // Sau khi tạo hóa đơn, giỏ hàng vẫn không bị xóa, vì yêu cầu là giữ lại giỏ hàng để tái sử dụng
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
            pause(); // Nếu bạn có hàm pause() thì giữ lại, không thì xóa dòng này
        }
    }
}

Product &Supermarket::getProductById(const string &productId)
{
    for (auto &product : inventory) // Giả sử bạn có vector `products` chứa các sản phẩm trong kho
    {
        if (product.getId() == productId)
        {
            return product;
        }
    }
    throw runtime_error("Product not found!"); // Nếu không tìm thấy
}

void Supermarket::payBill()
{
    string invoiceId;
    cout << "\n=== PAY BILL ===\n";
    cout << "Enter invoice ID: ";
    cin >> invoiceId;

    // Tìm hóa đơn theo ID
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

    // Cập nhật kho hàng
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

    // Xóa giỏ hàng sau khi thanh toán
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
    if (sortType == 1)
    { // Sắp xếp theo ID
        return ascending ? a.getId() < b.getId() : a.getId() > b.getId();
    }
    else if (sortType == 2)
    { // Sắp xếp theo Price
        return ascending ? a.getPrice() < b.getPrice() : a.getPrice() > b.getPrice();
    }
    return false;
}

bool compareCustomer(const Customer &a, const Customer &b, int sortType, bool ascending)
{
    if (sortType == 1)
    { // Sắp xếp theo ID
        return ascending ? a.getId() < b.getId() : a.getId() > b.getId();
    }
    else if (sortType == 2)
    { // Sắp xếp theo MemberType
        return ascending ? a.getMemberType() < b.getMemberType() : a.getMemberType() > b.getMemberType();
    }
    else if (sortType == 3)
    { // Sắp xếp theo LoyaltyPoints
        return ascending ? a.getLoyaltyPoints() < b.getLoyaltyPoints() : a.getLoyaltyPoints() > b.getLoyaltyPoints();
    }
    return false;
}

int getPositionPriority(const std::string &position, const std::vector<std::string> &positionOrder)
{
    for (int i = 0; i < positionOrder.size(); ++i)
    {
        if (positionOrder[i] == position)
        {
            return i;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int dateToInt(const std::string &date)
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    return (year * 10000) + (month * 100) + day;
}

bool compareEmployee(const Employee &a, const Employee &b, int sortType, bool ascending)
{
    if (sortType == 4)
    {
        int dateA = dateToInt(a.getDateHired());
        int dateB = dateToInt(b.getDateHired());
        return ascending ? dateA > dateB : dateA < dateB;
    }
    else if (sortType == 1)
    {
        return ascending ? a.getId() < b.getId() : a.getId() > b.getId();
    }
    else if (sortType == 2)
    {
        static const vector<string> positionOrder = {"Staff", "Supervisor", "Manager", "Assistant Manager"};

        int priorityA = getPositionPriority(a.getPosition(), positionOrder);
        int priorityB = getPositionPriority(b.getPosition(), positionOrder);
        return ascending ? priorityA < priorityB : priorityA > priorityB;
    }
    else if (sortType == 3)
    {
        return ascending ? a.getSalary() < b.getSalary() : a.getSalary() > b.getSalary();
    }
    return false;
}

void Supermarket::sortData()
{
    int choice;
    cout << "1. Sort Products\n2. Sort Customers\n3. Sort Employees\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int sortType;
    bool ascending;

    switch (choice)
    {
    case 1:
        cout << "Sort Products by:\n1. ID\n2. Price\nEnter your choice: ";
        cin >> sortType;
        cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
        cin >> ascending;
        sort(inventory.begin(), inventory.end(),
             [&](const Product &a, const Product &b)
             { return compareProduct(a, b, sortType, ascending); });
        cout << "-------------------------------------------------------------" << endl;
        cout << "Products sorted.\n";
        cout << "-------------------------------------------------------------" << endl;
        break;
    case 2:
        cout << "Sort Customers by:\n1. ID\n2. Member Type\n3. Loyalty Points\nEnter your choice: ";
        cin >> sortType;
        cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
        cin >> ascending;
        sort(customers.begin(), customers.end(),
             [&](const Customer &a, const Customer &b)
             { return compareCustomer(a, b, sortType, ascending); });
        cout << "-------------------------------------------------------------" << endl;
        cout << "Customers sorted.\n";
        cout << "-------------------------------------------------------------" << endl;
        break;
    case 3:
        cout << "Sort Employees by:\n1. ID\n2. Position\n3. Salary\n4. Date Hired\nEnter your choice: ";
        cin >> sortType;
        cout << "Sort order:\n0. Descending\n1. Ascending\nEnter your choice: ";
        cin >> ascending;
        sort(employees.begin(), employees.end(),
             [&](const Employee &a, const Employee &b)
             { return compareEmployee(a, b, sortType, ascending); });
        cout << "-------------------------------------------------------------" << endl;
        cout << "Employees sorted.\n";
        cout << "-------------------------------------------------------------" << endl;
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
