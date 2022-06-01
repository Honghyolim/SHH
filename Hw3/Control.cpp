#pragma once
#include "Control.h"
#include "Entity.h"


//현재 로그인한 멤버의 ID를 저장하는 전역변수
extern string MemberID;
extern int MemberSeq;
//등록된 상품의 숫자를 저장하는 전역변수
extern int productnumber;
// Product 저장하는 리스트 전역변수
extern Product product[100];
extern int memberCnt;
// Member 저장하는 리스트 전역변수
extern Member* memberList[100];
Buyer* now;

//Function : SignUp()
//Description: 컨트롤 클래스 생성자, 바운더리 클래스 생성자를 부름
//
//
//Parameters : 
//Return Value : void
//Created : 2022/06/1 3:24 pm 
//author : Hong Hyolim
//Revisions :
//

SignUp::SignUp()
{
    SignUpUI* boundary = this->createBoundary(this);
}

//Function : SignOut()
//Description: 회원탈퇴 control 클래스 생성자
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 1:30 pm 
//author : Hong Hyolim
//Revisions :
//

SignOut::SignOut()
{
    //boundary class 생성
    SignOutUI* boundary = this->createBoundary(this);
}

//Function : void deleteMember(signOutUI* boundary)
//Description: member class의 deltemember를 부르기위한 control 클래스의 함수
//
//
//Parameters : signOutUI* boundary - 결과 출력을 위한 boundary 클래스의 래퍼랜스
//Return Value : void
//Created : 2022/06/1 1:08 pm 
//author : Hong Hyolim
//Revisions :
//

void SignOut::deleteMember(SignOutUI* boundary)
{
    currentMember->deleteMember(boundary);
}

//Function : bool createNewMember(string ID, string password, string SSN, string name)
//Description: 새로운 멤버를 생성하고 createMember함수에 정보를 전달하는 함수
//Parameters : ID - 가입시 입력한 id, password - 가입시 입력한 비번, SSN - 가입시 입력한 주민번호, name - 가입시 입력한 이름
//Return Value : 회원가입이 되었는지 확인하는 값
//Created : 2022/05/27 3:05 am 
//author : Hong Hyolim
//Revisions :
//

bool SignUp::createNewMember(string ID, string password, string SSN, string name)
{
    //Member 클래스 생성
    Member* nMember = new Member(ID, password, SSN, name);
    bool flag = nMember->createMember(nMember);
    return flag;
}

//Function : Login();
//Description: 컨트롤 클래스 생성자
//
//
//Parameters : 
//Return Value : void
//Created : 2022/06/1 3:08 pm 
//author : Hong Hyolim
//Revisions :
//

Login::Login()
{
    LoginUI* boundary = this->createBoundary(this);
}

//Function : LoginUI* createBoundary(Login* control);
//Description: 바운더리 클래스를 생성하고 래퍼랜스를 서로 교환하는 함수
//
//
//Parameters : Login*control - control 클래스의 래퍼랜스
//Return Value : 바운더리 클래스 포인터
//Created : 2022/06/1 3:05 pm 
//author : Hong Hyolim
//Revisions :
//

LoginUI* Login::createBoundary(Login* control)
{
    LoginUI* boundary = new LoginUI(control);
    return boundary;
}

//Function : bool validateID(string ID, string password)
//Description: ID와 PW가 유효한지 확인
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 5:51 pm 
//author : Hong Hyolim
//Revisions :
//
bool Login::validateID(string ID, string password)
{
    string password2;
    string ID2;

    //fout <<" ID : " <<ID << endl;
    //fout << "PW :"<<password << endl;

    for (int i = 0; i < memberCnt; i++)
    {
        ID2 = memberList[i]->validateID();
        //fout <<"ID2 : " << ID2 <<endl;
        password2 = memberList[i]->validatePW();
        //fout << password2;
        if (ID.compare(ID2) == 0 && password.compare(password2) == 0)
        {
            MemberSeq = i;
            return true;
        }
    }
    return false;
}

//Function : LogOutUI* createBoundary(LogOut*contro;);
//Description: 바운더리 클래스를 생성하고 래퍼랜스를 서로 교환하는 함수
//
//
//Parameters : LogOut*control - control 클래스의 래퍼랜스
//Return Value : 바운더리 클래스 포인터
//Created : 2022/06/1 2:32 pm 
//author : Hong Hyolim
//Revisions :
//



LogOutUI* LogOut::createBoundary(LogOut* control)
{
    LogOutUI* boundary = new LogOutUI(control);
    return boundary;

    //Function :LogOut()
//Description: 컨트롤 클래스 생성자
//
//
//Parameters : LogOut*control - control 클래스의 래퍼랜스
//Return Value : void
//Created : 2022/06/1 2:33 pm 
//author : Hong Hyolim
//Revisions :
//

    LogOut::LogOut()
    {
        //boundary class 생성
        LogOutUI* boundary = this->createBoundary(this);
    }

    //Function : void logOut(LogOutUI*boundary);
//Description: 로그아웃 하는 함수
//
//Parameters : signOutUI* boundary - 결과 출력함수를 부르기 위한 boundary class 래퍼랜스를 인자로 받는다.
//Return Value : void
//Created : 2022/06/1 2:44 pm 
//author : Hong Hyolim
//Revisions :
//

    void LogOut::logOut(LogOutUI* boundary)
    {
        string ID = MemberID;
        MemberID = "";
        boundary->sendLogOutMsg(ID);
    }


//Function : void Registation::setProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID)
//Description: 상품 정보를 등록하는 함수
//Parameters : string, string, int, int, string
//Return Value : void
//Created : 2022/05/30 15:59 pm 
//author : 황성윤
//Revisions :
//
void Registation::setProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID)
{
    product[productnumber].setName(ProductName);
    product[productnumber].setCompany(CompanyName);
    product[productnumber].setPrice(ProductPrice);
    product[productnumber].setRegistation(RegistationQuantity);
    product[productnumber].setPurchased(0);
    product[productnumber].setReview(0);
    product[productnumber].setSeller(SellerID);

}


//
//Function : bool CheckSale::searchCheckSale(int i)
//Description: 판매중인 상품인지 확인 하는 함수
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:03 pm 
//author : 황성윤
//Revisions :
//
bool CheckSale::searchCheckSale(int i)
{
    if (product[i].getSeller() == MemberID) {
        if (product[i].getRegistation() > product[i].getPurchased())
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}


//
//Function : bool Soldout::searchSoldout(int i)
//Description: 판매완료인 상품인지 확인 하는 함수
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:03 pm 
//author : 황성윤
//Revisions :
//
bool Soldout::searchSoldout(int i)
{
    if (product[i].getSeller() == MemberID) {
        if (product[i].getRegistation() == product[i].getPurchased())
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}


//Function : bool SaleStatistic::searchSaleStatistic(int i)
//Description: 사용자가 판매한 상품인지 확인하는 함수
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:08 pm 
//author : 황성윤
//Revisions :
//

bool SaleStatistic::searchSaleStatistic(int i)
{
    if (product[i].getSeller() == MemberID) {
        return true;
    }
    else
    {
        return false;
    }
}


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
Search::Search() {}

string Search::showProduct(string searchKeyword) {
    for (int i = 0; i < productnumber; i++) {
        if (product[i].getName() == searchKeyword) {
            product[i].setRecentSearched();//false ->true
            return product[i].getProductDetail();
        }
    }
    return "상품 없음";
}

Search::~Search() {
}

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
Purchase::Purchase() {
}

string Purchase::showPurchaseFinish() {
    for (int i = 0; i < productnumber; i++) {
        if (product[i].getRecentSearched()) {
            product[i].modifyProductQuantity();
            now = new Buyer(memberList[MemberSeq]);
            now->addPurchasedProduct(i);
            result = product[i].getSeller() + " " + product[i].getName();
            return result;
        }
    }
    return "최근 검색한 상품이 없음";
}

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
PurchasedList::PurchasedList() {}

string PurchasedList::getPurchasedProduct() {

    int* list = now->getPurchasedProduct();//buyer가 가진 구매목록 가져오기 (물건 번호로 저장)  
    int purchasedCount = now->getPurchasedCount(); //물건의 갯수 
    string result = "";
    for (int i = 0; i < purchasedCount; i++) {
        result += listPurchasedProduct(list[i]);
    }
    return result;
}

string PurchasedList::listPurchasedProduct(int productNum) {
    return product[productNum].getProductDetail();
}

string Review::selectProduct(string reviewProduct, int reviewPoint) {
    string result;
    for (int i = 0; i < productnumber; i++) {
        if (product[i].getName() == reviewProduct) {
            product[i].modifyProductReview(reviewPoint);
            result = product[i].getSeller() + " " + product[i].getName() + " " + to_string(product[i].getReview());
        }
    }

    return result;
}