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

// Class : Seller
// Description : Seller entity class
// Created : 2022/6/2 03:08 am
// Author : Ȳ����
// mail : yooni0704@gmail.com
// Revisions :
//   1. When& Who :
//      What :
class Seller : Member
{
private:
	int* registationList;
	int registationCount;
public:
	Seller(Member* member);
	virtual void addRegistationProduct(int registation);
	virtual int* getRegistationProduct();
	virtual int getRegistationCount();
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
// Class : Registation
// Description : �Ǹ� �Ƿ� ��� control Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :
class Registation
{
public:
	void setProduct(string, string, int, int, string);
};

// Class : CheckSale
// Description : ��� ��ǰ ��ȸ control Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :
class CheckSale
{
public:
	string searchCheckSale();
};

// Class : Soldout
// Description : �Ǹ� �Ϸ� ��ǰ ��ȸ control Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :
class Soldout
{
public:
	string searchSoldout();
};

// Class : SaleStatistic
// Description : �Ǹ� ��ǰ ��� control Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :

class SaleStatistic
{
public:
	string searchSaleStatistic();
};

// Class : Registation
// Description : �Ǹ� �Ƿ� ��� boundary Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :

class RegistationUI
{
public:
	void enterProduct(Registation*);
};
// Class : CheckSaleUI
// Description : ��� ��ǰ ��ȸ boundary Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :

class CheckSaleUI
{
public:
	void printCheckSale(CheckSale*);
};

// Class : SoldoutUI
// Description : �Ǹ� �Ϸ� ��ǰ ��ȸ boundary Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :


class SoldoutUI
{
public:
	void printSoldout(Soldout*);
};

// Class : SaleStatistic
// Description : �Ǹ� ��ǰ ��� boundary Ŭ����
// Created : 2022/6/2 3:36 am
// Author : Ȳ����
// mail : yooni0704@gamil.com
// Revisions :
//	1. When& Who :
//	   What :


class SaleStatisticUI
{
public:
	void printSaleStatistic(SaleStatistic*);
};

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

class Purchase;
class PurchaseUI {
private:
public:
	PurchaseUI();
	void clickPurchase(Purchase*);
	~PurchaseUI();
};

class PurchasedList;
class PurchasedListUI {
public:
	PurchasedListUI();
	void searchPurchasedList(PurchasedList*);
};

class Review;
class ReviewUI {
private:
	string reviewProduct;
	int reviewPoint;
public:
	ReviewUI() {};
	void selectProduct(Review*);
};

class Search {
private:

public:
	Search();
	string showProduct(string searchKeyword);
	~Search();
};

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

class PurchasedList {
public:
	PurchasedList();
	string getPurchasedProduct();
	string listPurchasedProduct(int purchased);
};

class Review {
public:
	Review() {};
	string selectProduct(string reviewProduct, int reviewPoint);
};





