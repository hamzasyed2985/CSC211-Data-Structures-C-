#include<iostream>
using namespace std;
 
class QuePizzaHut{
    public:
    int size;
    int front;
    int rear;
    int *q;

QuePizzaHut() 
{
size = 10; 
q = new int[size];
front=-1; 
rear=-1;
}
QuePizzaHut(int z) 
{
size = z; 
q = new int[size];
front=-1;
rear=-1;
}
bool is_full()
{
if (front==0 && rear==size-1){
return true;}
if(front==rear+1){
return true;}
return false;
}
bool is_empty()
{
if (front==-1){
return true;}
else
return false;
}
void Add_Order(int orderId){
    
    if(is_full()){
        cout<<"Order limit reached! ";
    }
    else {
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;  
        q[rear]=orderId;
      cout << "Order " << orderId << " placed successfully!" << endl;
    }
}

void Serve_order(){
int orderId= q[front];
if (is_empty())
{
cout<<"None To Serve! ";
}
else
{
if(front==rear)
{
front=rear=-1;
}
else{
   front=(front+1)%size; 
}cout << "Order# " << orderId << " served successfully!" << endl;
}

}
void display()
{
if (front == -1)
    {
        cout<<"\nNo Orders Placed!";
        return;
    }
    cout<<"\nOrders Queue is: ";
    for (int i = front; i != rear; i =(i+1)%size) {
        cout <<"\nOrder Number is: "<< q[i];
    }
     cout <<"\nOrder Number is: "<< q[rear];
    }
}
};
int main(){
    int orders;
    cout << "Enter maximum number of orders that Pizza Hut can accept: "<<endl;
    cin>>orders;
        QuePizzaHut obj(orders);
	
	int option;
	do
	{
		cout << "\nPress 1 to Place Order: ";
		cout << "\nPress 2 to Serve The Next Order: ";
		cout << "\nPress 3 to Display The Orders Queue: ";
        cout << "\nPress 0 to Exit The System: "<<endl;
		cin >> option;
		switch (option)
		{
		case 1:
        int id;
        cout<<"Enter Order Id: ";
        cin>>id;
		obj.Add_Order(id);
			break;
		case 2:
		obj.Serve_order();
			break;
		case 3:
		obj.display();
			break;
        case 0:
            cout<<"Thanks for using Pizza Hut service.";
			break;
		default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}
