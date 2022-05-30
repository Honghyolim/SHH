
#include "pch.h"
#include <iostream>
#include "hw3.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// Member �����ϴ� ����Ʈ ��������
Member* memberList[100];
int memberCnt = 0;
//���� �α����� ����� ID�� �����ϴ� ��������
string MemberID = "";
//Product �����ϴ� ����Ʈ ��������
Product product[100];
//��ϵ� ��ǰ�� ���ڸ� �����ϴ� ��������
int productnumber = 0;


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
        fout << name << " " << SSN << " " << ID << " " << password << endl << endl;
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

//Function : void join()
//Description: ȸ�������� �����ϴ� �Լ�
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
    // control class ����
    SignUp* control = new SignUp;
    // boundary class ���� 
    SignUpUI* boundary = new SignUpUI;
    boundary->enterMemberInfo(control);

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
//

void login()
{
    //control class ����
    Login* control = new Login;
    //boundary class ����
    LoginUI* boundary = new LoginUI;
    boundary->enterIDPW(control);

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

//Function : void registation()
//Description: ��ǰ����� �����ϴ� �Լ�
//Parameters : void
//Return Value : void
//Created : 2022/05/30 15:56 pm 
//author : Ȳ����
//Revisions :
//

void registation()
{
    //control class ����
    Registation* control = new Registation;
    //boundary class ����
    RegistationUI* boundary = new RegistationUI;
    boundary->enterProduct(control);
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
    fout << "3.1 �Ǹ� �Ƿ� ���" << endl << ProductName <<" " << CompanyName<<" "<< ProductPrice <<" "<< RegistationQuantity << endl;

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
            fout <<"3.2 ��� ��ǰ ��ȸ" <<endl<< product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
        }
        i++;
    }
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
            fout<<"3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ"<<endl << product[i].getName() << " " << product[i].getCompany() << " " << product[i].getPrice() << " " << product[i].getRegistation();
        }
        i++;
    }
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
            fout <<"5.1 �Ǹ� ��ǰ ���"<<endl << product[i].getName() << " " << product[i].getPrice() * product[i].getPurchased() << " " << product[i].getReview();
        }
        i++;
    }
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
            case 1: // "3.1 �Ǹ� �Ƿ� ���" �޴� �κ�
            {
                registation();
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

int main() {
    doTask();
}


