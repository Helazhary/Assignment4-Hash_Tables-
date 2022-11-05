#pragma once
#include <iostream>
#include "employee.h"
using namespace std;

struct node
{
	employee emp;
	node* next = NULL;
};

class lht
{
private:
	node* arr[11]; //preset to 11 simply to fullfill the scope of the assignment
	int h(int k)
	{
		return (k / 1000);
	}
	int collisions=0;
public:
	lht()
	{
		for (int i = 0; i < 11; i++)
		{
			arr[i] = NULL;
		}

	}
	void insert(employee z)
	{
		
		node* x = new node;
		x->emp = z;

		int index = h(z.getsalary());
		if (arr[index] == NULL)
		{
			arr[index] = x;
		}
		else
		{
			collisions++;
			while (x->next != NULL)
			{
				x = x->next;
			}
				x->next = x;
				
		}
	}
	void remove(employee z)
	{
		int index = h(z.getsalary());
		if (arr[index] == NULL)
			cout << "Employee does not exist in the system" << endl;
		else if (arr[index]->emp.getname() == z.getname())
		{
			node* removedemployee = arr[index];
			arr[index] = arr[index]->next;
			delete removedemployee;
		}
		else
		{
			node* p, * c;
			p = arr[index];
			c = arr[index];
			while (c != NULL && c->emp.getname() != z.getname())
			{
				p = c;
				c = c->next;
			}
			if (c->emp.getname() == z.getname())
			{
				p->next = c->next;
				delete c;
			}
			else
				cout << "Employee does not exist in the system" << endl;
		}
	}
	void print()
	{
		for (int i = 0; i < 11; i++)
		{
			node* cursor = arr[i];
			if(arr[i]!=NULL)
			{ 
				cout << "Employees with salary " << arr[i]->emp.getsalary() << ": ";
				while (cursor != NULL)
				{
						cout<<arr[i]->emp.getname() <<"/";
					cursor = cursor->next;

				}
				cout << endl;
			}
			
		}
	}
	void dipsplaycollisions()
	{
		cout << "Number of collisions: " << collisions << endl;
	}

};

