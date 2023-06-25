#include<iostream>
using namespace std;
 struct Node
 {
    string ch;
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
void push(string ch){
	Node *p=new Node;
    Node* curr=first;
	    p->ch=ch;
        p->next=first;
		   first = p;
}
string pop(){
    string ch;
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

string PostfixToInfix(string str){
    LinkedStackk myStackk;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
if ((str[i] >= 'a' && str[i] <= 'z'))
           {
            string op(1, str[i]);
            myStackk.push(op);
           }
    else {
           string a=myStackk.top()->ch;
           myStackk.pop();
           string b=myStackk.top()->ch;
           myStackk.pop();
           myStackk.push("( "+b+str[i]+a+" )");
          
        }
        }
       return myStackk.top()->ch;  
    }
int main()
{
    string h;
    cout << "Enter String for postfix to infix: " << endl;
    cin >> h;
    //if (isBalancedMulti(h))
    //{
    //cout << "Balanced";
    //}
    //else
    //cout << "Not Balanced";
       string result=PostfixToInfix(h);
       cout<<result;
}
