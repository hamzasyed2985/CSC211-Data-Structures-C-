#include <iostream>
using namespace std;

struct stu
{
	int id;

	stu *next = NULL;
};
stu *first = NULL;

stu *first2 = NULL;

stu *first3 = NULL;


void display(){
    stu *p;
	p=first;
if(first!=NULL){
do
	{
		cout<<"ID is: "<<p->id<<endl;
		p=p->next;
	}	while(p!=first);
}
}

void InsertAtEnd(){

	stu *p;
	p = new stu;
	stu *curr;
	curr=first;
	cout << "Enter Your ID: ";
	cin >> p->id;
	
		   if (first == NULL){
		   first = p;
           first->next=first;}
	else
	{
		while(curr->next!=first){
			curr=curr->next; }
			
			curr->next=p;
			p->next=first;
    }
            
}

void display2(){
    stu *p;
	p=first2;
	if(first2!=NULL){
do
	{
		cout<<"ID is: "<<p->id<<endl;
		
		p=p->next;
	}	while(p!=first2);
}
}

void InsertAtEnd2(){

	stu *p;
	p = new stu;
	stu *curr;
	curr=first2;
	cout << "Enter Your ID: ";
	cin >> p->id;
	
		   if (first2 == NULL){
		   first2 = p;
           first2->next=first2;}
	else
	{
		while(curr->next!=first2){
			curr=curr->next; }
			
			curr->next=p;
			p->next=first2;
    }
            
}

void display3(){
    stu *p;
	p=first3;
	if(first3!=NULL){
do
	{
		cout<<"ID is: "<<p->id<<endl;
		p=p->next;
	}	while(p!=first3);
}
}


void InsertAtEndList3(stu* p){
	stu *curr1;
	curr1=first3;
	if (first3==NULL){
		first3=p;
		first3->next=first3;
	}
	else{
		while(curr1->next!=first3){
			curr1=curr1->next;
		}
		curr1->next=p;
		p->next=first3;
	
	}
}

void FindMinOfTwoListsAndInsertSortedInLastList(){
do{	
    stu* curr1=first;
	stu* curr2=first2;
	stu* prev1=NULL;
	stu* prev2=NULL;
	stu* prev1Temp=NULL;
	stu* prev2Temp=NULL;
	stu* temp1;
	int Temp1=INT_MAX;
	stu* temp2;
	int Temp2=INT_MAX;




do
{	if(first==NULL){break;}
	if(curr1->id<Temp1 )
	{	Temp1=curr1->id;
		temp1=curr1;
	prev1Temp=prev1;
	}
	prev1=curr1;
	curr1=curr1->next;
}while(curr1!=first);
do
{	if(first2==NULL){break;}
	if(curr2->id<Temp2 )
	{	Temp2=curr2->id;
		temp2=curr2;
	prev2Temp=prev2;
	}
	prev2=curr2;
	curr2=curr2->next;
}while(curr2!=first2);


if(first2==NULL || Temp1<=Temp2){
	if(temp1==first && first->next!=first){
	first=first->next;
	prev1->next=first;
	}
	else if(first->next==first){
		first=NULL;
	}
	else{
	prev1Temp->next=temp1->next;	
	}
	InsertAtEndList3(temp1);
}else if(first==NULL || Temp2<=Temp1){
	if(temp2==first2 && first2->next!=first2){
	first2=first2->next;
	prev2->next=first2;
	}
	else if(first2->next==first2){
		first2=NULL;
	}
	else {
	prev2Temp->next=temp2->next;	
	}
	InsertAtEndList3(temp2);
}
	
}while(first!=NULL || first2!=NULL);
    
}

int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert At End: ";
		cout << "\nPress 2 to display: ";
        cout << "\nPress 4 to Insert At End LIST 2: ";
		cout << "\nPress 5 to display LIST 2: ";
		cout << "\nPress 8 to display LIST 3: ";
        cout << "\nPress 10 to Perform Main Function: "<<endl;
		cin >> option;
		switch (option)
		{
		case 1:
			InsertAtEnd();
			break;
		case 2:
			display();
			break;
        case 4:
			InsertAtEnd2();
			break;
		case 5:
			display2();
			break;
		case 8:
			display3();
			break;
        case 10:
			FindMinOfTwoListsAndInsertSortedInLastList();	 
			break;
        
		default:
			cout << "Please Enter Correct Choice";
			break;
		}

	} while (option != 0);
}





