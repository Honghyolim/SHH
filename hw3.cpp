#include "hw3.h"


using namespace std;


//��ϵ� ��ǰ�� ���ڸ� �����ϴ� ��������
int productnumber = 0;
// Product �����ϴ� ����Ʈ ��������
Product product[100];
Buyer* now;
int MemberSeq;

// Member �����ϴ� ����Ʈ ��������
Member* memberList[100];
int memberCnt = 0;
//���� �α����� ����� ID�� �����ϴ� ��������
string MemberID = "";
//���� �α����� ����� �����͸� �����ϴ� ��������
Member* currentMember;
//���� ����� ��ü ����
ifstream fin("input.txt");
ofstream fout("output.txt");

//Function : void enterMemberInfo(SignUp* control)
//Description: ȸ������ ������ �Է¹ް�, ȸ�������� �Ϸ�Ǹ� ��� ����ϴ� �Լ�
//Parameters : control - control��ü ������
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

    fout << "1.1 ȸ������" << endl;
    bool flag = control->createNewMember(ID, password, SSN, name);

    if (flag == true)
    {
        fout << "> " << name << " " << SSN << " " << ID << " " << password << endl << endl;
    }

}

//Function : bool createNewMember(string ID, string password, string SSN, string name)
//Description: ���ο� ����� �����ϰ� createMember�Լ��� ������ �����ϴ� �Լ�
//Parameters : ID - ���Խ� �Է��� id, password - ���Խ� �Է��� ���, SSN - ���Խ� �Է��� �ֹι�ȣ, name - ���Խ� �Է��� �̸�
//Return Value : ȸ�������� �Ǿ����� Ȯ���ϴ� ��
//Created : 2022/05/27 3:05 am 
//author : Hong Hyolim
//Revisions :
//

bool SignUp::createNewMember(string ID, string password, string SSN, string name)
{
    //Member Ŭ���� ����
    Member* nMember = new Member(ID, password, SSN, name);
    bool flag = nMember->createMember(nMember);
    return flag;
}

//Function : Member(string ID, string password, string SSN, string name)
//Description: Member Ŭ���� ������
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

//Function : void join()
//Description: ȸ�������� �����ϴ� �Լ�
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 12:28 am 
//author : Hong Hyolim
//Revisions : 
// 1. When& Who : 2022/06/01 3:16 pm by ȫȿ��
//	   What : boundary �����ϴ°��� control ������ �ȿ� �־���
//

void join()
{
    // control class ����
    SignUp* control = new SignUp;

}

//Function : void login()
//Description: �α����� �����ϴ� �Լ�
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 5:46 pm 
//author : Hong Hyolim
//Revisions : 
// 1. When& Who : 2022/06/01 3:10 pm by ȫȿ��
//	   What : boundary �����ϴ°��� control ������ �ȿ� �־���
//

void login()
{
    //control class ����
    Login* control = new Login;
}

//Function : void withdraw()
//Description: ȸ��Ż�� �����ϴ� �Լ�
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
    //control class ����
    SignOut* control = new SignOut;
}

//Function : void logout()
//Description: �α׾ƿ��� �����ϴ� �Լ�
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
    //control class ����
    LogOut* control = new LogOut;
}

//Function : void registation()
//Description: ��ǰ����� �����ϴ� �Լ�
//Parameters : void
//Return Value : void
//Created : 2022/05/30 15:56 pm 
//author : Ȳ����
//Revisions :
//
void registration()
{
    //control class ����
    Registation* control = new Registation;
    //boundary class ����
    RegistationUI* boundary = new RegistationUI;
    boundary->enterProduct(control);
}


//
//Function : void checksale()
//Description: ��ǰ ��� ��ȸ�� �����ϴ� �Լ�
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:01 pm 
//author : Ȳ����
//Revisions :
//
void checksale()
{
    //control class ����
    CheckSale* control = new CheckSale;
    //boundary class ����
    CheckSaleUI* boundary = new CheckSaleUI;
    boundary->printCheckSale(control);
}


//Function : void soldout()
//Description: �Ǹ� �Ϸ� ��ǰ ��ȸ�� �����ϴ� �Լ�
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:06 pm 
//author : Ȳ����
//Revisions :
//
void soldout()
{
    //control class ����
    Soldout* control = new Soldout;
    //boundary class ����
    SoldoutUI* boundary = new SoldoutUI;
    boundary->printSoldout(control);
}


//Function : void salestatistic()
//Description: �Ǹ� ��� ��ȸ�� �����ϴ� �Լ�
//Parameters : void
//Return Value : void
//Created : 2022/05/30 16:07 pm 
//author : Ȳ����
//Revisions :
//
void salestatistic()
{
    //control class ����
    SaleStatistic* control = new SaleStatistic;
    //boundary class ����
    SaleStatisticUI* boundary = new SaleStatisticUI;
    boundary->printSaleStatistic(control);
}


//4 1 ��ǰ�˻�
void searchProduct() {
    Search* searchControl = new Search;//control ����
    SearchUI* boundary = new SearchUI; //boundary class ����
    boundary->enterProductName(searchControl);
}

//4 2 �ֱ� �˻��� ���� ����
void purchase() {
    Purchase* purchaseControl = new Purchase;//control ����
    PurchaseUI* boundary = new PurchaseUI;//boundary class ����
    boundary->clickPurchase(purchaseControl);
}

void purchasedList() {
    PurchasedList* control = new PurchasedList;//control ����
    PurchasedListUI* boundary = new PurchasedListUI;//boundary class ����
    boundary->searchPurchasedList(control);
}

void review() {
    Review* control = new Review;//control ����
    ReviewUI* boundary = new ReviewUI;//boundary class ����
    boundary->selectProduct(control);
}

//Function : SignUpUI(SignUp*control)
//Description: �ٿ���� Ŭ���� ������
//
//
//Parameters : Login* control - controlŬ������ ���۷���
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
//Description: �ٿ���� Ŭ������ �����ϰ� ���۷����� ���� ��ȯ�ϴ� �Լ�
//
//
//Parameters : Login*control - control Ŭ������ ���۷���
//Return Value : �ٿ���� Ŭ���� ������ 
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
//Description: ��Ʈ�� Ŭ���� ������, �ٿ���� Ŭ���� �����ڸ� �θ�
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
//Description: ȸ��Ż�� control Ŭ���� ������
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
    //boundary class ����
    SignOutUI* boundary = this->createBoundary(this);
}

//Function : LoginUI* createBoundary(Login* control);
//Description: �ٿ���� Ŭ������ �����ϰ� ���۷����� ���� ��ȯ�ϴ� �Լ�
//
//
//Parameters : Login*control - control Ŭ������ ���۷���
//Return Value : �ٿ���� Ŭ���� ������
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
//Description: �ٿ���� Ŭ���� ������
//
//
//Parameters : Login* control - controlŬ������ ���۷���
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
//Description: ��Ʈ�� Ŭ���� ������
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
//Description: �α��ε����͸� �Է¹޴� �Լ�
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

    fout << "2.1 �α���" << endl;
    bool flag = control->validateID(ID, password);

    if (flag == true)
    {
        fout << "> " << ID << " " << password << endl << endl;
        MemberID = ID;
    }
    else
    {
        fout << "�α��� ����" << endl << endl;
    }
}

//Function : bool validateID(string ID, string password)
//Description: ID�� PW�� ��ȿ���� Ȯ��
//
//
//Parameters : void
//Return Value : void
//Created : 2022/05/27 5:51 pm 
//author : Hong Hyolim
//Revisions :
//


//Function : bool validateID(string ID, string password)
//Description: ID�� PW�� ��ȿ���� Ȯ��
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

//Function : signOutUI* createBoundary(signOut* control);
//Description: �ٿ���� Ŭ������ �����ϰ� ���۷����� ���� ��ȯ�ϴ� �Լ�
//
//
//Parameters : signOut* control - �ٿ���� Ŭ������ controlŬ������ ���۷��� ����
//Return Value : �ٿ���� Ŭ������ ���۷���
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
//Description: �ٿ���� Ŭ���� ������
//
//
//Parameters : signOut* control - control Ŭ������ ���۷���
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
//Description: member class�� deltemember�� �θ������� control Ŭ������ �Լ�
//
//
//Parameters : signOutUI* boundary - ��� ����� ���� boundary Ŭ������ ���۷���
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
//Description: ȸ��Ż�� �Ϸ�� ��� ����� ���� �Լ�
//
//Parameters : string ID - ��� ��½� �ʿ��� ������ ���ڷ� �޴´�
//Return Value : void
//Created : 2022/06/1 1:14 pm 
//author : Hong Hyolim
//Revisions :
//

void SignOutUI::sendSignOutMsg(string ID)
{
    fout << "1.2 ȸ��Ż��" << endl;
    fout << "> " << ID << endl << endl;
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

//Function : LogOutUI(LogOut*)
//Description: �ٿ���� Ŭ���� ������
//
//
//Parameters : LogOut*control - control Ŭ������ ���۷���
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
//Description: �ٿ���� Ŭ������ �����ϰ� ���۷����� ���� ��ȯ�ϴ� �Լ�
//
//
//Parameters : LogOut*control - control Ŭ������ ���۷���
//Return Value : �ٿ���� Ŭ���� ������
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
//Description: ��Ʈ�� Ŭ���� ������
//
//
//Parameters : LogOut*control - control Ŭ������ ���۷���
//Return Value : void
//Created : 2022/06/1 2:33 pm 
//author : Hong Hyolim
//Revisions :
//

LogOut::LogOut()
{
    //boundary class ����
    LogOutUI* boundary = this->createBoundary(this);
}

//Function : void sendLogOutMsg(string ID);
//Description: �α׾ƿ� �Ϸ�� ��� ����� ���� �Լ�
//
//Parameters : string ID - ��� ��½� �ʿ��� ������ ���ڷ� �޴´�
//Return Value : void
//Created : 2022/06/1 2:40 pm 
//author : Hong Hyolim
//Revisions :
//

void LogOutUI::sendLogOutMsg(string ID)
{
    fout << "2.2 �α׾ƿ�" << endl;
    fout << "> " << ID << endl << endl;
}

//Function : void logOut(LogOutUI*boundary);
//Description: �α׾ƿ� �ϴ� �Լ�
//
//Parameters : signOutUI* boundary - ��� ����Լ��� �θ��� ���� boundary class ���۷����� ���ڷ� �޴´�.
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
//Description: ��ǰ ������ �Է¹޴� �Լ�
//Parameters : Registation*
//Return Value : void
//Created : 2022/05/30 15:59 pm 
//author : Ȳ����
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
    fout << "3.1 �Ǹ� �Ƿ� ��� " << endl;
    fout << "> " ProductName << " " << CompanyName << " " << ProductPrice << " " << RegistationQuantity << endl;
}


//
//Function : void CheckSaleUI::printCheckSale(CheckSale* control)
//Description: �Ǹ����� ��ǰ�� ����ϴ� �Լ�
//Parameters : CheckSale*
//Return Value : void
//Created : 2022/05/30 16:01 pm 
//author : Ȳ����
//Revisions :
//
void CheckSaleUI::printCheckSale(CheckSale* control)
{
    int i = 0;
    fout << "3.2 ��� ��ǰ ��ȸ" << endl;
    int registationCount = now->getRegistationCount(); //������ ����
    while (registationCount > i) {
        if ("" != control->searchCheckSale(i)) {
            fout << "> " << control->searchCheckSale(i)<< <<endl;
        }
        i++;
    }
}


//
//Function : void SoldoutUI::printSoldout(Soldout* control)
//Description: �ǸſϷ��� ��ǰ�� ����ϴ� �Լ�
//Parameters : Soldout*
//Return Value : void
//Created : 2022/05/30 16:07 pm 
//author : Ȳ����
//Revisions :
//
void SoldoutUI::printSoldout(Soldout* control)
{
    int i = 0;
    int registationCount = now->getRegistationCount(); //������ ����
    fout << "3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
    while (registationCount > i) {
        if ("" != control->searchSoldout(i)) {
            fout << "> " << control->searchSoldout(i) << << endl;
        }
        i++;
    }
}


//Function : void SaleStatisticUI::printSaleStatistic(SaleStatistic* control)
//Description: ����ڰ� �Ǹ��� ��ǰ���� Ȯ���ϴ� �Լ�
//Parameters : SaleStatistic*
//Return Value : void
//Created : 2022/05/30 16:08 pm 
//author : Ȳ����
//Revisions :
//
void SaleStatisticUI::printSaleStatistic(SaleStatistic* control)
{
    int i = 0;
    int registationCount = now->getRegistationCount(); //������ ����
    fout << "5.1 �Ǹ� ��ǰ ���" << endl;
    while (registationCount > i) {
        if ("" != control->searchSaleStatistic(i)) {
            fout << "> " << control->searchSaleStatistic(i) << endl;
        }
        i++;
    }
}

/*
�Լ� �̸� : SearchUI ������
��� : �˻��� ��ǰ��
*/
SearchUI::SearchUI() {}

void SearchUI::enterProductName(Search* control) {
    fin >> searchKeyword;
    string result = control->showProduct(searchKeyword);
    fout << "4.1. ��ǰ ���� �˻�" << endl;
    fout << "> " << result << endl;
}


SearchUI::~SearchUI() {
}

PurchaseUI::PurchaseUI() {
};

void PurchaseUI::clickPurchase(Purchase* control) {
    string purchaseResult = control->showPurchaseFinish();
    fout << "4.2. ��ǰ ����" << endl;
    fout << "> " << purchaseResult << endl;
}

PurchaseUI::~PurchaseUI() {
}

PurchasedListUI::PurchasedListUI() {}

void PurchasedListUI::searchPurchasedList(PurchasedList* control) {
    string purchasedList = control->getPurchasedProduct();

    fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
    fout << "> " << purchasedList << endl;
}

void ReviewUI::selectProduct(Review* control) {
    fin >> reviewProduct >> reviewPoint;
    string result = control->selectProduct(reviewProduct, reviewPoint);
    fout << "4.4. ��ǰ ���Ÿ����� ��" << endl;
    fout << "> " << result << endl;
}

//Function : void Registation::setProduct(string ProductName, string CompanyName, int ProductPrice, int RegistationQuantity, string SellerID)
//Description: ��ǰ ������ ����ϴ� �Լ�
//Parameters : string, string, int, int, string
//Return Value : void
//Created : 2022/05/30 15:59 pm 
//author : Ȳ����
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
    now = new Seller(memberList[MemberSeq]);
    now->addRegistationProduct(i);

}


//
//Function : bool CheckSale::searchCheckSale(int i)
//Description: �Ǹ����� ��ǰ���� Ȯ�� �ϴ� �Լ�
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:03 pm 
//author : Ȳ����
//Revisions :
//
string CheckSale::searchCheckSale(int i)
{
    int* list = now->getRegistationProduct();
    int registationCount = now->getRegistationCount(); //������ ����
    string result = ""
        result = product[list[i]].getName() + " " + product[list[i]].getCompany() + " " << to_string(product[list[i]].getPrice()) << " " << to_string(product[list[i]].getRegistation());
    return result;

}


//
//Function : bool Soldout::searchSoldout(int i)
//Description: �ǸſϷ��� ��ǰ���� Ȯ�� �ϴ� �Լ�
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:03 pm 
//author : Ȳ����
//Revisions :
//
string Soldout::searchSoldout(int i)
{
    int* list = now->getRegistationProduct();//buyer�� ���� ���Ÿ�� �������� (���� ��ȣ�� ����)  
    int registationCount = now->getRegistationCount(); //������ ���� 
    string result = "";
    result = result = product[list[i]].getName() + " " + product[list[i]].getCompany() + " " << to_string(product[list[i]].getPrice()) << " " << to_string(product[list[i]].getPurchased()) << " " << to_string(product[i].getReview());
    return result;

}


//Function : bool SaleStatistic::searchSaleStatistic(int i)
//Description: ����ڰ� �Ǹ��� ��ǰ���� Ȯ���ϴ� �Լ�
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:08 pm 
//author : Ȳ����
//Revisions :
//

string SaleStatistic::searchSaleStatistic(int i)
{
    int* list = now->getRegistationProduct();//buyer�� ���� ���Ÿ�� �������� (���� ��ȣ�� ����)  
    int registationCount = now->getRegistationCount(); //������ ���� 
    string result = "";
    result = product[list[i]].getName() << " " << to_string(product[list[i]].getPrice() * product[list[i]].getPurchased()) << " " << to_string(product[list[i]].getReview());
    return result;

}

Search::Search() {}

string Search::showProduct(string searchKeyword) {
    for (int i = 0; i < productnumber; i++) {
        if (product[i].getName() == searchKeyword) {
            product[i].setRecentSearched();//false ->true
            return product[i].getProductDetail();
        }
    }
    return "��ǰ ����";
}

Search::~Search() {
}


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
    return "�ֱ� �˻��� ��ǰ�� ����";
}

PurchasedList::PurchasedList() {}

string PurchasedList::getPurchasedProduct() {

    int* list = now->getPurchasedProduct();//buyer�� ���� ���Ÿ�� �������� (���� ��ȣ�� ����)  
    int purchasedCount = now->getPurchasedCount(); //������ ���� 
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


Seller::Seller(Member* member) {
    RegistationList = new int[10];
}

void Seller::addRegistationProduct(int registation) {
    registationList[RegistationCount] = registation;
    registationCount++;
}
int* Seller::getRegistationProduct() {
    int* registationIndexList = new int[registationCount + 1];
    for (int i = 0; i < RegistationCount; i++) {
        registationIndexList[i] = registationList[i];
    }
    return registationIndexList;
}

int Seller::getRegistationCount() {
    return registationCount;
}

//Function : void doTask()
//Description: �޴� �Ľ��ϴ� �Լ�
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
        // �Է����Ͽ��� �޴� ���� 2���� �б�


        fin >> menu_level_1;
        fin >> menu_level_2;


        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
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
            case 1:   // "2.1. �α��Ρ� �޴� �κ�
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
            case 1: // "3.1 �Ǹ� �Ƿ� ���" �޴� �κ�
            {
                registration();
                break;
            }
            case 2: // "3.2 ��� ��ǰ ��ȸ" �޴� �κ�
            {
                checksale();
                break;
            }
            case 3: // "3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ" �޴� �κ�
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
            case 1:   // "5.1 ��ǰ �Ǹ� ���" �޴� �κ�
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
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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


