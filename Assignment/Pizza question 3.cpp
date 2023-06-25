#include<iostream>
using namespace std;
struct Order {
    int orderNumber;
    int age;
};
class QuePizzaHut{
    public:
    int size;
    int front;
    int rear;
    Order *q;

QuePizzaHut() 
{
size = 10; 
Order q[size];
front=-1; 
rear=-1;
}
QuePizzaHut(int z) 
{
size = z; 
Order q[size];
front=-1;
rear=-1;
}
void shift_right (int a, int b) {
for(int i = b; i >= a; --i ) {
    q[i + 1] = q[i];
    if(a == front) front++;
    if(b == rear) rear++;
}
}
void shift_left (int a, int b) {
for(int i = a; i <= b; ++i ) {
  q[i - 1] = q[i];
  if(a == front) front--;
  if(b == rear) rear--;
}
}

bool is_full()
{
if (front==0 && rear==size-1){
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
void Add_Order_Front(int orderId,int age){
    
    if(is_full()){
        cout<<"Order limit reached! ";
    }
    else if(front==-1){
        front=rear=0;
        q[front].orderNumber=orderId;
        q[front].age=age;
    }
    else
    {
     if(front > 0) {
        --front;
      q[front].orderNumber =orderId ;
      q[front].age=age;
      }
      else {
        shift_right(front, rear);
        --front;
        q[front].orderNumber = orderId;
        q[front].age=age;
      }
    }
   
}
void Add_Order_Rear(int orderId,int age){
    
    if(is_full()){
        cout<<"Order limit reached! ";
    }
    else if(front==-1){
        front=rear=0;
        q[rear].orderNumber=orderId;
        q[rear].age=age;
    }
    else{
        if(rear<size-1){
            rear++;
             q[rear].orderNumber=orderId;
        q[rear].age=age;
        }
        else 
        {   shift_left(front, rear);
            rear++;
            q[rear].orderNumber=orderId;
            q[rear].age=age;
            } 
    }

}
void Serve_order_Front(){
int orderId= q[front].orderNumber;
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
    front++;
}cout << "Order# " << orderId << " served successfully!" << endl;
}
}
void Serve_order_Rear(){
int orderId= q[front].orderNumber;
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
    rear--;
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
    for (int i = front; i <= rear; i++) {
        cout <<"\nOrder Number is: "<< q[i].orderNumber;
        cout <<"\nAge is: "<< q[i].age;
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
		cout << "\nPress 1 to Place Order From Front: ";
        cout << "\nPress 2 to Place Order From Rear: ";
		cout << "\nPress 3 to Serve Order From Front: ";
		cout << "\nPress 4 to Serve Order From Rear: ";
        cout << "\nPress 5 to Display The Orders Queue: ";
        cout << "\nPress 0 to Exit The System: "<<endl;
		cin >> option;
		switch (option)
		{
		case 1:
        int id,age;
        cout<<"Enter Order Id: ";
        cin>>id;
        cout<<"Enter Age: ";
        cin>>age;
		obj.Add_Order_Front(id,age);
			break;
        case 2:
        cout<<"Enter Order Id: ";
        cin>>id;
        cout<<"Enter Age: ";
        cin>>age;
		obj.Add_Order_Rear(id,age);
			break;
		case 3:
		obj.Serve_order_Front();
			break;
        case 4:
		obj.Serve_order_Rear();
			break;
		case 5:
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
