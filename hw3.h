#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

void doTask();

// Class : SignUpUI
// Description : ȸ������ boundary class
// Created : 2022/5/27 12:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class SignUp;
class SignUpUI
{
private:

public:
    void enterMemberInfo(SignUp*);
    //void startInterface();
    //void sendSignUpmsg();


};


// Class : SignUp
// Description : ȸ������ control class
// Created : 2022/5/27 12:46 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class SignUp
{
private:

public:

    bool createNewMember(string, string, string, string);

};


// Class : Member
// Description : ȸ�� entity class
// Created : 2022/5/27 12:50 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
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
    Member(string, string, string, string);
    bool createMember(Member*);
    string validateID();
    string validatePW();
    void deleteMember();

};

// Class : LoginUI
// Description : �α��� boundary class
// Created : 2022/5/27 5:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//
class Login;
class LoginUI
{
private:

public:
    void enterIDPW(Login*);
    //void startInterface();
    //void sendSignUpmsg();
};


// Class : Login
// Description : �α��� control class
// Created : 2022/5/27 5:48 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class Login
{
private:

public:

    bool validateID(string, string);

};

class Registation
{
public:
    void setProduct(string, string, int, int, string);
};

class RegistationUI
{
public:
    void enterProduct(Registation*);
};

class CheckSale
{
public:
    string searchCheckSale(int);
};

class CheckSaleUI
{
public:
    void printCheckSale(CheckSale*);
};

class Soldout
{
public:
    string searchSoldout(int);
};

class SoldoutUI
{
public:
    void printSoldout(Soldout*);
};

class SaleStatistic
{
public:
    string searchSaleStatistic(int);
};

class SaleStatisticUI
{
public:
    void printSaleStatistic(SaleStatistic*);
};

// Class : Product
// Description : Product entity class
// Created : 2022/5/30 11:19 am
// Author : Ȳ����
// mail : yooni0704@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
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

public:
    Product() {}

    void SetProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID)
    {
        Name = ProductName;
        Company = CompanyName;
        Price = ProductPrice;
        Registation = RegistationQuantity;
        Purchased = 0;
        Review = 0;
        Seller = SellerID;
    }
    void setName(string ProductName)
    {
        Name = ProductName;
    }
    void setCompany(string CompanyName)
    {
        Company = CompanyName;
    }
    void setSeller(string SellerID)
    {
        Seller = SellerID;
    }
    void setRegistation(int RegistationQuantity)
    {
        Registation = RegistationQuantity;
    }
    void setPurchased(int PurchasedQuantity)
    {
        Purchased = PurchasedQuantity;
    }
    void setPrice(int ProductPrice)
    {
        Price = ProductPrice;
    }
    void setReview(double AverageReview)
    {
        Review = AverageReview;
    }
    string getName()
    {
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    string getSeller()
    {
        return Seller;
    }
    int getRegistation()
    {
        return Registation;
    }
    int getPurchased()
    {
        return Purchased;
    }
    int getPrice()
    {
        return Price;
    }
    double getReview()
    {
        return Review;
    }


    ~Product() {}
};




