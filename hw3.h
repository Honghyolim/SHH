#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

void doTask();

// Class : SignUpUI
// Description : ȸ������ boundary class
// Created : 2022/5/27 12:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:12 pm by ȫȿ��
//	   What : control atrribute �߰�, ������ ����
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
// Description : ȸ������ control class
// Created : 2022/5/27 12:46 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:13 pm by ȫȿ��
//	   What : createBoundary �Լ� �߰�, ������ ����
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
// Description : ȸ�� entity class
// Created : 2022/5/27 12:50 pm
// Author : ȫȿ��
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
// Description : �α��� boundary class
// Created : 2022/5/27 5:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by ȫȿ��
//	   What : control atrribute �߰�, ������ ����
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
// Description : �α��� control class
// Created : 2022/5/27 5:48 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who : 2022/06/01 3:05 pm by ȫȿ��
//	   What : createBoundary �Լ� �߰�, ������ ����
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
// Description : ȸ��Ż�� boundary Ŭ����
// Created : 2022/6/1 12:50 pm
// Author : ȫȿ��
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
// Description : ȸ��Ż�� control Ŭ����
// Created : 2022/6/1 12:50 pm
// Author : ȫȿ��
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
// Description : �α׾ƿ� boundary Ŭ����
// Created : 2022/6/1 2:28 pm
// Author : ȫȿ��
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
// Description : �α׾ƿ� control Ŭ����
// Created : 2022/6/1 2:30 pm
// Author : ȫȿ��
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








