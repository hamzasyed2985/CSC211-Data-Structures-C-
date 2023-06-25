#include <iostream>
using namespace std;
void InsertAtStart();
void InsertAtEnd();
void InsertAfterSpecific();
void InsertBeforeSpecific();
void display();
void DeleteFromStart();
void DeleteAtEnd();
void DeleteAfterSpecific();
void DeleteBeforeSpecific();
struct stu
{
	int id;
	float marks;
	stu *next = NULL;
};

stu *first = NULL;
stu *last = NULL;
int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert At Start: ";
		cout << "\nPress 2 to Insert At End: ";
		cout << "\nPress 3 to Insert After Specific: ";
		cout << "\nPress 4 to Insert Before Specific: ";
		cout << "\nPress 5 to display: ";
		cout << "\nPress 6 to Delete from End: ";
		cout << "\nPress 7 to Delete from Start: ";
		cout << "\nPress 8 to Delete After Specific: ";
		cout << "\nPress 9 to Delete Before Specific: ";
		cout << "\nPress 0 to Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			InsertAtStart();
			break;
		case 2:
			InsertAtEnd();
			break;
		case 3:
			InsertAfterSpecific();
			break;
		case 4:
			InsertBeforeSpecific();
			break;
		case 5:
			display();
			
			break;
		case 6:
			DeleteAtEnd();	 
			break;
		case 7:
			DeleteFromStart();
			 break;
		case 8:
			DeleteAfterSpecific();
			break;
		case 9:
			DeleteBeforeSpecific();
			break;
			
		default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}

void display(){
    stu *p;
	p=first;

	while(p!=NULL)
	{
		cout<<"ID is: "<<p->id<<endl;
		cout<<"Marks are: "<<p->marks<<endl;
		p=p->next;
	}
}

void InsertAtStart(){
	stu *p;
	p = new stu;
	cout << "Enter Your ID: "<<endl;
	cin >> p->id;
	cout << "Enter the Marks: "<<endl;
	cin >> p->marks;
		   if (first == NULL)
		   first = last = p;
	else
	{
		p->next=first;
		first=p; 
	}
}

void InsertAtEnd(){
	// take the pointer to hold the address of stu record
	stu *p;
	// allocate runtime memory for new record of stu using new operator
	p = new stu;
	cout << "Enter Your ID: ";
	cin >> p->id;
	cout << "Enter Your Marks: ";
	cin >> p->marks;
		   /* l i s t i s empty */
		   if (first == NULL)
		   /* p becomes first node and first and last pointer will point to same node */
		   first = last = p;
	else
	{
		/* link the last pointer with newly created node (p) */
		last->next = p;
		last = p; /* assign p to last node */
	}
}

void DeleteAtEnd(){
	stu *p;
	p=first;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		last=NULL;
	}
	else
	{
		while(p->next->next!=NULL)
		{
			p=p->next;
		}	
		p->next=NULL;	 
	}
}

void DeleteFromStart(){
	stu *p;
	p=first;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		first=NULL;
	}
	else
	{
		first=first->next;	 
	}
}

void InsertAfterSpecific(){
	int input;
	stu *p;
	p=first;
	cout<<"Enter ID Number After which you want to Insert: ";
	cin>>input;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		if(p->id==input){
			stu *curr;
			curr=new stu;
			cout << "Enter Your ID: "<<endl;
			cin >> curr->id;
			cout << "Enter the Marks: "<<endl;
			cin >> curr->marks;
			curr->next=p->next;
			p->next=curr;
			last=curr;
		}else {
			cout<<"ID Doesn't Matched";}
	}
	else
	{
		while(p->id!=input){
			p=p->next;
		}
			stu *curr;
			curr=new stu;
			cout << "Enter Your ID: "<<endl;
			cin >> curr->id;
			cout << "Enter the Marks: "<<endl;
			cin >> curr->marks;
			curr->next=p->next;
			p->next=curr;
			 
	}
}

void InsertBeforeSpecific(){
	int input;
	stu *p;
	p=first;
	cout<<"Enter ID Number Before which you want to Insert: ";
	cin>>input;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		if(p->id==input){
			stu *curr;
			curr=new stu;
			cout << "Enter Your ID: "<<endl;
			cin >> curr->id;
			cout << "Enter the Marks: "<<endl;
			cin >> curr->marks;
			curr->next=first;
			first=curr;	
		}else {
			cout<<"ID Doesn't Matched";}
	}
	else
	{	
		stu *prev;
		while(p->id!=input){
			prev=p;
			p=p->next;
		}
			stu *curr;
			curr=new stu;
			cout << "Enter Your ID: "<<endl;
			cin >> curr->id;
			cout << "Enter the Marks: "<<endl;
			cin >> curr->marks;
			prev->next=curr;
			curr->next=p;
	}
}

void DeleteAfterSpecific(){
	
	int input;
	stu *p;
	p=first;
	cout<<"Enter ID Number After which you want to Delete: ";
	cin>>input;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		cout<<"No NOde Exist";
	}
	else
	{
		while(p->id!=input){
			p=p->next;
		}
			p->next=p->next->next;
			
			 
	}
}

void DeleteBeforeSpecific(){
	int input;
	stu *p;
	p=first;
	stu *prev;
    stu *prevtopre;
	cout<<"Enter ID Number Before which you want to Delete: ";
	cin>>input;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first==last)
	{
		cout<<"No Node Exist";	
		}
	
	else
	{
		while(p->id!=input){
            prevtopre=prev;
			prev=p;
			p=p->next;   
        }
			prevtopre->next=p;			 
	}
}

