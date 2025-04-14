#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
private:
    string position;
    float salary;
    string dateHired;

public:
    Employee();

    void in() override;
    void out() const override;

    void updateSalary(float newSalary);
    void promote(const string &newPosition);

    string getPosition() const;
    void setPosition(const string &pos);
    float getSalary() const;
    string getDateHired() const;
};

#endif
