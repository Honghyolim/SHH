#pragma once
#include "Entity.h"


//���� �α����� ����� ID�� �����ϴ� ��������
extern string MemberID;
//��ϵ� ��ǰ�� ���ڸ� �����ϴ� ��������
extern int productnumber;
// Product �����ϴ� ����Ʈ ��������
extern Product product[100];
extern int memberCnt;
// Member �����ϴ� ����Ʈ ��������
extern Member* memberList[100];

//Function : Member(string ID, string password, string SSN, string name)
//Description: Member Ŭ���� ������
//
//
//Parameters : ID - ���Խ� �Է��� id, password - ���Խ� �Է��� ���, SSN - ���Խ� �Է��� �ֹι�ȣ, name - ���Խ� �Է��� �̸�
//Return Value : void
//Created : 2022/05/27 3:14 pm 
//author : Hong Hyolim
//Revisions :
//
Member::Member(string ID, string password, string SSN, string name)
{
    this->ID = ID;
    this->password = password;
    this->SSN = SSN;
    this->name = name;
}


//Function : bool createMember(Member* nMember)
//Description: memberList�� ��� �߰��ϴ� �Լ�
//
//
//Parameters : nMember - ���ο� ����� ����Ű�� ������
//Return Value : ȸ�������� �Ǿ����� Ȯ���ϴ� ��
//Created : 2022/05/27 3:14 pm 
//author : Hong Hyolim
//Revisions :
//
bool Member::createMember(Member* nMember)
{
    memberList[memberCnt] = nMember;
    memberCnt++;
    return true;
}

//Function : void deleteMember(signOutUI* boundary);
//Description: ȸ������Ʈ���� �����ϰ� �������Լ��� �θ��� �Լ�
//
//Parameters : signOutUI* boundary - ��� ����Լ��� �θ��� ���� boundary class ���۷����� ���ڷ� �޴´�.
//Return Value : void
//Created : 2022/06/1 1:20 pm 
//author : Hong Hyolim
//Revisions :
//

void Member::deleteMember(SignOutUI* boundary)
{
    //boundary Ŭ������ reference�� �̿��� �Լ��� �ҷ��� �޼��� ���
    for (int i = 0; i < memberCnt; i++)
    {
        if (currentMember->ID == memberList[i]->ID)
        {
            memberList[i] = NULL;
            string ID = MemberID;
            boundary->sendSignOutMsg(ID);
            //�α׾ƿ�
            MemberID = "";
        }
    }
}

//Function : string validatePW()
//Description: memberList[i]�� pw�� �����ϴ� �Լ�
//Parameters : void
//Return Value : string
//Created : 2022/05/27 6:00 pm 
//author : Hong Hyolim
//Revisions :
//
string Member::validatePW()
{
    return this->password;
}



//Function : string validateID()
//Description: memberList[i]�� id�� �����ϴ� �Լ�
//Parameters : void
//Return Value : string
//Created : 2022/05/27 6:01 pm 
//author : Hong Hyolim
//Revisions :
//
string Member::validateID()
{
    return this->ID;
}

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

Product::Product() {
}

void Product::SetProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID)
{
    Name = ProductName;
    Company = CompanyName;
    Price = ProductPrice;
    Registation = RegistationQuantity;
    Purchased = 0;
    Review = 0;
    Seller = SellerID;
    recentSearched = false; //S.J.T
}

void Product::setName(string ProductName)
{
    Name = ProductName;
}
void Product::setCompany(string CompanyName)
{
    Company = CompanyName;
}
void Product::setSeller(string SellerID)
{
    Seller = SellerID;
}
void Product::setRegistation(int RegistationQuantity)
{
    Registation = RegistationQuantity;
}
void Product::setPurchased(int PurchasedQuantity)
{
    Purchased = PurchasedQuantity;
}
void Product::setPrice(int ProductPrice)
{
    Price = ProductPrice;
}
void Product::setReview(double AverageReview)
{
    Review = AverageReview;
}
string Product::getName()
{
    return Name;
}
string Product::getCompany()
{
    return Company;
}
string Product::getSeller()
{
    return Seller;
}
int Product::getRegistation()
{
    return Registation;
}
int Product::getPurchased()
{
    return Purchased;
}
int Product::getPrice()
{
    return Price;
}
double Product::getReview()
{
    return Review;
}
bool Product::getRecentSearched() {
    return recentSearched;
}

void Product::setRecentSearched() {
    this->recentSearched = !this->recentSearched;
}

/*������*/
void Product::modifyProductQuantity() {
    Purchased++;
}

/*������*/
string Product::getProductDetail() {
    return Seller + " " + Name + " " + Company + " " + to_string(Price) + " " + to_string(Registation - Purchased) + " " + to_string(Review);
}

/*������*/
void Product::modifyProductReview(int reviewPoint) {
    Review = (Review * (Purchased - 1) + reviewPoint) / Purchased;
}

Product::~Product() {}

Buyer::Buyer(Member* member) {
    purchasedList = new int[10];
}

void Buyer::addPurchasedProduct(int purchased) {
    purchasedList[purchasedCount] = purchased;
    purchasedCount++;
}
int* Buyer::getPurchasedProduct() {
    int* purchasedIndexList = new int[purchasedCount + 1];
    for (int i = 0; i < purchasedCount; i++) {
        purchasedIndexList[i] = purchasedList[i];
    }
    return purchasedIndexList;
}

int Buyer::getPurchasedCount() {
    return purchasedCount;
}