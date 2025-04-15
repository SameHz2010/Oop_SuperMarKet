#include "../Class Headers/Person.h"

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