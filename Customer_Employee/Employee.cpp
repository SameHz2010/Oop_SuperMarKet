#include "../Class headers/Employee.h"

Employee::Employee()
{
    position = "Staff";
    salary = 0.0f;
    dateHired = "";
}

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

void Employee::out() const
{
    cout << left << setw(10) << id << setw(20) << name << setw(15) << phone
         << setw(20) << position << setw(15) << salary << setw(10) << dateHired << endl;
}

void Employee::setSalary(double newSalary)
{
    if (newSalary >= 0)
    {
        this->salary = newSalary;
    }
}

string Employee::getPosition() const
{
    return position;
}

void Employee::setPosition(const string &pos)
{
    this->position = pos;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setDateHired(const string &DateHired)
{
    this->dateHired = DateHired;
}

string Employee::getDateHired() const
{
    return dateHired;
}
