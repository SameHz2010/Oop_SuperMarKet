#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
private:
    string position;
    double salary;
    string dateHired;

public:
    Employee();

    void in() override;
    void out() const override;

    void setSalary(double newSalary);

    string getPosition() const;
    void setPosition(const string &pos);
    double getSalary() const;
    void setDateHired(const string &DateHired);
    string getDateHired() const;
};

#endif
