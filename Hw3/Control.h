#pragma once
#include "base.h"

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

class Review {
public:
	Review() {};
	string selectProduct(string reviewProduct, int reviewPoint);
};