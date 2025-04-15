#include "../Class headers/Customer.h"

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
