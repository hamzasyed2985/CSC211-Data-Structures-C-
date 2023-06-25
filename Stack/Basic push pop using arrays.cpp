#include<iostream>
using namespace std;
int arr[5],length=5;
int top=-1;
void push(){
    int ele;
    cout<<"Enter the lement you want ot push"<<endl;
    cin>>ele;
    if(top==length-1){cout<<"Arr is FUll! ";}
    else {
    if(top==-1){
        top=0;
        arr[top]=ele;
    }
    else if(top<length-1){
        arr[++top]=ele;
    }
}
}
void display(){
    for (int i=0;i<=top;i++){
        cout<<"\nElement at Index"<<i<<"is:"<<arr[i];
    }
    }
void pop(){
    if(top==-1){
        cout<<"Stack is empty";
    }else{
        top--;
    }
}

int main(){
     int option;
    
                
do{
    cout<<"\nPress 1 to PUSH: ";
    cout<<"\nPress 2 To Display: ";
    cout<<"\nPress 3 to POP: "<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
        push();
        break;
    case 2:
        display();
        break;
    case 3:
        pop();
        break; 
    default:
    cout<<"Please Enter Correct Choice";
        break;
    }
    }while(option!=0);

}