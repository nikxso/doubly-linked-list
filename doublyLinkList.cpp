#include <iostream>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *next;
};

struct Node *head = NULL;

void insert_beigining()
{
	char userdata, choice;
	do
	{
		cout << endl
			 << "Enter data: ";
		cin >> userdata;
		if (head == NULL)
		{
			struct Node *_node = (struct Node *)malloc(sizeof(struct Node));
			_node->data = userdata;
			_node->next = NULL;
			_node->left = NULL;
			head = _node;
		}
		else
		{
			struct Node *_node = (struct Node *)malloc(sizeof(struct Node));
			_node->data = userdata;
			_node->left = NULL;
			_node->next = head;
			head->left = _node;
			head = _node;
		}
		cout << endl
			 << "Do you wanna insert more data?(Y/N)";
		cin >> choice;

	} while ((choice == 'Y') || (choice == 'y'));
}

void insert_end()
{
	char userdata, choice;
	do
	{
		cout << endl
			 << "Enter data: ";
		cin >> userdata;
		if (head == NULL)
		{
			struct Node *_end = (struct Node *)malloc(sizeof(struct Node));
			_end->data = userdata;
			_end->next = NULL;
			_end->left = NULL;
			head = _end;
		}
		else
		{
			struct Node *_end = (struct Node *)malloc(sizeof(struct Node));
			struct Node *second = head;

			while (second->next != NULL)
			{
				second = second->next;
			}
			_end->data = userdata;
			second->next = _end;
			_end->left = second;
			_end->next = NULL;
		}
		cout << endl
			 << "Do you wanna insert more data?(Y/N)";
		cin >> choice;

	} while ((choice == 'Y') || (choice == 'y'));
}

int checklocation(char loc)
{
	struct Node *ptr = head;
	while (ptr->data != loc)
	{
		ptr = ptr->next;
		if (ptr->next == NULL)
		{
			if (loc != ptr->data)
			{

				cout << "\n--------------------------------------\n";
				cout << "seems like there is no '" << loc << "' present in linklist" << endl;

				cout << "\n--------------------------------------\n";
				return 1;
				break;
			}
			else
			{
				return 0;
			}
		}
	}
	cout<<checklocation(loc);
}
void insert_after_perticular()
{
	char loc, userdata;

	cout << endl
		 << "Enter the Location: ";
	cin >> loc;
	if (checklocation(loc) != 1)
	{
		cout << endl
			 << "Enter data: ";
		cin >> userdata;

		struct Node *_end = (struct Node *)malloc(sizeof(struct Node));
		struct Node *second = head;
		while (second->data != loc)
		{
			second = second->next;
		}
		_end->data = userdata;
		_end->next = second->next;
		_end->left = second;
		second->next = _end;
		second->next->left = _end;
	}
}
void displayFromBeigining()
{
	cout << "---------------" << endl;
	struct Node *ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl
		 << "---------------" << endl;
}

void displayFromEnd()
{
	cout << "---------------" << endl;

	struct Node *ptr = head;
	while (ptr->next != NULL)
	{

		ptr = ptr->next;
	}
	struct Node *loc = ptr;
	while (loc->left != NULL)
	{
		cout << loc->data << " ";
		loc = loc->left;
	}
	cout << head->data;

	cout << endl
		 << "---------------" << endl;
}
void delete_first()
{
	struct Node *ptr;
	if (head == NULL)
	{
		cout << "\n--------------------------------------\n";
		cout << "\nLinklist is emplay, can't delete first element\n";
		cout << "\n--------------------------------------\n";
	}
	else if (head->next == NULL)
	{
		head = NULL;
		free(head);
		cout << "\n--------------------------------------\n";
		cout << "ELement Successfully delete ";
		cout << "\n--------------------------------------\n";
	}
	else
	{
		ptr = head;
		head = head->next;
		head->left = NULL;
		free(ptr);
		cout << "\n--------------------------------------\n";
		cout << "ELement Successfully delete ";
		cout << "\n--------------------------------------\n";
	}
}
void delete_last()
{
	if (head == NULL)
	{
		cout << "\n--------------------------------------\n";
		cout << "\nLinklist is emplay, can't delete last element\n";
		cout << "\n--------------------------------------\n";
	}
	else if (head->next == NULL)
	{
		head = NULL;
		free(head);
		cout << "\n--------------------------------------\n";
		cout << "\nELement Successfully delete\n";
		cout << "\n--------------------------------------\n";
	}
	else
	{
		struct Node *ptr;
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->left->next = NULL;
		free(ptr);
		cout << "\n--------------------------------------\n";
		cout << "ELement Successfully delete ";
		cout << "\n--------------------------------------\n";
	}
}

void delete_perticular()
{
	char loc;

	cout << endl
		 << "Enter the Location: ";
	cin >> loc;
	if (checklocation(loc) != 1)
	{
		struct Node *ptr = head;

		if (loc == head->data)
		{
			ptr = head->next;
			ptr->left = NULL;
			free(head);
			head = ptr;
			cout << "\n--------------------------------------\n";
			cout << "ELement Successfully delete ";
			cout << "\n--------------------------------------\n";
		}
		else
		{

			while (ptr->data != loc)
			{
				ptr = ptr->next;
			}
			struct Node *extra = ptr;
			extra->left->next = ptr->next;
			ptr = NULL;
			free(ptr);
			cout << "\n--------------------------------------\n";
			cout << "ELement Successfully delete ";
			cout << "\n--------------------------------------\n";
		}
	}
}
int main()

{
dashboard:
	int choice;
	cout << endl
		 << "(dashboard) press key to perform operation: ";
	cout << endl
		 << "   *Insertion of Node:- \n\t1.Insert at last";
	cout << endl
		 << "\t2.Insert at beigining";
	cout << endl
		 << "\t3.Insertion after Particular Node";
	cout << endl
		 << "   *Fetch all Node:- \n\t4.display from start\n\t5.display from end";
	cout << endl
		 << "   *Delection of Node:- \n\t6.delete first element\n\t7.delete last element";
	cout << endl
		 << "\t8.delete a perticualr element";

	cout << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		insert_end();
		goto dashboard;
		break;
	case 2:
		insert_beigining();
		goto dashboard;
		break;
	case 3:
		insert_after_perticular();
		goto dashboard;
		break;
	case 4:
		displayFromBeigining();
		goto dashboard;
		break;
	case 5:
		displayFromEnd();
		goto dashboard;
		break;
	case 6:
		delete_first();
		goto dashboard;
		break;
	case 7:
		delete_last();
		goto dashboard;
		break;
	case 8:
		delete_perticular();
		goto dashboard;
		break;
	default:
		cout << "You've entered other then following key\n";
		break;
	}

	// displayFromBeigining();
	return 0;
}