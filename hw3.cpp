#include "hw3.h"


using namespace std;

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
        fout <<"> "<< name << " " << SSN  << " " << ID << " " << password << endl << endl;
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

SignUpUI::SignUpUI(SignUp*control)
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

LoginUI* Login:: createBoundary(Login* control)
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
    LoginUI*boundary = this->createBoundary(this);
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
    fout<<"> " << ID << endl << endl;
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

LogOutUI :: LogOutUI(LogOut*control)
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

LogOutUI* LogOut:: createBoundary(LogOut*control)
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

void LogOut::logOut(LogOutUI*boundary)
{
    string ID = MemberID;
    MemberID = "";
    boundary->sendLogOutMsg(ID);
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


