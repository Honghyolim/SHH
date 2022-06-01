#pragma once
#include "base.h"

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

class Review {
public:
	Review() {};
	string selectProduct(string reviewProduct, int reviewPoint);
};