#include "../Class headers/Person.h"
#include "../Class headers/Customer.h"
#include "../Class headers/Employee.h"

// Các hàm định nghĩa
string Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

void Person::setName(const string &name)
{
    this->name = name;
}

string Person::getPhone() const
{
    return phone;
}

void Person::setPhone(const string &phone)
{
    this->phone = phone;
}

// Constructor
Customer::Customer()
{
    memberType = "Regular"; // Mặc định là khách hàng thông thường
    loyaltyPoints = 0;
}

// Nhập thông tin khách hàng
void Customer::in()
{
    cout << "Nhap ID: ";
    cin >> id;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    cout << "Nhap loai thanh vien (Regular/VIP): ";
    getline(cin, memberType);
    cout << "Nhap diem tich luy: ";
    cin >> loyaltyPoints;
}

// Xuất thông tin khách hàng
void Customer::out() const
{
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Loai thanh vien: " << memberType << endl;
    cout << "Diem tich luy: " << loyaltyPoints << endl;
}

// Trả về mức giảm giá dựa trên loại thành viên
float Customer::getDiscountRate() const
{
    if (memberType == "VIP")
    {
        return 0.1f; // Giảm 10%
    }
    return 0.0f; // Không giảm
}

// Cộng thêm điểm tích lũy
void Customer::addLoyaltyPoints(int points)
{
    if (points > 0)
    {
        loyaltyPoints += points;
    }
}

// Reset điểm tích lũy về 0
void Customer::resetLoyaltyPoints()
{
    loyaltyPoints = 0;
}

// Getter cho loại thành viên
string Customer::getMemberType() const
{
    return memberType;
}

// Setter cho loại thành viên
void Customer::setMemberType(const string &type)
{
    memberType = type;
}

// Getter cho điểm tích lũy
int Customer::getLoyaltyPoints() const
{
    return loyaltyPoints;
}

// Constructor
Employee::Employee()
{
    position = "Staff";
    salary = 0.0f;
    dateHired = "";
}

// Nhập thông tin nhân viên
void Employee::in()
{
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
void Employee::out() const
{
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Chuc vu: " << position << endl;
    cout << "Luong: " << salary << endl;
    cout << "Ngay vao lam: " << dateHired << endl;
}

// Cập nhật lương
void Employee::updateSalary(float newSalary)
{
    if (newSalary >= 0)
    {
        salary = newSalary;
    }
}

// Thăng chức (cập nhật chức vụ)
void Employee::promote(const string &newPosition)
{
    position = newPosition;
}

// Getter cho chức vụ
string Employee::getPosition() const
{
    return position;
}

// Setter cho chức vụ
void Employee::setPosition(const string &pos)
{
    position = pos;
}

// Getter cho lương
float Employee::getSalary() const
{
    return salary;
}

// Getter cho ngày vào làm
string Employee::getDateHired() const
{
    return dateHired;
}
