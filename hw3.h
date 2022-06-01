#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

void doTask();

// Class : SignUpUI
// Description : 회원가입 boundary class
// Created : 2022/5/27 12:47 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:12 pm by 홍효림
//	   What : control atrribute 추가, 생성자 선언
// 
//

class SignUp;
class SignUpUI
{
private:
	SignUp* control;
public:
	SignUpUI(SignUp*);
	void enterMemberInfo(SignUp*);
	//void startInterface();
	//void sendSignUpmsg();

};

// Class : SignUp
// Description : 회원가입 control class
// Created : 2022/5/27 12:46 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:13 pm by 홍효림
//	   What : createBoundary 함수 추가, 생성자 선언
// 
//

class SignUp
{
	private:
		SignUpUI* createBoundary(SignUp*);
	public:
		SignUp();
		bool createNewMember(string, string, string, string);

};

// Class : Member
// Description : 회원 entity class
// Created : 2022/5/27 12:50 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//
class SignOutUI;
class Member
{

	private:
		string ID;
		string password;
		string SSN;
		string name;

	public:
		Member(string, string, string, string);
		bool createMember(Member*);
		string validateID();
		string validatePW();
		void deleteMember(SignOutUI*);

};

// Class : LoginUI
// Description : 로그인 boundary class
// Created : 2022/5/27 5:47 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by 홍효림
//	   What : control atrribute 추가, 생성자 선언
// 
//
class Login;
class LoginUI
{
private:
	Login* control;
public:
	LoginUI(Login*);
	void enterIDPW(Login*);
	//void startInterface();
	//void sendSignUpmsg();
};


// Class : Login
// Description : 로그인 control class
// Created : 2022/5/27 5:48 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by 홍효림
//	   What : createBoundary 함수 추가, 생성자 선언
// 
//

class Login
{
private:
	LoginUI* createBoundary(Login*);
public:
	Login();
	bool validateID(string, string);

};

// Class : SignOutUI
// Description : 회원탈퇴 boundary 클래스
// Created : 2022/6/1 12:50 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 
//	   What : 
// 
//

class SignOut;
class SignOutUI
{
private:
	SignOut* control;
public:
	SignOutUI(SignOut*);
	void sendSignOutMsg(string);
};

// Class : SignOut
// Description : 회원탈퇴 control 클래스
// Created : 2022/6/1 12:50 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class SignOut
{
private:
	SignOutUI* createBoundary(SignOut*);
public:
	SignOut();
	void deleteMember(SignOutUI*);
};

// Class : LogOutUI
// Description : 로그아웃 boundary 클래스
// Created : 2022/6/1 2:28 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class LogOut;
class LogOutUI
{
private:
	LogOut* control;
public:
	LogOutUI(LogOut*);
	void sendLogOutMsg(string);
};

// Class : LogOut
// Description : 로그아웃 control 클래스
// Created : 2022/6/1 2:30 pm
// Author : 홍효림
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//

class LogOut
{
private:
	LogOutUI* createBoundary(LogOut*);
public:
	LogOut();
	void logOut(LogOutUI*);
};








