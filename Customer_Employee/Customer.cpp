#include "../Class headers/Customer.h"

// Constructor
Customer::Customer() {
    memberType = "Regular"; // Mặc định là khách hàng thông thường
    loyaltyPoints = 0;
}

// Nhập thông tin khách hàng
void Customer::in() {
    cout << "Nhap ID: ";
    cin >> id;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    cout << "Nhap loai thanh vien (Regular/VIP): ";
    getline(cin, memberType);
    cout << "Nhap diem tich luy: ";
    cin >> loyaltyPoints;
}

// Xuất thông tin khách hàng
void Customer::out() const {
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Loai thanh vien: " << memberType << endl;
    cout << "Diem tich luy: " << loyaltyPoints << endl;
}

// Trả về mức giảm giá dựa trên loại thành viên
float Customer::getDiscountRate() const {
    if (memberType == "VIP") {
        return 0.1f; // Giảm 10%
    }
    return 0.0f; // Không giảm
}

// Cộng thêm điểm tích lũy
void Customer::addLoyaltyPoints(int points) {
    if (points > 0) {
        loyaltyPoints += points;
    }
}

// Reset điểm tích lũy về 0
void Customer::resetLoyaltyPoints() {
    loyaltyPoints = 0;
}

// Getter cho loại thành viên
string Customer::getMemberType() const {
    return memberType;
}

// Setter cho loại thành viên
void Customer::setMemberType(const string &type) {
    memberType = type;
}

// Getter cho điểm tích lũy
int Customer::getLoyaltyPoints() const {
    return loyaltyPoints;
}
