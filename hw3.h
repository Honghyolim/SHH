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
//	1. When& Who :
//	   What :
// 
//

class SignUp;
class SignUpUI
{
private:
	
public:
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
//	1. When& Who :
//	   What :
// 
//

class SignUp
{
	private:

	public:

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
		void deleteMember();

};

// Class : LoginUI
// Description : �α��� boundary class
// Created : 2022/5/27 5:47 pm
// Author : ȫȿ��
// mail : hyolim.korea@gmail.com
// Revisions :
//	1. When& Who :
//	   What :
// 
//
class Login;
class LoginUI
{
private:

public:
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
//	1. When& Who :
//	   What :
// 
//

class Login
{
private:

public:

	bool validateID(string, string);

};





