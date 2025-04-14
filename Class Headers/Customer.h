#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person
{
private:
    string memberType;
    int loyaltyPoints;

public:
    Customer();

    void in() override;
    void out() const override;

    float getDiscountRate() const;
    void addLoyaltyPoints(int points);
    void resetLoyaltyPoints();

    string getMemberType() const;
    void setMemberType(const string &type);
    int getLoyaltyPoints() const;
};

#endif
