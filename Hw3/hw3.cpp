#include "hw3.h"


using namespace std;


//등록된 상품의 숫자를 저장하는 전역변수
int productnumber = 0;
// Product 저장하는 리스트 전역변수
Product product[100];
Buyer* now[100];
int MemberSeq;

// Member 저장하는 리스트 전역변수
Member* memberList[100];
int memberCnt = 0;
//현재 로그인한 멤버의 ID를 저장하는 전역변수
string MemberID = "";
//현재 로그인한 멤버의 포인터를 저장하는 전역변수
Member* currentMember;
//파일 입출력 객체 선언
ifstream fin("input.txt");
ofstream fout("output.txt");

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

//Function : Member(string ID, string password, string SSN, string name)
//Description: Member 클래스 생성자
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

//Function : void join()
//Description: 회원가입을 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 12:28 am 
//author : Hong Hyolim
//Revisions : 
// 1. When& Who : 2022/06/01 3:16 pm by 홍효림
//	   What : boundary 생성하는것을 control 생성자 안에 넣었음
//

void join()
{
    // control class 생성
    SignUp* control = new SignUp;

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
// 1. When& Who : 2022/06/01 3:10 pm by 홍효림
//	   What : boundary 생성하는것을 control 생성자 안에 넣었음
//

void login()
{
    //control class 생성
    Login* control = new Login;
}

//Function : void withdraw()
//Description: 회원탈퇴를 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 12:12 pm 
//author : Hong Hyolim
//Revisions :
//

void withdraw()
{
    //control class 생성
    SignOut* control = new SignOut;
}

//Function : void logout()
//Description: 로그아웃을 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 2:00 pm 
//author : Hong Hyolim
//Revisions :
//

void logout()
{
    //control class 생성
    LogOut* control = new LogOut;
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


//Function : void searchProduct
//Description: 검색을 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 19:01 am 
//author : 서준택
//Revisions :
//
void searchProduct() {
    Search* searchControl = new Search;//control 생성
    SearchUI* boundary = new SearchUI; //boundary class 생성
    boundary->enterProductName(searchControl);
}


//Function : void purchase()
//Description: 상품 구매를 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 19:01 am 
//author : 서준택
//Revisions :
//
void purchase() {
    Purchase* purchaseControl = new Purchase;//control 생성
    PurchaseUI* boundary = new PurchaseUI;//boundary class 생성
    boundary->clickPurchase(purchaseControl);
}

//Function : void purchasedList()
//Description: 상품 구매 내역 조회를 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 19:01 am 
//author : 서준택
//Revisions :
//
void purchasedList() {
    PurchasedList* control = new PurchasedList;//control 생성
    PurchasedListUI* boundary = new PurchasedListUI;//boundary class 생성
    boundary->searchPurchasedList(control);
}

//Function : void review()
//Description: 만족도 평가를 진행하는 함수
//
//
//Parameters : void
//Return Value : void
//Created : 2022/06/1 19:01 am 
//author : 서준택
//Revisions :
//
void review() {
    Review* control = new Review;//control 생성
    ReviewUI* boundary = new ReviewUI;//boundary class 생성
    boundary->selectProduct(control);
}

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
        fout << "> " << ID << " " << password << endl << endl;
        MemberID = ID;
    }
    else
    {
        fout << "로그인 실패" << endl << endl;
    }
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
}

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

//Function : SearchUI()
//Description: 생성자
//Parameters : 
//Return Value : 
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
SearchUI::SearchUI() {}


//Function : void enterProductName(Search* control)
//Description: 검색어를 입력받고 검색결과를 출력파일에 쓰는 함수
//Parameters : Search*
//Return Value : void
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
void SearchUI::enterProductName(Search* control) {
    fin >> searchKeyword;
    string result = control->showProduct(searchKeyword);
    fout << "4.1. 상품 정보 검색" << endl;
    fout << "> " << result << endl;
}


//Function : ~SearchUI()
//Description: 소멸자
//Parameters : 
//Return Value : 
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
SearchUI::~SearchUI() {
}

//Function : PurchaseUI()
//Description: 생성자
//Parameters : 
//Return Value : 
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
PurchaseUI::PurchaseUI() {
};

//Function : void clickPurchase(Purchase* control)
//Description: 구매한 상품의 판매자ID와 상품명을 받아서 출력파일에 쓰는 함수
//Parameters : Purchase*
//Return Value : void
//Created : 2022/06/01 17:03 pm 
//author : 서준택
//Revisions :
//
void PurchaseUI::clickPurchase(Purchase* control) {
    string purchaseResult = control->showPurchaseFinish();
    fout << "4.2. 상품 구매" << endl;
    fout << "> " << purchaseResult << endl;
}

//Function : ~PurchaseUI()
//Description: 소멸자
//Parameters : 
//Return Value : 
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
PurchaseUI::~PurchaseUI() {
}

//Function : PurchasedListUI()
//Description: 생성자
//Parameters : 
//Return Value : 
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
PurchasedListUI::PurchasedListUI() {}

//Function : void searchPurchasedList(PurchasedList* control)
//Description: 구매 상품 리스트를 받은 후 상세정보를 출력파일에 쓰는 함수
//Parameters : PurchasedList*
//Return Value : void
//Created : 2022/06/01 20:03 pm 
//author : 서준택
//Revisions :
//
void PurchasedListUI::searchPurchasedList(PurchasedList* control) {
    string purchasedList = control->getPurchasedProduct();

    fout << "4.3. 상품 구매 내역 조회" << endl;
    fout << "> " << purchasedList << endl;
}

//Function : void selectProduct(Review* control)
//Description: 만족도를 평가할 상품과 만족도 평가 점수를 받아서 출력파일에 쓰는 함수
//Parameters : Review*
//Return Value : void
//Created : 2022/06/01 20:27 pm 
//author : 서준택
//Revisions :
//
void ReviewUI::selectProduct(Review* control) {
    fin >> reviewProduct >> reviewPoint;
    string result = control->selectProduct(reviewProduct, reviewPoint);
    fout << "4.4. 상품 구매만족도 평가" << endl;
    fout << "> " << result << endl;
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

//Function : string showProduct(string searchKeyword)
//Description: 바운더리에서 만든 검색어를 받아서 프로덕트리스트에서 검색어와 이름이 똑같은 애를 찾고 상품 구매처리를 위해 검색을 
// 했다는 것을 표시한다. 검색했을때 검색어랑 물건이름이 같으면 트루로 바꿔주고 프로덕트 배열에 프로덕트디테일은 넣은 후 반환하는 함수.
//Parameters : int
//Return Value : bool
//Created : 2022/06/01 16:08 pm 
//author : 서준택
//Revisions :
//
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

//Function : string showPurchaseFinish()
//Description: 파는 사람과 물건의 번호를 스트링으로 바운더리에게 반환하는 함수
//Parameters : 
//Return Value : string
//Created : 2022/05/30 16:08 pm 
//author : 서준택
//Revisions :
//
string Purchase::showPurchaseFinish() {
    for (int i = 0; i < productnumber; i++) {
        if (product[i].getRecentSearched()) {
            if (product[i].getRegistation() > product[i].getPurchased()) {
                product[i].modifyProductQuantity();
                if (now[MemberSeq] == NULL) {
                    now[MemberSeq] = new Buyer(memberList[MemberSeq]);
                }
                now[MemberSeq]->addPurchasedProduct(i);
                product[i].setRecentSearched();//true->false;
                result = product[i].getSeller() + " " + product[i].getName();
                return result;
            }
            else {
                return "재고 없음";
            }
        }
    }
    return "최근 검색한 상품이 없음";
}

PurchasedList::PurchasedList() {}

//Function : string getPurchasedProduct()
//Description: 구매목록 리스트를 가져오는 함수
//Parameters : 
//Return Value : string
//Created : 2022/06/01 22:08 pm 
//author : 서준택
//Revisions :
//
string PurchasedList::getPurchasedProduct() {
    string result = "";
    if (now[MemberSeq] != NULL) {
        int purchasedCount = now[MemberSeq]->getPurchasedCount(); //물건의 갯수
        int* list = now[MemberSeq]->getPurchasedProduct();//buyer가 가진 구매목록 가져오기 (물건 번호로 저장)  
        for (int i = 0; i < purchasedCount; i++) {
            result += listPurchasedProduct(list[i]);
            result += "\n";
        }
    }
    else {
        result = "구매한 물건 없음";
    }
    return result;
}


//Function : string listPurchasedProduct(int productNum)
//Description: 구매 내역을 반환해주는 함수
//Parameters : int productNum
//Return Value : string
//Created : 2022/06/01 22:08 pm 
//author : 서준택
//Revisions :
//
string PurchasedList::listPurchasedProduct(int productNum) {
    return product[productNum].getProductDetail();
}


//Function : string getPurchasedProduct()
//Description: 만족도 평가한 결과를 반환하는 함수
//Parameters : 
//Return Value : string
//Created : 2022/06/01 22:08 pm 
//author : 서준택
//Revisions :
//
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
    recentSearched = false;
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


//Function : void modifyProductQuantity()
//Description: 구매 상품을 추가하는 함수
//
//
//Parameters : 
//Return Value : 
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
void Product::modifyProductQuantity() {
    Purchased++;
}

//Function : string getProductDetail()
//Description: 상품의 상세정보를 가져오는 함수
//
//
//Parameters : 
//Return Value : string, string, string, string
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
string Product::getProductDetail() {
    return Seller + " " + Name + " " + Company + " " + to_string(Price) + " " + to_string(Registation - Purchased) + " " + to_string(Review);
}

//Function : void modifyProductReview(int reviewPoint)
//Description: 만족도를 수정하는 함수
//
//
//Parameters : int reviewPoint
//Return Value : 
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
void Product::modifyProductReview(int reviewPoint) {
    Review = (Review * (Purchased - 1) + reviewPoint) / Purchased;
}

Product::~Product() {}

Buyer::Buyer(Member* member) {
    purchasedList = new int[10];
}

//Function : void addPurchasedProduct(int purchased)
//Description: 구매하기를 누룬 상품의 번호를 구매한리스트에 추가하는 함수
//
//
//Parameters : 
//Return Value : 
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
void Buyer::addPurchasedProduct(int purchased) {
    purchasedList[purchasedCount] = purchased;
    purchasedCount++;
}

//Function : int* getPurchasedProduct()
//Description: 구매목록을 물건번호로 저장 하는 함수
//
//
//Parameters : 
//Return Value : purchasedIndexList
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
int* Buyer::getPurchasedProduct() {
    int* purchasedIndexList = new int[purchasedCount + 1];
    for (int i = 0; i < purchasedCount; i++) {
        purchasedIndexList[i] = purchasedList[i];
    }
    return purchasedIndexList;
}

//Function : int getPurchasedCount()
//Description: 구매 상품 물건 수를 반환하는 함수
//
//
//Parameters : 
//Return Value : purchasedCount
//Created : 2022/06/1 6:50 pm 
//author : 서준택
//Revisions :
//
int Buyer::getPurchasedCount() {
    return purchasedCount;
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
                withdraw();
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
                //cout << "login" << endl;
                login();

                break;
            }
            case 2:
            {
                logout();
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
                break;;
            }
            }

        }
        }
    }
    return;
}


