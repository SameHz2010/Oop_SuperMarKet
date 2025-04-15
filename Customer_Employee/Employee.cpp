#include "../Class headers/Employee.h"

// Constructor
Employee::Employee() {
    position = "Staff";
    salary = 0.0f;
    dateHired = "";
}

// Nhập thông tin nhân viên
void Employee::in() {
    cout << "Nhap ID: ";
    cin >> id;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    cout << "Nhap chuc vu: ";
    getline(cin, position);
    cout << "Nhap luong: ";
    cin >> salary;
    cin.ignore();
    cout << "Nhap ngay vao lam (dd/mm/yyyy): ";
    getline(cin, dateHired);
}

// Xuất thông tin nhân viên
void Employee::out() const {
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Chuc vu: " << position << endl;
    cout << "Luong: " << salary << endl;
    cout << "Ngay vao lam: " << dateHired << endl;
}

// Cập nhật lương
void Employee::updateSalary(float newSalary) {
    if (newSalary >= 0) {
        salary = newSalary;
    }
}

// Thăng chức (cập nhật chức vụ)
void Employee::promote(const string &newPosition) {
    position = newPosition;
}

// Getter cho chức vụ
string Employee::getPosition() const {
    return position;
}

// Setter cho chức vụ
void Employee::setPosition(const string &pos) {
    position = pos;
}

// Getter cho lương
float Employee::getSalary() const {
    return salary;
}

// Getter cho ngày vào làm
string Employee::getDateHired() const {
    return dateHired;
}
