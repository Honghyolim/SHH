#pragma once
#include "Entity.h"


//현재 로그인한 멤버의 ID를 저장하는 전역변수
extern string MemberID;
//등록된 상품의 숫자를 저장하는 전역변수
extern int productnumber;
// Product 저장하는 리스트 전역변수
extern Product product[100];
extern int memberCnt;
// Member 저장하는 리스트 전역변수
extern Member* memberList[100];

//Function : Member(string ID, string password, string SSN, string name)
//Description: Member 클래스 생성자
//
//
//Parameters : ID - 가입시 입력한 id, password - 가입시 입력한 비번, SSN - 가입시 입력한 주민번호, name - 가입시 입력한 이름
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
//Description: memberList에 멤버 추가하는 함수
//
//
//Parameters : nMember - 새로운 멤버를 가리키는 포인터
//Return Value : 회원가입이 되었는지 확인하는 값
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
//Description: 회원리스트에서 삭제하고 결과출력함수를 부르는 함수
//
//Parameters : signOutUI* boundary - 결과 출력함수를 부르기 위한 boundary class 래퍼랜스를 인자로 받는다.
//Return Value : void
//Created : 2022/06/1 1:20 pm 
//author : Hong Hyolim
//Revisions :
//

void Member::deleteMember(SignOutUI* boundary)
{
    //boundary 클래스의 reference를 이용해 함수를 불러서 메세지 출력
    for (int i = 0; i < memberCnt; i++)
    {
        if (currentMember->ID == memberList[i]->ID)
        {
            memberList[i] = NULL;
            string ID = MemberID;
            boundary->sendSignOutMsg(ID);
            //로그아웃
            MemberID = "";
        }
    }
}

//Function : string validatePW()
//Description: memberList[i]의 pw를 리턴하는 함수
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
//Description: memberList[i]의 id를 리턴하는 함수
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
// Author : 황성윤
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

/*서준택*/
void Product::modifyProductQuantity() {
    Purchased++;
}

/*서준택*/
string Product::getProductDetail() {
    return Seller + " " + Name + " " + Company + " " + to_string(Price) + " " + to_string(Registation - Purchased) + " " + to_string(Review);
}

/*서준택*/
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