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
void Shift_leftt(int si,int li){
int z=si;
    while(z!=li){
        q[z]=q[z+1];
        z++;
    }
    front++;
}
void Shift_left(int si,int li){

for(int i=si;i<li;i++){ 
        q[i]=q[i+1];
    }
}
void shift_right(int si,int li){
    for(int i=li;i>si;i--){
        q[i]=q[i-1];
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
void Add_Order(int orderId,int age){
    
    if(is_full()){
        cout<<"Order limit reached! ";
    }
    else if(front==-1){
        front=rear=0;
        q[rear].orderNumber=orderId;
        q[rear].age=age;
    }
    else {
        int i=rear;
        cout << i;
        while(i!= front -1 && !(q[i].age>=age))  {
            i--;
        }      
        cout <<  "\n i :"<< i << endl;
        if(front == -1){

            // case handled when have to be inserted at start and their is space at end
            front = rear = 0;
            q[rear].orderNumber=orderId;
            q[rear].age=age;
        }
        if(i<front && front==0){

            // case handled when have to be inserted at start and their is space at end
            shift_right(front,rear+1);
            q[front].orderNumber=orderId;
            q[front].age=age;
            rear++;
        }
        else if(i == rear && rear != size - 1){
            
            rear++;
            q[rear].orderNumber=orderId;
            q[rear].age=age;

        }
        else if(q[i].age>=age && front==0){
            if(i!=rear){
            shift_right(i+1,rear+1);}
            q[i + 1].orderNumber=orderId;
            q[i + 1].age=age;
            rear++;
            cout << "shift right" << endl;
        }
        else if(front!=0 && i<front){
            front--;
            q[front].orderNumber=orderId;
            q[front].age=age;
            

        }
        else if(front!=0 && q[i].age>=age){
            Shift_left(front-1,i);
            q[i].orderNumber=orderId;
            q[i].age=age;
            front--;
            cout << "shift left" << endl;
        }
    }
        cout << "front "<< front  << endl;
        cout << "rear "<< rear  << endl;
      cout << "Order " << orderId << " placed successfully!" << endl;
}

void Serve_order(){
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
		cout << "\nPress 1 to Place Order: ";
		cout << "\nPress 2 to Serve The Next Order: ";
		cout << "\nPress 3 to Display The Orders Queue: ";
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
        
		obj.Add_Order(id,age);
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
