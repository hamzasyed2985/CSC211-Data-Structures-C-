#include <iostream>
using namespace std;

struct stu
{
	int id;
	stu *next = NULL;
	stu *prev = NULL;
};
stu *first2=NULL;
stu *first = NULL;


void display(){
    stu *p;
	p=first;
	
	while(p!=NULL)
	{
		cout<<"ID is: "<<p->id<<endl;
		p=p->next;
	}
}

void displayList2(){
    stu *p;
	p=first2;
	
	while(p!=NULL)
	{
		cout<<"ID is: "<<p->id<<endl;
		p=p->next;
	}
}

void InsertAtEnd(){
	stu* curr=first;
	stu *p;
	p = new stu;
	cout << "Enter Your ID: ";
	cin >> p->id;
		   if (first == NULL){
           p->prev=NULL;
		   first = p;
          }
	else
	{	while (curr->next!=NULL)
	{
		curr=curr->next;
	}
		curr->next = p;
        p->prev=curr;
		p->next=NULL;
    }
}

void InsertAtEndList2(){
	stu *p;
	p = new stu;
	stu *curr;
	curr=first2;
	cout << "Enter Your ID: ";
	cin >> p->id;

		   if (first2 == NULL)
		   first2 = p;
	else
	{
		while(curr->next!=NULL){
			curr=curr->next; }
			
		curr->next = p;
        p->prev=curr;
		p->next=NULL;}
} 

void DeleteAtEnd(){
	stu *curr;
	curr=first;
	if (first == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first->next==NULL)
	{
		first=NULL;
	}
	else
	{
		while(curr->next->next!=NULL)
		{
			curr=curr->next;
		}	
		curr->next=NULL;
	}
}

void DeleteAtEndList2(){
	stu *p;
	p=first2;
	if (first2 == NULL)
	{
		cout<<"Linked List is Empty: ";
	}
	else if(first2->next==NULL)
	{
		first2=NULL;
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

void ReverseDisplay()
{
    stu *p=first;
    stu *l;
    stu *k;
    l=NULL;
	while(p->next!=NULL){
		p=p->next;
	}l=p;
	while(l!=NULL){
		cout<<l->id<<endl;
		l=l->prev;
	}

}

void ReverseDisplayRecursion(stu *p)
{
	if(p!=NULL)
    {
		ReverseDisplayRecursion(p->next);
	cout<<"ID is: "<<p->id<<endl;
	}
}

void Reverse(){
	stu *curr;
	stu *next=NULL;
	stu *temp;
	curr=first;
	while(curr!=NULL){
		temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
	}cout<<temp->prev->id;
	first=temp->prev;	
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
	cout << "Enter Your ID: ";
	cin >>x;
	p->id=x;
	
	if (first==NULL){
		first=p;
	}
	else if((p->id)<(first->id)){
			p->next=first;
			first->prev=p;
			p->prev=NULL;
			first=p;
	}
	else{
		curr1=first;
	while (curr1->next != NULL && curr1->next->id <= p->id) {
        curr1 = curr1->next;
    }
    p->next = curr1->next;
    p->prev = curr1;
    curr1->next = p;
    if (p->next != NULL) {
        p->next->prev = p;
    }
	}
}
void InsertInSortLinkedList2(stu* p){
	stu *curr1;
	stu *prev1=first2;
	curr1=first2;
	if (first2==NULL){
		first2=p;
	}
	else if((p->id)<(first2->id)){
			p->next=curr1;
			first2=p;
}/*else if((p->id)>(last2->id)) {
		last2->next=p;
		last2=p;
}*/
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
		
		q->id=p->id;
		
		p->id=TempId;
		
}

void swapAllNodes(){
	stu *curr1=first;
	//stu *curr2=last;
	stu *prev2=NULL;
	stu* current2=first;
	stu* l=NULL;
	
	/*while(curr1!=curr2 && curr2->next!=curr1){

		swapValues(curr1,curr2);
		current2=first;
		while(current2->next!=l){
			prev2=current2;
			current2=current2->next;
		}l=current2;	
	
	curr1=curr1->next;
	curr2=prev2;
	}	*/
			
}

void Sort_by_Nodes_FORLOOP(){
	stu *p,*s,*k;
	for(p=first;p!=NULL;p=p->next){
		s=p;
		for(k=p;k!=NULL;k=k->next){
			if(k->id<s->id){s=k;}
		}
			SwapTwoNodes(/*p,/s*/);
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





