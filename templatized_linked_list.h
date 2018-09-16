#include <iostream>
#include <typeinfo>
#include <string>
#include <conio.h>
#include <Windows.h>

template<typename Generic>          // Templatizing the class to make it Generic
class Node
{
public:
	Node(Generic input) : nodeData(input) {}
	Generic nodeData;               // Generic object nodeData
	Node* next;                     // (traditional) next pointer in a Node

	class LinkedList               // Nested Class LinkedList to apply same templatization to this class
	{
	public:
		LinkedList() :head(NULL), tail(NULL), nodeCount(0) {}
		Node* head;                 // Node* pointer to the first node
		Node* tail;                 // Node* pointer to the last node
		int nodeCount;              // To keep track of total nodes (helps in bounds checking)
		char operationMode;         // Store current operation mode of Linked List (int, float, char, etc)

		/*
		void checkInputType(Generic input)
		{
			bool valid = false;
			const char* strType = typeid(input).name();   // Extract user input type (at runtime)
			string inputTypeInString((LPCTSTR)strType);
		} 
		*/
		
		void insertAtStart(Generic input)     // Function to insert nodes to the left of the list [ O(1) ]
		{
			nodeCount++;
			if (head == NULL)
			{
				Node* temp = new Node(input);
				head = temp;
				tail = temp;
				cout << "\n Node created with data: " << temp->nodeData;
			}
			else
			{
				Node* temp = new Node(input);
				temp->next = head;
				head = temp;
				tail->next = NULL;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
		}

		void insertAtEnd(Generic input)  // Function to insert nodes to the right of the list [ O(1) ]
		{
			nodeCount++;
			if (head == NULL)
			{
				Node* temp = new Node(input);
				head = temp;
				tail = temp;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
			else
			{
				Node* temp = new Node(input);
				tail->next = temp;
				tail = temp;
				tail->next = NULL;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
		}

		void insertAtLocation(Generic input, int location)   // Function to insert node at a specific location in the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list created. Please create a linked list first.\n";
				_getch();
				insertionMenu();
			}

			else if (location > nodeCount)
			{
				cout << "\n Invalid location. Current linked list has only " << nodeCount << " node(s). ";
				Sleep(2000);
				insertionMenu();
			}

			nodeCount++;
			int i;
			Node* ptr = NULL;
			for (i = 1, ptr = head; i < location - 1 && i <= nodeCount; ptr = ptr->next, ++i)
			{
			}
			Node* temp = new Node(input);
			temp->next = ptr->next;
			ptr->next = temp;
			cout << "\n New node with data " << temp->nodeData << " created at location " << location << " ";
		}

		void continousDataInputMode()
		{
			system("cls");
			Generic var;
			int size = 0;
			cout << "\n ---------------------------- CONTINUOUS DATA INPUT M0DE ----------------------------\n";
			cout << "\n\n Keep entering successive node's data continuosly."
				<< "\n Use <spacebar> or <enter> to identify separate nodes data."
				<< "\n\n CIM requires the size of the list to operate: ";
			cin >> size;
			cout << "\n Begin entering data: ";
			for (int i = 0; i < size; ++i)
			{
				cout << "\n";
				cin >> var;
				insertAtEnd(var);
			}
			if (head != NULL && tail != NULL)
			{
				cout << "\n All " << size << " data items added successfully to linked list. ";
				Sleep(2500);
			}
			else
			{
				cout << "\n !!! SOME ERROR OCCURRED WHILE STORING DATA !!";
				Sleep(2000);
			}
			insertionMenu();
		}

		void deleteFirstNode()  // Function to delete first node of the list [ O(1) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				Node* temp = head;
				head = head->next;
				cout << "\n First node with data " << temp->nodeData << " deleted successfully. ";
				delete temp;
			}
		}

		void deleteLastNode()  // Function to delete last node of the list [ O(1) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				Node* ptr;
				for (ptr = head; ptr->next != tail; ptr = ptr->next) {}
				ptr->next = NULL;
				cout << "\n Last node with data " << tail->nodeData << " deleted successfully. ";
				delete tail;
				tail = ptr;
			}
		}

		void deleteSpecificNode(int location)  // Function to delete a specific node of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				if (location > nodeCount)
				{
					cout << "\n Invalid location. Current linked list has only " << nodeCount << " node(s). ";
					Sleep(2000);
					deletionMenu();
				}
				Node* ptr;
				int i;
				for (ptr = head, i = 1; ptr->next != NULL && i<location - 1; ptr = ptr->next, ++i) {}
				Node* toBeDeleted = ptr->next;
				ptr->next = ptr->next->next;
				cout << "\n Node " << location << " with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
				delete toBeDeleted;
			}
		}

		void deleteSpecificValue(Generic input)  // Function to delete a node containing specific data of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				Node* ptr=head;
				while (ptr->next != NULL && ptr->next->nodeData != input)
				{
					ptr = ptr->next;
				}
				if (ptr->next == NULL)
				{
					cout << "\n Data " << input << " not found in the list. ";
					Sleep(2000);
					deletionMenu();
				}

				else
				{
					Node* toBeDeleted = ptr->next;
					ptr->next = ptr->next->next;
					cout << "\n Node with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
					delete toBeDeleted;
				}
				/*for (ptr = head, i = 1; ((ptr->next != NULL && ptr->next->nodeData !=input) && i <= nodeCount); ++i) {}
				
				cout << "\n Node " << i << " with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
				 */
			}
		}

		

		void searchByIndex(int location)  // Function to display data in a specified node of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2800);
				commenceOperation();
			}
			else
			{
				if (location > nodeCount)
				{
					cout << "\n Invalid index. Current linked list has only " << nodeCount << " node(s). ";
					Sleep(2000);
					searchMenu();
				}
				Node* ptr;
				int i;
				for (ptr = head, i = 1; ptr->next != NULL && i<location; ++i)
				{
					ptr = ptr->next;

				}
				cout << "\n Data at Node '" << location << "' : '" << ptr->nodeData << "' ";
			}
		}
		
		void searchByValue(Generic data)
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2800);
				commenceOperation();
			}
			else
			{
				bool found = false;
				Node* ptr;
				int i, foundCount = 0;
				for (ptr = head, i = 1; ptr!= NULL && i <= nodeCount; ++i, ptr = ptr->next)
				{
					if (ptr->nodeData == data)
					{
						found = true;
						foundCount++;
						Sleep(600);
						cout << "\n '" << data << "' found at index '" << i << "'.";
						Sleep(700);
						cout << "\n Continuing search to look for duplicates..";
						Sleep(2000);
						if (ptr->next == NULL)
							break;
					}
				}
				if (!ptr == NULL)
				{
					if (ptr->next == NULL && found == false)
						cout << "\n No search results for '" << data << "' ";
					/*else
					{
						cout << "\n\n Found " << foundCount << " matches to '" << data << "'.";
						_getch();
						searchMenu();
					} */
				}
				else
				{
					cout << "\n\n Found " << foundCount << " matches to '" << data << "'.";
					_getch();
					searchMenu();
				}

				
			}
		}

		void commenceOperation()
		{
			// Operation Mode
			std::string operatingType;
			switch (operationMode)
			{
			case '1':
				operatingType = "<INT>";
				break;
			case '2':
				operatingType = "<FLOAT>";
				break;
			case '3':
				operatingType = "<CHAR>";
				break;
			case '4':
				operatingType = "<STRING>";
				break;
			case '5':
				operatingType = "<BOOL>";
				break;
			}

			system("cls");
			cout << "\n ############### DYNAMIC TEMPLATIZED LINKED-LIST IMPLEMENTATION IN C++ ###############\n\n"
				<< "                                     ~ Version 2.0 ~\n\n"
				<< "                          CURRENT MODE OF OPERATION :: " << operatingType << "\n";
			cout << "\n Press 1-6 to choose option:\n\n"
				<< "\t\t 1 - Insertion operations\n"
				<< "\t\t 2 - Deletion operations\n"
				<< "\t\t 3 - Search operations\n"
				<< "\t\t 4 - Delete current linked list\n"
				<< "\t\t 5 - Display current linked list\n"
				<< "\t\t 6 - Change selected Data Structure type\n ";
			char c = _getch();
			switch (c)
			{
			case '1':
				insertionMenu();
				commenceOperation();
				break;

			case '2':
				deletionMenu();
				commenceOperation();
				break;

			case '3':
				searchMenu();
				commenceOperation();
				break;

			case '4':
				if (head == NULL)
				{
					cout << "\n No list already in memory.\n";
					_getch();
					commenceOperation();
				}
				else
				{
					cout << "\n This action is IRREVERSIBLE. Proceed (y/n)?";
					char c = _getch();
					if (c == 'n' || c == 'N')
						commenceOperation();
					else if (c != 'y' && c != 'Y')
					{
						cout << "\n Invalid input. ";
						Sleep(700);
						commenceOperation();
					}
					Node* temp = head;
					while (temp != NULL)
					{
						Node* first = temp;
						temp = temp->next;
						head = temp;
						delete first;
					}
					cout << "\n Deleting nodes";
					Sleep(800);
					cout << ".";
					Sleep(800);
					cout << ".";
					Sleep(800);
					cout << ".";
					cout << "\n Cleaning up memory";
					Sleep(800);
					cout << ".";
					Sleep(800);
					cout << ".";
					Sleep(800);
					cout << ".";
					cout << "\n\n Linked list successfully deleted from existence.\n";
					_getch();
					commenceOperation();
					break;
				}

			case '5':
				printList();
				_getch();
				commenceOperation();

			case '6':
				main();

			default:
				cout << "\n Press 1-5 only. <Press any Key> ";
				_getch();
				commenceOperation();
			}
		}


		void insertionMenu()
		{
			system("cls");
			cout << "\n ------------------------------- INSERTION OPTIONS -------------------------------";
			cout << "\n\n Press 1-5 to select option:\n\n"
				<< "\t\t 1 > Insert a node at the beginning of the Linked List\n"
				<< "\t\t 2 > Insert a node at the end of the Linked List\n"
				<< "\t\t 3 > Insert a node at a location in the Linked List\n"
				<< "\t\t 4 > Continuous Data Input Mode\n"
				<< "\t\t 5 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				cout << "\n Enter data to store at the beginning of the linked list: ";
				cin >> var;
				insertAtStart(var);
				Sleep(2000);
				commenceOperation();
				break;

			case '2':
				cout << "\n Enter data to append to the end of the linked list: ";
				cin >> var;
				insertAtEnd(var);
				Sleep(2000);
				commenceOperation();
				break;

			case '3':
				cout << "\n Enter location where you want to insert a new node: ";
				int loc;
				cin >> loc;
				cin.clear();
				cout << "\n Enter data to store in the new node at location " << loc << " :";
				cin >> var;
				insertAtLocation(var, loc);
				Sleep(2000);
				commenceOperation();
				break;

			case '4':
				continousDataInputMode();
				break;

			case '5':
				commenceOperation();
				break;

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";
				_getch();
				insertionMenu();
				break;
			}
		}

		void deletionMenu()
		{
			system("cls");
			cout << "\n ------------------------------- DELETION OPTIONS -------------------------------";
			cout << "\n\n Press 1-4 to select option:\n\n"
				<< "\t\t 1 > Delete the first node of the Linked List\n"
				<< "\t\t 2 > Delete the last node of the Linked List\n"
				<< "\t\t 3 > Delete a node at a specific location in the Linked List\n"
				<< "\t\t 4 > Delete a node with a specific value in the Linked List\n"
				<< "\t\t 5 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				deleteFirstNode();
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '2':
				deleteLastNode();
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '3':
				cout << "\n Enter location where you want to delete a node: ";
				int loc;
				cin >> loc;
				cin.clear();
				deleteSpecificNode(loc);
				nodeCount--;
				cout << "\n Data at node " << loc << " deleted successfully.\n";
				Sleep(2000);
				commenceOperation();
				break;

			case '4':
				cout << "\n Enter the node data you want to delete: ";
				cin >> var;
				cin.clear();
				deleteSpecificValue(var);
				nodeCount--;
				Sleep(2000);
				_getch();
				commenceOperation();
				break;

			case '5':
				commenceOperation();

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";
				_getch();
				insertionMenu();
				break;
			}
		}

		void searchMenu()
		{
			system("cls");
			cout << "\n ------------------------------- SEARCH OPTIONS -------------------------------";
			cout << "\n\n Press 1-3 to select option:\n\n"
				<< "\t\t 1 > Search data by index in the Linked List\n"
				<< "\t\t 2 > Search data by value the Linked List\n"
				<< "\t\t 3 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				int index;
				cout << "\n Enter (integer) index to check value at it: ";
				cin >> index;
				searchByIndex(index);
				Sleep(4000);
				commenceOperation();
				break;

			case '2':
				cout << "\n Enter data to search in the linked list: ";
				cin >> var;
				searchByValue(var);
				Sleep(4000);
				commenceOperation();
				break;

			case '3':
				commenceOperation();

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";
				_getch();
				searchMenu();
				break;
			}
		}

		void printList()
		{
			std::cout << "\n\n -------------------------------- CURRENT LINKED LIST --------------------------------\n\n\t";
			for (Node* iter = head; iter != NULL; iter = iter->next)
				cout << " " << iter->nodeData;
			std::cout << "\n\n -------------------------------------------------------------------------------------\n";
		}

	};
};

