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
//	1. When& Who : 2022/06/01 3:12 pm by 홍효림
//	   What : control atrribute 추가, 생성자 선언
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
// Description : 회원가입 control class
// Created : 2022/5/27 12:46 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:13 pm by 홍효림
//	   What : createBoundary 함수 추가, 생성자 선언
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
// Description : 구매자 entity class
// Created : 2022/6/1 6:50 pm
// Author : 서준택
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class Buyer : Member
{
private:
	int* purchasedList; //구매한 물건 번호 list
	int purchasedCount;//구매한 물건 수
public:
	Buyer(Member* member);
	virtual void addPurchasedProduct(int purchased);
	virtual int* getPurchasedProduct();
	virtual int getPurchasedCount();

};

// Class : Product
// Description : Product entity class
// Created : 2022/5/30 11:19 am
// Author : 황성윤
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

	//최근 검색 여부
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
// Description : 로그인 boundary class
// Created : 2022/5/27 5:47 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by 홍효림
//	   What : control atrribute 추가, 생성자 선언
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
// Description : 로그인 control class
// Created : 2022/5/27 5:48 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by 홍효림
//	   What : createBoundary 함수 추가, 생성자 선언
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
// Description : 회원탈퇴 boundary 클래스
// Created : 2022/6/1 12:50 pm
// Author : 홍효림
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
// Description : 회원탈퇴 control 클래스
// Created : 2022/6/1 12:50 pm
// Author : 홍효림
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
// Description : 로그아웃 boundary 클래스
// Created : 2022/6/1 2:28 pm
// Author : 홍효림
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
// Description : 로그아웃 control 클래스
// Created : 2022/6/1 2:30 pm
// Author : 홍효림
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
// Description : 검색 boundary class
// Created : 2022/6/1 16:51 pm
// Author : 서준택
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
	void showProduct(string result);//control -> boundary 결과 
	~SearchUI();
};

// Class : PurchaseUI
// Description : 구매 boundary class
// Created : 2022/6/1 16:51 pm
// Author : 서준택
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
// Description : 상품 구매 내역 조회 boundary class
// Created : 2022/6/1 16:51 pm
// Author : 서준택
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
// Description : 만족도 평가 boundary class
// Created : 2022/6/1 16:51 pm
// Author : 서준택
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
// Description : 검색 control class
// Created : 2022/6/1 5:36 pm
// Author : 서준택
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
// Description : 상품 구매 control class
// Created : 2022/6/1 5:36 pm
// Author : 서준택
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
// Description : 상품 구매 내역 조회 control class
// Created : 2022/6/1 5:36 pm
// Author : 서준택
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
// Description : 만족도 평가 control class
// Created : 2022/6/1 16:51 pm
// Author : 서준택
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





