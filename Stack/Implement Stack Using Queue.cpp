#include<iostream>
using namespace std;

class Que{
    public:
    int size;
    int front;
    int rear;
    int *q;

Que() 
{
size = 10; 
q = new int[size];
front=-1; 
rear=-1;
}
Que(int z) 
{
size = z; 
q = new int[size];
front=-1;
rear=-1;
}
bool is_empty()
{
if (rear==-1){
return true;}
else
return false;
}
void Shift_left(int si,int li){
for(int i=si;i<li;i++){ 
        q[i]=q[i+1];
    }
}
bool is_full()
{
if (rear==size-1){
return true;}
else
return false ;
}
void Enque(int x){
    
    if(is_full()){
        cout<<"Que is full";
    }
    else {
     if(is_empty()){
        front=rear=0;
    }
    else{
        rear++;
        }
    q[rear]=x;
    }
}
int Deque(){
    int x;
    if (is_empty())
{
cout<<"Que is already empty";

}
else
{
x= q[front];
if(front==rear)
{
front=rear=-1;
}
else{
    Shift_left(front,rear);
    rear--;
    }
}
return x;
}
void display()
{
if(is_empty())
{
cout<<"\n Queue is empty....";
}
else{
for(int i=front; i<=rear; i++)
{
cout<<"\n Value at index "<<i<< " is: "<<q[i];
}
}}
};
Que q1;
Que q2;
void push(int x){
q2.Enque(x);
while(!q1.is_empty()){
    q2.Enque(q1.Deque());
}

while(!q2.is_empty()){
    q1.Enque(q2.Deque());
}
}
void pop(){
    
    q1.Deque();
}
int main(){
    
        Que obj(5);
	
	int option;
	do
	{
		cout << "\nPress 1 to Push: ";
		cout << "\nPress 2 to Pop: ";
		cout << "\nPress 3 to Display: "<< endl;
		cin >> option;
		switch (option)
		{
		case 1:
        int id;
        cout<<"Enter the number";
        cin>>id;
		push(id);
			break;
		case 2:
		pop();
			break;
		case 3:
		q1.display();
			break;
	
	
	
		default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}
