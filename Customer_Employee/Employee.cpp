#include "../Class headers/Employee.h"

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
