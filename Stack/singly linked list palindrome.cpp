#include<iostream>
using namespace std;
 struct Node
 {
   char ch;
	Node *next = NULL; 
 };
 Node* first=NULL;
class LinkedStackk
{
private:
Node* first;
public:
LinkedStackk()
{
first = NULL;
}
void push(char ch){
	Node *p=new Node;
    Node* curr=first;
	    p->ch=ch;
        p->next=first;
		   first = p;
}
char pop(){
    char ch;
    Node *p=first;
  if(first==NULL){
    cout<<"Stackk is Empty";}
    else{
        ch=p->ch;
        first=first->next;
    }return ch;
}
Node* top()
    {
        return first;
    }
bool isEmpty()
    {
        if(first==NULL)
        return true;
        else
            return false;
    }
};   
bool IsPalindrome(string str){
    LinkedStackk myStack;
    for (int i=0;i<str.length();i++){
        myStack.push(str[i]);
    }
    for (int i=0;i<str.length();i++){
    
        if(myStack.pop()!=str[i]){
            return false;
            break;
        }
    
    }return true;
}
   
int main()
{
    string h;
    cout << "Enter String for postfix evaluation" << endl;
    cin >> h;
    //if (isBalancedMulti(h))
    //{
    //cout << "Balanced";
    //}
    //else
    //cout << "Not Balanced";
       bool result=IsPalindrome(h);
       cout<<result;
       
}