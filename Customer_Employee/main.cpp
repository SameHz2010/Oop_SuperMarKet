#include <iostream>
#include <vector>
#include <algorithm>
#include "../Class headers/Customer.h"
#include "../Class headers/Employee.h"
#include "../Class headers/Person.h"

using namespace std;
 
// ======= HÀM HỖ TRỢ CHUNG =======

void pause() {
    cout << "Nhan phim Enter de tiep tuc...";
    cin.ignore();
    cin.get();
}

// ======= CUSTOMER FUNCTIONS =======

void addCustomer(vector<Customer> &customers) {
    Customer c;
    c.in();
    customers.push_back(c);
}

void editCustomer(vector<Customer> &customers) {
    string id;
    cout << "Nhap ID khach hang can sua: ";
    cin >> id;
    bool found = false;
    for (auto &c : customers) {
        if (c.getId() == id) {
            cout << "Thong tin cu:\n";
            c.out();
            cout << "\nNhap thong tin moi:\n";
            c.in();
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay khach hang!\n";
}

void deleteCustomer(vector<Customer> &customers) {
    string id;
    cout << "Nhap ID khach hang can xoa: ";
    cin >> id;
    auto it = remove_if(customers.begin(), customers.end(), [&](Customer &c) {
        return c.getId() == id;
    });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "Da xoa thanh cong!\n";
    } else {
        cout << "Khong tim thay khach hang!\n";
    }
}

void searchCustomer(const vector<Customer> &customers) {
    int choice;
    cout << "1. Tim theo ID\n2. Tim theo ten\nChon: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        string id;
        cout << "Nhap ID: ";
        cin >> id;
        for (const auto &c : customers) {
            if (c.getId() == id) {
                c.out();
                return;
            }
        }
    } else {
        string name;
        cout << "Nhap ten: ";
        getline(cin, name);
        for (const auto &c : customers) {
            if (c.getName().find(name) != string::npos) {
                c.out();
                cout << "-----------------\n";
            }
        }
    }
}

void displayCustomers(const vector<Customer> &customers) {
    cout << "--- Danh sach khach hang ---\n";
    for (const auto &c : customers) {
        c.out();
        cout << "-----------------\n";
    }
}

// ======= EMPLOYEE FUNCTIONS =======

void addEmployee(vector<Employee> &employees) {
    Employee e;
    e.in();
    employees.push_back(e);
}

void editEmployee(vector<Employee> &employees) {
    string id;
    cout << "Nhap ID nhan vien can sua: ";
    cin >> id;
    bool found = false;
    for (auto &e : employees) {
        if (e.getId() == id) {
            cout << "Thong tin cu:\n";
            e.out();
            cout << "\nNhap thong tin moi:\n";
            e.in();
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay nhan vien!\n";
}

void deleteEmployee(vector<Employee> &employees) {
    string id;
    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
    auto it = remove_if(employees.begin(), employees.end(), [&](Employee &e) {
        return e.getId() == id;
    });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Da xoa thanh cong!\n";
    } else {
        cout << "Khong tim thay nhan vien!\n";
    }
}

void searchEmployee(const vector<Employee> &employees) {
    int choice;
    cout << "1. Tim theo ID\n2. Tim theo ten\nChon: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        string id;
        cout << "Nhap ID: ";
        cin >> id;
        for (const auto &e : employees) {
            if (e.getId() == id) {
                e.out();
                return;
            }
        }
    } else {
        string name;
        cout << "Nhap ten: ";
        getline(cin, name);
        for (const auto &e : employees) {
            if (e.getName().find(name) != string::npos) {
                e.out();
                cout << "-----------------\n";
            }
        }
    }
}

void displayEmployees(const vector<Employee> &employees) {
    cout << "--- Danh sach nhan vien ---\n";
    for (const auto &e : employees) {
        e.out();
        cout << "-----------------\n";
    }
}

void promoteEmployee(vector<Employee> &employees) {
    string id, newPos;
    cout << "Nhap ID nhan vien: ";
    cin >> id;
    cin.ignore();
    cout << "Nhap chuc vu moi: ";
    getline(cin, newPos);
    for (auto &e : employees) {
        if (e.getId() == id) {
            e.promote(newPos);
            cout << "Da phan quyen thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien!\n";
}

// ======= MENU FUNCTION =======

void inMenu() {
    vector<Customer> customers;
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n====== MENU CHINH ======\n";
        cout << "1. Quan ly khach hang\n";
        cout << "2. Quan ly nhan vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int cChoice;
                do {
                    cout << "\n-- QUAN LY KHACH HANG --\n";
                    cout << "1. Them khach hang\n";
                    cout << "2. Sua khach hang\n";
                    cout << "3. Xoa khach hang\n";
                    cout << "4. Tim khach hang\n";
                    cout << "5. Hien thi danh sach\n";
                    cout << "0. Quay lai\n";
                    cout << "Chon: ";
                    cin >> cChoice;
                    switch (cChoice) {
                        case 1: addCustomer(customers); break;
                        case 2: editCustomer(customers); break;
                        case 3: deleteCustomer(customers); break;
                        case 4: searchCustomer(customers); break;
                        case 5: displayCustomers(customers); break;
                    }
                    pause();
                } while (cChoice != 0);
                break;
            }
            case 2: {
                int eChoice;
                do {
                    cout << "\n-- QUAN LY NHAN VIEN --\n";
                    cout << "1. Them nhan vien\n";
                    cout << "2. Sua nhan vien\n";
                    cout << "3. Xoa nhan vien\n";
                    cout << "4. Tim nhan vien\n";
                    cout << "5. Hien thi danh sach\n";
                    cout << "6. Phan quyen nhan vien\n";
                    cout << "0. Quay lai\n";
                    cout << "Chon: ";
                    cin >> eChoice;
                    switch (eChoice) {
                        case 1: addEmployee(employees); break;
                        case 2: editEmployee(employees); break;
                        case 3: deleteEmployee(employees); break;
                        case 4: searchEmployee(employees); break;
                        case 5: displayEmployees(employees); break;
                        case 6: promoteEmployee(employees); break;
                    }
                    pause();
                } while (eChoice != 0);
                break;
            }
            case 0: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (choice != 0);
}

// ======= MAIN FUNCTION =======

int main() {
    inMenu();
    return 0;
}
