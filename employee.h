#pragma once
#include <iostream>
using namespace std;

class employee
{
private:
	string name;
	int age;
	int salary;
	int experience;
public:
	employee(string n = "", int a = 0, int s = 0, int e = 0)
	{
		name = n;
		age = a;
		salary = s;
		experience = e;
	}
	int getsalary()
	{
		return salary;
	}
	int getage()
	{
		return age;
	}
	int getexperience()
	{
		return experience;
	}
	string getname()
	{
		return name;
	}
};

