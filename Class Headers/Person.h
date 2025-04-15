#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>

using namespace std;

class Person
{
protected:
    string id;
    string name;
    string phone;

public:
    Person() {}
    virtual ~Person() {}

    virtual void in() = 0;
    virtual void out() const = 0;

    string getId() const;
    void setId(const string &id);
    string getName() const;
    void setName(const string &name);
    string getPhone() const;
    void setPhone(const string &phone);
};

#endif
