#pragma once
#include <iostream>
#include "employee.h"
using namespace std;
class dht
{
private:
	employee emp;
	int h(int k)
	{
		return (k / 1000);
	}
	int collisions = 0;
	employee* arr = new employee[12]; //preset to 12 merely for collision testing

public:
	dht()
	{
		for (int i = 0; i < 12; i++)
			arr[i] = employee();
	}
	void insert(employee z)
	{
		int index = h(z.getsalary());
		if (arr[index].getname() == "")
			arr[index] = z;
		else
		{
			collisions++;
			int limit = 12;	//can be a dynamic variable, but predefined here for the sake of controlled testing.
			while (arr[index].getname() != "" && limit != 0)
			{
				index = h(index + 1);
				limit--;
			}
			if (arr[index].getname() == "")
			{
				arr[index] = z;
			}
			else
				cout << "No space for employee" << endl;

		}
	}
		

	void remove(employee z)
	{
		int index = h(z.getsalary());
		if (arr[index].getname() == "")
			cout << "Employee not found" << endl;
		else if (arr[index].getname() == z.getname())
			arr[index] = employee(); //empty employee object (method of nullifying an object array)
		else
		{
			int limit = 12;
			while (arr[index].getname() != z.getname() && arr[index].getname()!="" && limit != 0)
			{
				index = h(index + 1);
				limit--;
			}
			if (arr[index].getname() == "" || limit == 0)
			{
				cout << "Employee does not exist in the system" << endl;
			}
			else
				arr[index] = employee();
			
		}
	}
	void print()
	{
		for (int i = 0; i < 12; i++)
			if(arr[i].getname()!="")
			cout << "Employee: " << arr[i].getname() << endl << "Age: " << arr[i].getage() << endl <<
			"Salary: " << arr[i].getsalary() << endl << "Years of experience: " << arr[i].getexperience() << endl << endl;

	}
	void displaycollisions()
	{
		cout << "Number of collisions: " << collisions << endl;
	}
};

