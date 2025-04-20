#include "../Class headers/Customer.h"

// Constructor
Customer::Customer()
{
    memberType = "Regular";
    loyaltyPoints = 0;
}

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

void Customer::out() const
{
    cout << left << setw(10) << id << setw(20) << name << setw(15) << phone
         << setw(15) << memberType << setw(10) << loyaltyPoints << endl;
}

float Customer::getDiscountRate() const
{
    if (memberType == "VIP")
    {
        return 0.1f;
    }
    return 0.0f;
}

void Customer::addLoyaltyPoints(int points)
{
    if (points > 0)
    {
        loyaltyPoints += points;
    }
}

void Customer::resetLoyaltyPoints()
{
    loyaltyPoints = 0;
}

string Customer::getMemberType() const
{
    return memberType;
}

void Customer::setMemberType(const string &type)
{
    memberType = type;
}

int Customer::getLoyaltyPoints() const
{
    return loyaltyPoints;
}
