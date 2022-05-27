#include "hw3.h"


using namespace std;

// Member �����ϴ� ����Ʈ ��������
Member* memberList[100];
int memberCnt = 0;

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
        fout << name << " " << SSN  << " " << ID << " " << password << endl << endl;
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
    
    //cout <<" ID : " <<ID << endl;
    //cout << "PW :"<<password << endl;

    for (int i = 0; i < memberCnt; i++)
    {
        ID2 = memberList[i]->validateID();
        //cout <<"ID2 : " << ID2 <<endl;
        password2 = memberList[i]->validatePW();
        //cout << password2;
        if (ID.compare(ID2) == 0 && password.compare(password2) ==0 )
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
                    //cout << "login" << endl;
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


