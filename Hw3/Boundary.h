#pragma once
#include "base.h"
#include "Control.h"


// Class : SignUpUI
// Description : ȸ������ boundary class
// Created : 2022/5/27 12:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class SignUpUI
{
private:

public:
    void enterMemberInfo(SignUp*);
    //void startInterface();
    //void sendSignUpmsg();


};

// Class : LoginUI
// Description : �α��� boundary class
// Created : 2022/5/27 5:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class LoginUI
{
private:

public:
    void enterIDPW(Login*);
    //void startInterface();
    //void sendSignUpmsg();
};


class RegistationUI
{
public:
    void enterProduct(Registation*);
};


class CheckSaleUI
{
public:
    void printCheckSale(CheckSale*);
};


class SoldoutUI
{
public:
    void printSoldout(Soldout*);
};


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
class PurchasedListUI {
public:
    PurchasedListUI();
    void searchPurchasedList(PurchasedList*);
};

// Class : class ReviewUI
// Description : ������ �� boundary class
// Created : 2022/6/1 16:51 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
class ReviewUI {
private:
    string reviewProduct;
    int reviewPoint;
public:
    ReviewUI() {};
    void selectProduct(Review*);
};