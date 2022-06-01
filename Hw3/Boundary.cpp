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
        fout << name << " " << SSN << " " << ID << " " << password << endl << endl;
    }

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