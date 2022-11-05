#include <iostream>
#include "lht.h"
#include "dht.h"
#include "employee.h"
using namespace std;

int main()
{
	employee Mina("Mina", 30, 10000, 4);
	employee Fawzy("Fawzy", 45, 5000, 8);
	employee Yara("Yara", 19, 2000, 0);
	employee Mariam("Mariam", 32, 8000, 2);
	employee Ayman("Ayman", 33, 4000, 8);
	employee Roshdy("Roshdy", 28, 9000, 3);
	employee Aya("Aya", 26, 6000, 3);
	employee Abdallah("Abdallah", 29, 7000, 4);
	employee Fatma("Fatma", 21, 3000, 1);

	cout << "Employee table using linked lists" << endl << endl;
	lht ll_etable;
	ll_etable.insert(Mina);
	ll_etable.insert(Fawzy);
	ll_etable.insert(Yara);
	ll_etable.insert(Mariam);
	ll_etable.insert(Ayman);
	ll_etable.insert(Roshdy);
	ll_etable.insert(Aya);
	ll_etable.insert(Abdallah);
	ll_etable.insert(Fatma);
	ll_etable.print();
	ll_etable.dipsplaycollisions();
	cout << endl;
	cout << "Employee table after removing Abdallah" << endl << endl;
	ll_etable.remove(Abdallah);
	ll_etable.print();
	cout << endl << endl;


	cout << "Employee table using dynamic arrays" << endl << endl;
	dht d_etable;
	d_etable.insert(Mina);
	d_etable.insert(Fawzy);
	d_etable.insert(Yara);
	d_etable.insert(Mariam);
	d_etable.insert(Ayman);
	d_etable.insert(Roshdy);
	d_etable.insert(Aya);
	d_etable.insert(Abdallah);
	d_etable.insert(Fatma);
	d_etable.print();
	d_etable.displaycollisions();
	cout << endl;
	cout << "Employee table after removing Mariam" << endl << endl;
	d_etable.remove(Mariam);
	d_etable.print();
	cout << endl << endl;




}
