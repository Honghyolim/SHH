#include "base.h"
#include "Control.h"
#include "Boundary.h"
#include "Entity.h"

void doTask();
void join();
void login();
void registration();
void checksale();
void soldout();
void salestatistic();
void searchProduct();
void purchase();
void purchasedList();
void review();

// Member 저장하는 리스트 전역변수
Member* memberList[100];
int memberCnt = 0;
//현재 로그인한 멤버의 ID를 저장하는 전역변수
string MemberID = "";
int MemberSeq;
//Product 저장하는 리스트 전역변수
Product product[100];
//등록된 상품의 숫자를 저장하는 전역변수
int productnumber = 0;

//파일 입출력 객체 선언
ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

int main() {
    doTask();
}


//Function : void doTask()
//Description: 메뉴 파싱하는 함수
//
//
//Parameters : 
//Return Value
//Created : 2022/05/27 11:58 am 
//author : Hong Hyolim
//Revisions :
//
void doTask()
{
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기


        fin >> menu_level_1;
        fin >> menu_level_2;


        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {
                join();

                break;
            }
            case 2:
            {

                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:   // "2.1. 로그인“ 메뉴 부분
            {
                //fout << "login" << endl;
                login();

                break;
            }
            case 2:
            {

                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1: // "3.1 판매 의류 등록" 메뉴 부분
            {
                registration();
                break;
            }
            case 2: // "3.2 등록 상품 조회" 메뉴 부분
            {
                checksale();
                break;
            }
            case 3: // "3.3 판매 완료 상품 조회" 메뉴 부분
            {
                soldout();
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1:
                searchProduct();
                break;
            case 2:
                purchase();
                break;
            case 3:
                purchasedList();
                break;
            case 4:
                review();
                break;
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:   // "5.1 상품 판매 통계" 메뉴 부분
            {
                salestatistic();
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {

                // program_exit();
                is_program_exit = 1;
                break;
            }
            }

        }
        }
    }
    return;
}


//Function : void join()
//Description: 회원가입을 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 12:28 am 
//author : Hong Hyolim
//Revisions :
//
void join()
{
    // control class 생성
    SignUp* control = new SignUp;
    // boundary class 생성 
    SignUpUI* boundary = new SignUpUI;
    boundary->enterMemberInfo(control);

}


//Function : void login()
//Description: 로그인을 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 5:46 pm 
//author : Hong Hyolim
//Revisions :
//
void login()
{
    //control class 생성
    Login* control = new Login;
    //boundary class 생성
    LoginUI* boundary = new LoginUI;
    boundary->enterIDPW(control);

}


//Function : void registation()
//Description: 상품등록을 진행하는 함수
//Parameters : void
//Return Value : void
//Created : 2022/05/30 15:56 pm 
//author : 황성윤
//Revisions :
//
void registration()
{
    //control class 생성
    Registation* control = new Registation;
    //boundary class 생성
    RegistationUI* boundary = new RegistationUI;
    boundary->enterProduct(control);
}


//
//Function : void checksale()
//Description: 상품 등록 조회를 진행하는 함수
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:01 pm 
//author : 황성윤
//Revisions :
//
void checksale()
{
    //control class 생성
    CheckSale* control = new CheckSale;
    //boundary class 생성
    CheckSaleUI* boundary = new CheckSaleUI;
    boundary->printCheckSale(control);
}


//Function : void soldout()
//Description: 판매 완료 상품 조회를 진행하는 함수
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:06 pm 
//author : 황성윤
//Revisions :
//
void soldout()
{
    //control class 생성
    Soldout* control = new Soldout;
    //boundary class 생성
    SoldoutUI* boundary = new SoldoutUI;
    boundary->printSoldout(control);
}


//Function : void salestatistic()
//Description: 판매 통계 조회를 진행하는 함수
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:07 pm 
//author : 황성윤
//Revisions :
//
void salestatistic()
{
    //control class 생성
    SaleStatistic* control = new SaleStatistic;
    //boundary class 생성
    SaleStatisticUI* boundary = new SaleStatisticUI;
    boundary->printSaleStatistic(control);
}


//4 1 상품검색
void searchProduct() {
    Search* searchControl = new Search;//control 생성
    SearchUI* boundary = new SearchUI; //boundary class 생성
    boundary->enterProductName(searchControl);
}

//4 2 최근 검색한 물건 구매
void purchase() {
    Purchase* purchaseControl = new Purchase;//control 생성
    PurchaseUI* boundary = new PurchaseUI;//boundary class 생성
    boundary->clickPurchase(purchaseControl);
}

void purchasedList() {
    PurchasedList* control = new PurchasedList;//control 생성
    PurchasedListUI* boundary = new PurchasedListUI;//boundary class 생성
    boundary->searchPurchasedList(control);
}

void review() {
    Review* control = new Review;//control 생성
    ReviewUI* boundary = new ReviewUI;//boundary class 생성
    boundary->selectProduct(control);
}