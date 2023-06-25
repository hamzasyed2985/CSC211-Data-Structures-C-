#include <iostream>
using namespace std;

struct stu
{
	int id;
	float marks;
	stu *next = NULL;
};
stu *first = NULL;
stu *last = NULL;

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

void InsertAtEnd(){

	stu *p;
	p = new stu;
	stu *curr;
	curr=first;
	cout << "Enter Your ID: ";
	cin >> p->id;
	cout << "Enter Your Marks: ";
	cin >> p->marks;
		   if (first == NULL)
		   first = last = p;
	else
	{
		while(curr->next!=NULL){
			curr=curr->next; }
			
			curr->next=p;
			last=p;}
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
		last=p;	 
	}
}

void CheckPalindrome(){
    stu *curr1=first;
	stu *curr2=last;
	stu *prev2=NULL;
	stu* current2=first;
	stu* l=NULL;
	int check;
	while(curr1!=curr2 && curr2->next!=curr1){
		current2=first;
		while(current2->next!=l){
			prev2=current2;
			current2=current2->next;
		}l=current2;
       	
        if(curr1->id==l->id){check=0;}
        else{check=1;}
	curr1=curr1->next;
	curr2=prev2;
	}if(check==0){cout<<"PAlindrome";}
    else{cout<<"NOT PAlindrome";}	
			
}





	












int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert At End: ";
		cout << "\nPress 2 to display: ";
		cout << "\nPress 3 to Delete from End: ";
        cout << "\nPress 4 to check palindrome: "<<endl;
		cin >> option;
		switch (option)
		{
		case 1:
			InsertAtEnd();
			break;
		case 2:
			display();
			break;
		case 3:
			DeleteAtEnd();	 
			break;
        case 4:
			CheckPalindrome();	 
			break;
        
		default:
			cout << "Please Enter Correct Choice";
			break;
		}

	} while (option != 0);
}





