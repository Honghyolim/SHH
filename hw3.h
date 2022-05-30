#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

void doTask();

// Class : SignUpUI
// Description : 회원가입 boundary class
// Created : 2022/5/27 12:47 pm
// Author : 홍효림
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
// Description : 회원가입 control class
// Created : 2022/5/27 12:46 pm
// Author : 홍효림
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
// Description : 회원 entity class
// Created : 2022/5/27 12:50 pm
// Author : 홍효림
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
// Description : 로그인 boundary class
// Created : 2022/5/27 5:47 pm
// Author : 홍효림
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
// Description : 로그인 control class
// Created : 2022/5/27 5:48 pm
// Author : 홍효림
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



// Class : Product
// Description : Product entity class
// Created : 2022/5/30 11:19 am
// Author : 황성윤
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
    string getName()
    {
        return Name;
    }  string getCompany()
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





