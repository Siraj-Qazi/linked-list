#include <iostream>
#include <string>
#include "templatized_linked_list.h"
using namespace std;

int main()
{
	system("cls");
	cout << "\n ################# DYNAMIC TEMPLATIZED LINKED-LIST IMPLEMENTATION IN C++ ################\n";
	cout << "                                     ~ Version 2.0 ~\n\n"
		<< " ########################################################################################\n";
	cout << "\n Welcome. Choose your linked-list data type: \n";
	cout << "\n Press 1-5 to select option:\n\n"
		<< "\t\t 1 > Integer\t\t\t\t(int)\n"
		<< "\t\t 2 > Decimal\t\t\t\t(float)\n"
		<< "\t\t 3 > Single Character\t\t\t(char)\n"
		<< "\t\t 4 > Sequence of characters\t\t(string)\n"
		<< "\t\t 5 > Boolean variable\t\t\t(bool)\n ";

	char c = _getch();
	if (c == '1')
	{
		Node<int>::LinkedList L_int;
		L_int.operationMode = c;
		L_int.commenceOperation();
	}
	else if (c == '2')
	{
		Node<float>::LinkedList L_float;
		L_float.operationMode = c;
		L_float.commenceOperation();
	}
	else if (c == '3')
	{
		Node<char>::LinkedList L_char;
		L_char.operationMode = c;
		L_char.commenceOperation();
	}
	else if (c == '4')
	{
		Node<std::string>::LinkedList L_str;
		L_str.operationMode = c;
		L_str.commenceOperation();
	}
	else if (c == '5')
	{
		Node<bool>::LinkedList L_bool;
		L_bool.operationMode = c;
		L_bool.commenceOperation();
	}
	else
	{
		cout << "\n Please press 1-5. ";
		_getch();
		main();
	}

}