#include "base.h"

// Class : Member
// Description : ȸ�� entity class
// Created : 2022/5/27 12:50 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Member
{

private:
    string ID;
    string password;
    string SSN;
    string name;

public:
    Member() {}
    Member(string, string, string, string);
    bool createMember(Member*);
    string validateID();
    string validatePW();
    void deleteMember();

    virtual void addPurchasedProduct(int purchased) {}
    virtual int* getPurchasedProduct() { return 0; }
    virtual int getPurchasedCount() { return 0; };

};

class Buyer : Member
{
private:
    int* purchasedList; //������ ���� ��ȣ list
    int purchasedCount;//������ ���� ��
public:
    Buyer(Member* member);
    virtual void addPurchasedProduct(int purchased);
    virtual int* getPurchasedProduct();
    virtual int getPurchasedCount();

};



// Class : Product
// Description : Product entity class
// Created : 2022/5/30 11:19 am
// Author : Ȳ����
// mail : yooni0704@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Product {
private:
    string Name;
    string Company;
    int Price;
    int Registation;
    int Purchased;
    double Review;
    string Seller;

    //�ֱ� �˻� ����
    bool recentSearched;

public:
    Product();
    void SetProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID);
    void setName(string ProductName);
    void setCompany(string CompanyName);
    void setSeller(string SellerID);
    void setRegistation(int RegistationQuantity);
    void setPurchased(int PurchasedQuantity);
    void setPrice(int ProductPrice);
    void setReview(double AverageReview);
    string getName();
    string getCompany();
    string getSeller();
    int getRegistation();
    int getPurchased();
    int getPrice();
    double getReview();
    bool getRecentSearched();
    void setRecentSearched();

    void modifyProductQuantity();
    string getProductDetail();
    void modifyProductReview(int reviewPoint);
    ~Product();
};
