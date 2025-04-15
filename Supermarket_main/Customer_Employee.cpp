#include "../Class headers/Person.h"
#include "../Class headers/Customer.h"
#include "../Class headers/Employee.h"

string Person::getId() const
{
    return id;
}

void Person::setId(const string &id)
{
    this->id = id;
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
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Phone number: ";
    getline(cin, phone);
    cout << "Member type (Regular/VIP): ";
    getline(cin, memberType);
    cout << "Loyalty points: ";
    cin >> loyaltyPoints;
}

// Xuất thông tin khách hàng
void Customer::out() const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone number: " << phone << endl;
    cout << "Member type: " << memberType << endl;
    cout << "Loyalty points: " << loyaltyPoints << endl;
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
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Phone number: ";
    getline(cin, phone);
    cout << "Position: ";
    getline(cin, position);
    cout << "Salary: ";
    cin >> salary;
    cin.ignore();
    cout << "Hired date (dd/mm/yyyy): ";
    getline(cin, dateHired);
}

// Xuất thông tin nhân viên
void Employee::out() const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone number: " << phone << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
    cout << "Hired date (dd/mm/yyyy): " << dateHired << endl;
}

// Cập nhật lương
void Employee::setSalary(double newSalary)
{
    if (newSalary >= 0)
    {
        this->salary = newSalary;
    }
}

// Getter cho chức vụ
string Employee::getPosition() const
{
    return position;
}

// Setter cho chức vụ
void Employee::setPosition(const string &pos)
{
    this->position = pos;
}

// Getter cho lương
double Employee::getSalary() const
{
    return salary;
}

void Employee::setDateHired(const string &DateHired)
{
    this->dateHired = DateHired;
}

// Getter cho ngày vào làm
string Employee::getDateHired() const
{
    return dateHired;
}
