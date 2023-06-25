#include<iostream>
using namespace std;
 
class Stackk
{
public:
    int tos;
    char *q;

public:
    Stackk()
    {
        tos = -1;
       int size=10;
       q = new char[size];
    }
    Stackk(int x)
    {
        tos = -1;
       q = new char[x];
    }
    void push(char x)
    {
        if (tos == 100000)
        {
            cout << "\nStackk overflow condition" << endl;
        }
        else
            q[++tos] = x;
    }
    char pop()
    {
        if (tos == -1)
        {
            cout << "\nStackk Underflow condition" << endl;
            return ' ';
        }
        else
            return q[tos--];
    }
    char top()
    {
        return q[tos];
    }
    bool isEmpty()
    {
        if (tos == -1)
        {
            return true;
        }
        else
            return false;
    }

void display(){
    for (int i=0;i<=tos;i++){
        cout<<"\nElement at Index"<<i<<"is:"<<q[i];
    }
    }
};   

    Stackk p1;
    Stackk p2;
void Enque(char x){
    p1.push(x);
}
void Deque(){
while(!p1.isEmpty()){
    p2.push(p1.top());
    p1.pop();
}
char y=p2.pop();
while(!p2.isEmpty()){
    p1.push(p2.top());
    p2.pop();
}
}
   
int main()
{
  Stackk obj(5);
	
	int option;
	do
	{
		cout << "\nPress 1 to Enque: ";
		cout << "\nPress 2 to Deque: ";
		cout << "\nPress 3 to Display: "<< endl;
		cin >> option;
		switch (option)
		{
		case 1:
        char id;
        cout<<"Enter the char"<<endl;
        cin>>id;
		Enque(id);
			break;
		case 2:
		Deque();
			break;
		case 3:
		p1.display();
			break;
	
	
	
		default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
       
}