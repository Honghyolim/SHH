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

// Member �����ϴ� ����Ʈ ��������
Member* memberList[100];
int memberCnt = 0;
//���� �α����� ����� ID�� �����ϴ� ��������
string MemberID = "";
int MemberSeq;
//Product �����ϴ� ����Ʈ ��������
Product product[100];
//��ϵ� ��ǰ�� ���ڸ� �����ϴ� ��������
int productnumber = 0;
//���� �α����� ����� �����͸� �����ϴ� ��������
Member* currentMember;

//���� ����� ��ü ����
ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

int main() {
    doTask();
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
                //fout << "login" << endl;
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
                break;
            }
            }

        }
        }
    }
    return;
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