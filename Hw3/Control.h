#pragma once
#include "base.h"

// Class : SignUp
// Description : 회원가입 control class
// Created : 2022/5/27 12:46 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class SignUp
{
private:

public:
	SignUp() {};
	bool createNewMember(string, string, string, string);

};


// Class : Login
// Description : 로그인 control class
// Created : 2022/5/27 5:48 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//   1. When& Who :
//      What :
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