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
//	1. When& Who : 2022/06/01 3:12 pm by ȫȿ��
//	   What : control atrribute �߰�, ������ ����
// 
//

class SignUp;
class SignUpUI
{
private:
	SignUp* control;
public:
	SignUpUI(SignUp*);
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
//	1. When& Who : 2022/06/01 3:13 pm by ȫȿ��
//	   What : createBoundary �Լ� �߰�, ������ ����
// 
//

class SignUp
{
private:
	SignUpUI* createBoundary(SignUp*);
public:
	SignUp();
	bool createNewMember(string, string, string, string);

};
class SignOutUI;
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
	void deleteMember(SignOutUI*);

	virtual void addPurchasedProduct(int purchased) {}
	virtual int* getPurchasedProduct() { return 0; }
	virtual int getPurchasedCount() { return 0; };

};

// Class : Buyer
// Description : ������ entity class
// Created : 2022/6/1 6:50 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
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

// Class : LoginUI
// Description : �α��� boundary class
// Created : 2022/5/27 5:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by ȫȿ��
//	   What : control atrribute �߰�, ������ ����
// 
//
class Login;
class LoginUI
{
private:
	Login* control;
public:
	LoginUI(Login*);
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
//	1. When& Who : 2022/06/01 3:05 pm by ȫȿ��
//	   What : createBoundary �Լ� �߰�, ������ ����
// 
//

class Login
{
private:
	LoginUI* createBoundary(Login*);
public:
	Login();
	bool validateID(string, string);

};

// Class : SignOutUI
// Description : ȸ��Ż�� boundary Ŭ����
// Created : 2022/6/1 12:50 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 
//	   What : 
// 
//

class SignOut;
class SignOutUI
{
private:
	SignOut* control;
public:
	SignOutUI(SignOut*);
	void sendSignOutMsg(string);
};

// Class : SignOut
// Description : ȸ��Ż�� control Ŭ����
// Created : 2022/6/1 12:50 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class SignOut
{
private:
	SignOutUI* createBoundary(SignOut*);
public:
	SignOut();
	void deleteMember(SignOutUI*);
};

// Class : LogOutUI
// Description : �α׾ƿ� boundary Ŭ����
// Created : 2022/6/1 2:28 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class LogOut;
class LogOutUI
{
private:
	LogOut* control;
public:
	LogOutUI(LogOut*);
	void sendLogOutMsg(string);
};

// Class : LogOut
// Description : �α׾ƿ� control Ŭ����
// Created : 2022/6/1 2:30 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class LogOut
{
private:
	LogOutUI* createBoundary(LogOut*);
public:
	LogOut();
	void logOut(LogOutUI*);
};
class Registation;
class RegistationUI
{
public:
	void enterProduct(Registation*);
};

class CheckSale;
class CheckSaleUI
{
public:
	void printCheckSale(CheckSale*);
};

class Soldout;
class SoldoutUI
{
public:
	void printSoldout(Soldout*);
};

class SaleStatistic;
class SaleStatisticUI
{
public:
	void printSaleStatistic(SaleStatistic*);
};

// Class : SearchUI
// Description : �˻� boundary class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Search;
class SearchUI {
private:
	string searchKeyword;

public:
	SearchUI();
	void enterProductName(Search*);
	void showProduct(string result);//control -> boundary ��� 
	~SearchUI();
};

// Class : PurchaseUI
// Description : ���� boundary class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Purchase;
class PurchaseUI {
private:
public:
	PurchaseUI();
	void clickPurchase(Purchase*);
	~PurchaseUI();
};

// Class : PurchasedListUI
// Description : ��ǰ ���� ���� ��ȸ boundary class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class PurchasedList;
class PurchasedListUI {
public:
	PurchasedListUI();
	void searchPurchasedList(PurchasedList*);
};

// Class : ReviewUI
// Description : ������ �� boundary class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Review;
class ReviewUI {
private:
	string reviewProduct;
	int reviewPoint;
public:
	ReviewUI() {};
	void selectProduct(Review*);
};

class Registation
{
public:
	void setProduct(string, string, int, int, string);
};


class CheckSale
{
public:
	bool searchCheckSale(int);
};


class Soldout
{
public:
	bool searchSoldout(int);
};


class SaleStatistic
{
public:
	bool searchSaleStatistic(int);
};

// Class : Search
// Description : �˻� control class
// Created : 2022/6/1 5:36 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Search {
private:

public:
	Search();
	string showProduct(string searchKeyword);
	~Search();
};

// Class : Purchase
// Description : ��ǰ ���� control class
// Created : 2022/6/1 5:36 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Purchase {
private:
	string recentSearchWord;
	string result;

public:
	Purchase();
	void modifyProductQuantity();
	void addPurchaseProduct();
	string showPurchaseFinish();
};

// Class : PurchasedList
// Description : ��ǰ ���� ���� ��ȸ control class
// Created : 2022/6/1 5:36 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class PurchasedList {
public:
	PurchasedList();
	string getPurchasedProduct();
	string listPurchasedProduct(int purchased);
};

// Class : Review
// Description : ������ �� control class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Review {
public:
	Review() {};
	string selectProduct(string reviewProduct, int reviewPoint);
};




