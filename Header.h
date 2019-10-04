#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
	string employeelogin();
	string username;
	

	friend int main();
protected:
	//string username;
	string password;
private:
	string EmployeeInfo[3];


};
