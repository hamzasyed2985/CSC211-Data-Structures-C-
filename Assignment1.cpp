#include <iostream>
using namespace std;

struct stu
{
	int id;
	float marks;
	stu *next = NULL;
};
stu *first2=NULL;
stu *last2=NULL;
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

void displayList2(){
    stu *p;
	p=first2;
	
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

void InsertAtEndList2(){

	stu *p;
	p = new stu;
	stu *curr;
	curr=first2;
	cout << "Enter Your ID: ";
	cin >> p->id;
	cout << "Enter Your Marks: ";
	cin >> p->marks;
		   if (first2 == NULL)
		   first2 = last2 = p;
	else
	{
		while(curr->next!=NULL){
			curr=curr->next; }
			
			curr->next=p;
			last2=p;}
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

void DeleteAtEndList2(){
	stu *p;
	p=first2;
	if (first2 == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first2==last2)
	{
		last2=NULL;
	}
	else
	{
		while(p->next->next!=NULL)
		{
			p=p->next;
		}	
		p->next=NULL;
		last2=p;	 
	}
}

void ReverseDisplay()
{
    stu *p;
    stu *l;
    stu *k;
    l=NULL;
    while(l!=first)
    {
	    p=first;
	    while(p!=l)
	    {
		    k=p;
		    p=p->next;
	    } 
    cout<<"ID is: "<<k->id<<endl;
	cout<<"Marks are: "<<k->marks<<endl;
        l=k;
    }
}

void ReverseDisplayRecursion(stu *p)
{
	if(p!=NULL)
    {
		ReverseDisplayRecursion(p->next);
	cout<<"ID is: "<<p->id<<endl;
	cout<<"Marks are: "<<p->marks<<endl;
	}
}

void Reverse(){
	stu *p;
	stu *next=NULL;
	stu *prev=NULL;
	p=first;
	
	while (p!=NULL){
		next=p->next;
		p->next=prev;
		prev=p;
		p=next;
}
	last=first;
	first =prev;
}

void SwapTwoNodes(){
	stu *curr1;
	stu *prev1=NULL;
	curr1=first;
	stu *curr2;
	stu *prev2=NULL;
	curr2=first;
	int id1,id2;
	stu* newP;
	cout<<"Enter Id for First Node: "<<endl;
	cin>>id1;
	cout<<"Enter Id for Second Node: "<<endl;
	cin>>id2;
	if(id1==id2)
	return;

	while(curr1->id!=id1){
			prev1=curr1;
			curr1=curr1->next;
		}
	while(curr2->id!=id2){
			prev2=curr2;
			curr2=curr2->next;
		}
	if(curr1==NULL||curr2==NULL){
		return;
	}

	if(prev1!=NULL){
		prev1->next = curr2;
	}else 
		first=curr2;
	
	if(prev2!=NULL){
		prev2->next = curr1;
	}else 
		first=curr1;

	newP=curr2->next;
	curr2->next=curr1->next;
	curr1->next=newP;
	
}

void InsertInSortLinkedList(){
	stu *p=new stu;
	stu *curr1;
	stu *prev1=first;
	curr1=first;
	int x;
	float y;
	cout << "Enter Your ID: ";
	cin >>x;
	p->id=x;
	cout << "Enter Your Marks: ";
	cin >> y;
	p->marks=y;
	if (first==NULL){
		first=last=p;
	}
	else if((p->id)<(first->id)){
			p->next=curr1;
			first=p;
	}else if((p->id)>(last->id)) {
			last->next=p;
			last=p;
	}
	else{
	while(!(p->id>=prev1->id && p->id<=curr1->id )){
			prev1=curr1;
			curr1=curr1->next;
	}
	prev1->next=p;
	p->next=curr1;
	}
}

void InsertInSortLinkedList2(stu* p){
	stu *curr1;
	stu *prev1=first2;
	curr1=first2;
	if (first2==NULL){
		first2=last2=p;
	}
	else if((p->id)<(first2->id)){
			p->next=curr1;
			first2=p;
	}else if((p->id)>(last2->id)) {
			last2->next=p;
			last2=p;
	}
	else{
	while(!(p->id>=prev1->id && p->id<=curr1->id )){
			prev1=curr1;
			curr1=curr1->next;
	}
	prev1->next=p;
	p->next=curr1;
	}
}

void swapValues(stu* p,stu* q){
	int TempId;
    float TempMarks;

        TempId=q->id;
		TempMarks=q->marks;
		q->id=p->id;
		q->marks=p->marks;
		p->id=TempId;
		p->marks=TempMarks;
}

void swapAllNodes(){
	stu *curr1=first;
	stu *curr2=last;
	stu *prev2=NULL;
	stu* current2=first;
	stu* l=NULL;
	
	while(curr1!=curr2 && curr2->next!=curr1){

		swapValues(curr1,curr2);
		current2=first;
		while(current2->next!=l){
			prev2=current2;
			current2=current2->next;
		}l=current2;	
	
	curr1=curr1->next;
	curr2=prev2;
	}	
			
}


void Merge(){
	bool swapped;
    stu* curr1;
    stu* curr2 = NULL;
	stu* TEMP;
	stu* prev=NULL;
    
    if (first2 == NULL)
        return;
    do
    { 
        swapped = false; 
        curr1 = first2; 
  
        while (curr1->next != curr2) 
        { 
            if (curr1->id > curr1->next->id) 
            { 
                swapValues(curr1, curr1->next); 
                swapped = true; 
            } 
            curr1= curr1->next; 
        } 
        curr2 = curr1; 
    } 
    while (swapped); 
	stu* curr1first=first;
	stu* curr2first=NULL;
	stu* l=NULL;
	stu* p;
	stu* k;
	while(l!=first){
			p=first;
		while(p!=l){
			k=p;
			p=p->next;
		}
		InsertInSortLinkedList2(k);
		l=k;
	}






}

int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert At End: ";
		cout << "\nPress 2 to display: ";
		cout << "\nPress 3 to Delete from End: ";
        cout << "\nPress 4 to Reverse Display: ";
        cout << "\nPress 5 to Reverse Display Recursion: ";
		cout<<"\nPress 6 to Reverse: ";
		cout<<"\nPress 7 to Swap Two Nodes: ";
		cout<<"\nPress 8 to Sort in Sorted Linked List: ";
		cout<<"\nPress 9 to Swap All Nodes: ";
		cout<<"\nPress 10 to Merge: ";
		cout << "\nPress 11 to Insert In List 2: ";
		cout << "\nPress 12 to display List 2:";
		cout << "\nPress 13 to Delete From List 2: "<<endl;
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
			ReverseDisplay();	 
			break;
		case 5:
			ReverseDisplayRecursion(first);	 
			break;
		case 6:
			Reverse();
			break;
		case 7:
			SwapTwoNodes();
			break;
		case 8:
			InsertInSortLinkedList();
			break;
		case 9:
			swapAllNodes();
			break;
		case 10:
			Merge();
			break;
		case 11:
			InsertAtEndList2();
			break;
		case 12:
			displayList2();
			break;
		case 13:
			DeleteAtEndList2();
			break;
		default:
			cout << "Please Enter Correct Choice";
			break;
		}

	} while (option != 0);
}





