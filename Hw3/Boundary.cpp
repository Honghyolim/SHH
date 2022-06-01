#pragma once
#include "Boundary.h"
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

extern ifstream fin;
extern ofstream fout;

//Function : SignUpUI(SignUp*control)
//Description: 바운더리 클래스 생성자
//
//
//Parameters : Login* control - control클래스의 래퍼랜스
//Return Value : void
//Created : 2022/06/1 3:22 pm 
//author : Hong Hyolim
//Revisions :
//

SignUpUI::SignUpUI(SignUp* control)
{
    this->control = control;
    this->enterMemberInfo(control);
}

//Function : SignUpUI* createBoundary(SignUp* control);
//Description: 바운더리 클래스를 생성하고 래퍼랜스를 서로 교환하는 함수
//
//
//Parameters : Login*control - control 클래스의 래퍼랜스
//Return Value : 바운더리 클래스 포인터 
//Created : 2022/06/1 3:25 pm 
//author : Hong Hyolim
//Revisions :
//

SignUpUI* SignUp::createBoundary(SignUp* control)
{
    SignUpUI* boundary = new SignUpUI(control);
    return boundary;
}

//Function : void enterMemberInfo(SignUp* control)
//Description: 회원가입 정보를 입력받고, 회원가입이 완료되면 결과 출력하는 함수
//Parameters : control - control객체 포인터
//Return Value : void
//Created : 2022/05/27 2:37 pm 
//author : Hong Hyolim
//Revisions :

void SignUpUI::enterMemberInfo(SignUp* control)
{
    string ID;
    string password;
    string SSN;
    string name;
    fin >> name >> SSN >> ID >> password;

    fout << "1.1 회원가입" << endl;
    bool flag = control->createNewMember(ID, password, SSN, name);

    if (flag == true)
    {
        fout << "> " << name << " " << SSN << " " << ID << " " << password << endl << endl;
    }

}

//Function : LoginUI(Login* control);
//Description: 바운더리 클래스 생성자
//
//
//Parameters : Login* control - control클래스의 래퍼랜스
//Return Value : void
//Created : 2022/06/1 3:08 pm 
//author : Hong Hyolim
//Revisions :
//

LoginUI::LoginUI(Login* control)
{
    this->control = control;
    this->enterIDPW(control);
}

//Function : void enterIDPW(Login* control)
//Description: 로그인데이터를 입력받는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 5:51 pm 
//author : Hong Hyolim
//Revisions :
//
void LoginUI::enterIDPW(Login* control)
{
    string ID;
    string password;
    fin >> ID >> password;

    fout << "2.1 로그인" << endl;
    bool flag = control->validateID(ID, password);

    if (flag == true)
    {
        fout << ID << " " << password << endl << endl;
        MemberID = ID;
    }
    else
    {
        fout << "로그인 실패" << endl << endl;
    }
}

//Function : signOutUI* createBoundary(signOut* control);
//Description: 바운더리 클래스를 생성하고 래퍼랜스를 서로 교환하는 함수
//
//
//Parameters : signOut* control - 바운더리 클래스에 control클래스의 래퍼랜스 전달
//Return Value : 바운더리 클래스의 래퍼랜스
//Created : 2022/06/1 1:00 pm 
//author : Hong Hyolim
//Revisions :
//

SignOutUI* SignOut::createBoundary(SignOut* control)
{
    SignOutUI* boundary = new SignOutUI(control);
    return boundary;
}

//Function : signOutUI(signOut*);
//Description: 바운더리 클래스 생성자
//
//
//Parameters : signOut* control - control 클래스의 래퍼랜스
//Return Value : 
//Created : 2022/06/1 1:04 pm 
//author : Hong Hyolim
//Revisions :
//

SignOutUI::SignOutUI(SignOut* control)
{
    this->control = control;
    control->deleteMember(this);
}

//Function : void sendSignOutMsg(string ID);
//Description: 회원탈퇴 완료시 결과 출력을 위한 함수
//
//Parameters : string ID - 결과 출력시 필요한 정보를 인자로 받는다
//Return Value : void
//Created : 2022/06/1 1:14 pm 
//author : Hong Hyolim
//Revisions :
//

void SignOutUI::sendSignOutMsg(string ID)
{
    fout << "1.2 회원탈퇴" << endl;
    fout << "> " << ID << endl << endl;
}

//Function : LogOutUI(LogOut*)
//Description: 바운더리 클래스 생성자
//
//
//Parameters : LogOut*control - control 클래스의 래퍼랜스
//Return Value : void
//Created : 2022/06/1 2:30 pm 
//author : Hong Hyolim
//Revisions :
//

LogOutUI::LogOutUI(LogOut* control)
{
    this->control = control;
    control->logOut(this);
}

//Function : void sendLogOutMsg(string ID);
//Description: 로그아웃 완료시 결과 출력을 위한 함수
//
//Parameters : string ID - 결과 출력시 필요한 정보를 인자로 받는다
//Return Value : void
//Created : 2022/06/1 2:40 pm 
//author : Hong Hyolim
//Revisions :
//

void LogOutUI::sendLogOutMsg(string ID)
{
    fout << "2.2 로그아웃" << endl;
    fout << "> " << ID << endl << endl;
}

//
//Function : void RegistationUI::enterProduct(Registation* control)
//Description: 상품 정보를 입력받는 함수
//Parameters : Registation*
//Return Value : void
//Created : 2022/05/30 15:59 pm 
//author : 황성윤
//Revisions :
//
void RegistationUI::enterProduct(Registation* control) {
    string ProductName;
    string CompanyName;
    int ProductPrice;
    int RegistationQuantity;

    fin >> ProductName >> CompanyName >> ProductPrice >> RegistationQuantity;
    control->setProduct(ProductName, CompanyName, ProductPrice, RegistationQuantity, MemberID);
    productnumber++;
    fout << "3.1 판매 의류 등록" << endl << ProductName << " " << CompanyName << " " << ProductPrice << " " << RegistationQuantity << endl;

}


//
//Function : void CheckSaleUI::printCheckSale(CheckSale* control)
//Description: 판매중인 상품을 출력하는 함수
//Parameters : CheckSale*
//Return Value : void
//Created : 2022/05/30 16:01 pm 
//author : 황성윤
//Revisions :
//
void CheckSaleUI::printCheckSale(CheckSale* control)
{
    int i = 0;
    while (productnumber > i) {
        if (control->searchCheckSale(i)) {
            fout << "3.2 등록 상품 조회" << endl << product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
        }
        i++;
    }
}


//
//Function : void SoldoutUI::printSoldout(Soldout* control)
//Description: 판매완료인 상품을 출력하는 함수
//Parameters : Soldout*
//Return Value : void
//Created : 2022/05/30 16:07 pm 
//author : 황성윤
//Revisions :
//
void SoldoutUI::printSoldout(Soldout* control)
{
    int i = 0;
    while (productnumber > i) {
        if (control->searchSoldout(i)) {
            fout << "3.3 판매 완료 상품 조회" << endl << product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
        }
        i++;
    }
}


//Function : void SaleStatisticUI::printSaleStatistic(SaleStatistic* control)
//Description: 사용자가 판매한 상품인지 확인하는 함수
//Parameters : SaleStatistic*
//Return Value : void
//Created : 2022/05/30 16:08 pm 
//author : 황성윤
//Revisions :
//
void SaleStatisticUI::printSaleStatistic(SaleStatistic* control)
{
    int i = 0;
    while (productnumber > i) {
        if (control->searchSaleStatistic(i)) {
            fout << "5.1 판매 상품 통계" << endl << product[i].getName() << " " << product[i].getPrice() * product[i].getPurchased() << " " << product[i].getReview();
        }
        i++;
    }
}

/*
함수 이름 : SearchUI 생성자
기능 : 검색할 상품명
*/
SearchUI::SearchUI() {}

void SearchUI::enterProductName(Search* control) {
    fin >> searchKeyword;
    string result = control->showProduct(searchKeyword);
    fout << "4.1. 상품 정보 검색" << endl;
    fout << "> " << result << endl;
}


SearchUI::~SearchUI() {
}

PurchaseUI::PurchaseUI() {
};

void PurchaseUI::clickPurchase(Purchase* control) {
    string purchaseResult = control->showPurchaseFinish();
    fout << "4.2. 상품 구매" << endl;
    fout << "> " << purchaseResult << endl;
}

PurchaseUI::~PurchaseUI() {
}

PurchasedListUI::PurchasedListUI() {}

void PurchasedListUI::searchPurchasedList(PurchasedList* control) {
    string purchasedList = control->getPurchasedProduct();

    fout << "4.3. 상품 구매 내역 조회" << endl;
    fout << "> " << purchasedList << endl;
}

void ReviewUI::selectProduct(Review* control) {
    fin >> reviewProduct >> reviewPoint;
    string result = control->selectProduct(reviewProduct, reviewPoint);
    fout << "4.4. 상품 구매만족도 평가" << endl;
    fout << "> " << result << endl;
}