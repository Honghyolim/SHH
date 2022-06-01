#include "hw3.h"


using namespace std;

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
        fout <<"> "<< name << " " << SSN  << " " << ID << " " << password << endl << endl;
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

SignUpUI::SignUpUI(SignUp*control)
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

LoginUI* Login:: createBoundary(Login* control)
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
    LoginUI*boundary = this->createBoundary(this);
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
            currentMember = memberList[i];
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
    fout<<"> " << ID << endl << endl;
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

LogOutUI :: LogOutUI(LogOut*control)
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

LogOutUI* LogOut:: createBoundary(LogOut*control)
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

void LogOut::logOut(LogOutUI*boundary)
{
    string ID = MemberID;
    MemberID = "";
    boundary->sendLogOutMsg(ID);
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


