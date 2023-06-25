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



bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postfixToInfix(const string& postfix) {
    LinkedStackk myStackk;

    for (char c : postfix) {
        if (isOperator(c)) {
            string operand2 = myStackk.pop();
            string operand1 = myStackk.pop();

            string infix = '(' + operand1 + ' ' + c + ' ' + operand2 + ')';
            myStackk.push(infix);
        } else {
            string operand = string(1, c);
            myStackk.push(operand);
        }
    }

    return myStackk.pop();
}

int main() {
    string postfix = "ab+c*";
    string infix = postfixToInfix(postfix);

    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << infix << endl;

    return 0;
}