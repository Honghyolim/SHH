#pragma once
#include "Control.h"
#include "Entity.h"


//���� �α����� ����� ID�� �����ϴ� ��������
extern string MemberID;
extern int MemberSeq;
//��ϵ� ��ǰ�� ���ڸ� �����ϴ� ��������
extern int productnumber;
// Product �����ϴ� ����Ʈ ��������
extern Product product[100];
extern int memberCnt;
// Member �����ϴ� ����Ʈ ��������
extern Member* memberList[100];
Buyer* now;

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
//Description: �ǸſϷ��� ��ǰ���� Ȯ�� �ϴ� �Լ�
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:03 pm 
//author : Ȳ����
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
//Description: ����ڰ� �Ǹ��� ��ǰ���� Ȯ���ϴ� �Լ�
//Parameters : int
//Return Value : bool
//Created : 2022/05/30 16:08 pm 
//author : Ȳ����
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
// Description : �˻� control class
// Created : 2022/6/1 5:36 pm
// Author : ������
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
    return "��ǰ ����";
}

Search::~Search() {
}

// Class : Purchase
// Description : ��ǰ ���� control class
// Created : 2022/6/1 5:36 pm
// Author : ������
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
    return "�ֱ� �˻��� ��ǰ�� ����";
}

// Class : PurchasedList
// Description : ��ǰ ���� ���� ��ȸ control class
// Created : 2022/6/1 5:36 pm
// Author : ������
// mail : jwutn908@gmail.com
// Revisions :
//   1. When& Who :
//      What :
// 
//
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