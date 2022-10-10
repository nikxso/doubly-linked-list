#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	struct Node *prev;
	char data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *link = NULL;

//function
void insert(int type);
void display(int type);
void DisLines();
int count_Node();

// main function
int main()
{
	
	dashboard:

	int usr_choice;

	cout<<endl<<"Dashboard:- Press following key to perform Operation: ";
	cout<<endl<<"Create Linklist/Insert Operations: \n\t1- Insert at the end\n\t2- Insert at start\n\t3-Insert after Particular Node";
	cout<<endl<<"Display Operations: \n\t4- Display Forward\n\t5- Display Reverse";
	cout<<endl<<"Delete Operations: \n\t6- Delete first node\n\t7- Delete last node\n\t8- Delete a Particular node";
	cout<<endl<<"9- Exit dashboard: \n";
	cin>>usr_choice;

	switch(usr_choice){
		case 1: insert(0);goto dashboard;break; 
		case 2: insert(1);goto dashboard;break; 
		case 3: insert(2);goto dashboard;break; 
		case 4: display(0);goto dashboard;break; 
		case 5: display(1);goto dashboard;break;
		case 9: break;
		default: cout<<endl<<"You've entered other then following key";
	}	
	

	return 0;
}


//Insertion function
void insert(int type){
	/*	type 0 - insert at the end
	 	type 1 - insert at begining
	 	type 2 - insert after particular node
	*/
	
	//variables
	char userdata;
	int n;

	if(type == 0){

		cout<<"[Insertion at End]: Enter number of node you want to insert: ";
		cin>>n;

		if(n<=0){
			cout<<endl<<"You've to insert atleast 1 node in linklist";
		}else{

			for(int i = 1;i<=n;i++){

				cout << endl << "Enter data for "<<i<<": ";
				cin >> userdata;
				
				if (head == NULL)
				{
					struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
					ptr->data = userdata;
					ptr->next = NULL;
					ptr->prev = NULL;
					head = ptr;
					link = ptr;
				}
				else
				{
					struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
					ptr->data = userdata;
					ptr->next = NULL;
					link->next = ptr;
					ptr->prev = link;
					link = link->next;
				}

			}

		}
	}else if(type == 1){

		cout<<"[Insertion at start]: Enter number of node you want to insert: ";
		cin>>n;

		if(n<=0){
			cout<<endl<<"You've to insert atleast 1 node in linklist";
		}else{

			for(int i = 1;i<=n;i++){

				cout << endl << "Enter data for "<<i<<": ";
				cin >> userdata;
				
				if (head == NULL)
				{
					struct Node *ptRRR = (struct Node *)malloc(sizeof(struct Node));
					ptRRR->data = userdata;
					ptRRR->next = NULL;
					ptRRR->prev = NULL;
					head = ptRRR;
					link = ptRRR;
				}
				else
				{	
					struct Node *ptRRR = (struct Node *)malloc(sizeof(struct Node));
					struct Node *se = head;

					while(se->prev != NULL){
						se = se->prev;
					}
					ptRRR->data = userdata;
					se->prev = ptRRR;
					ptRRR->next = se;
					ptRRR->prev = NULL; 
					head = ptRRR;

				}

			}

		}
	}

}
void DisLines(){
	for(int i = 0; i<=count_Node(); i++){
		cout<<"--";
	}
	cout<<endl;
}
void display(int type){
	/*
		type 0 - Display Forward
		type 1 - Display Reverse
	*/
		system("cls");
	if(type == 0){
		struct Node *ptr = head;
		//display lines
		DisLines();	
			while (ptr != NULL)
			{
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
		cout<<endl;
		DisLines();
		delete(ptr);
	}else if(type == 1){
		struct Node *pTr = link;

		DisLines();	
		while (pTr != NULL)
		{
			cout<<pTr->data<<" ";
			pTr = pTr->prev;
		}
		cout<<endl;
		DisLines();	
		delete(pTr);

	}
}

int count_Node(){
	int count = 0;
struct Node *ppt = head;
	while(ppt !=NULL){
		count++;
		ppt = ppt->next;
	}
	delete(ppt);
	return count;
}