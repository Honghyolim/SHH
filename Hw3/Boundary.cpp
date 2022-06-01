#pragma once
#include "Boundary.h"
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

extern ifstream fin;
extern ofstream fout;

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
        fout << name << " " << SSN << " " << ID << " " << password << endl << endl;
    }

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
        fout << ID << " " << password << endl << endl;
        MemberID = ID;
    }
    else
    {
        fout << "�α��� ����" << endl << endl;
    }
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
    fout << "3.1 �Ǹ� �Ƿ� ���" << endl << ProductName << " " << CompanyName << " " << ProductPrice << " " << RegistationQuantity << endl;

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
    while (productnumber > i) {
        if (control->searchCheckSale(i)) {
            fout << "3.2 ��� ��ǰ ��ȸ" << endl << product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
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
    while (productnumber > i) {
        if (control->searchSoldout(i)) {
            fout << "3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl << product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
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
    while (productnumber > i) {
        if (control->searchSaleStatistic(i)) {
            fout << "5.1 �Ǹ� ��ǰ ���" << endl << product[i].getName() << " " << product[i].getPrice() * product[i].getPurchased() << " " << product[i].getReview();
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