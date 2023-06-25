#include<iostream>
using namespace std;
 struct Node
 {
    int ch;
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
void push(int num){
	Node *p=new Node;
    Node* curr=first;
	    p->ch=num;
        p->next=first;
		   first = p;
}
int pop(){
    int ch;
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
int InfixtoPostfixEvaluation(string str)
{
    LinkedStackk myStackk;
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            char ch = str[i];
            myStackk.push(ch - '0');
        }
        else
        {
            char ch = str[i];
            result = 0;
            int a = myStackk.pop();
            
            int b = myStackk.pop();
         
            switch (ch)
            {
            case '+':
                result = b + a;
                myStackk.push(result);
                break;

            case '-':
                result = b - a;
                myStackk.push(result);
                break;

            case '*':
                result = b * a;
                myStackk.push(result);
                break;

            case '/':
                if (a == 0)
                {
                    cout << "Error:\n";
                    return 1;
                }
                result = b / a;
                myStackk.push(result);
                break;

            default:
                cout << "Invalid operator\n";
                return 1;
            }
        }
    }
    return myStackk.pop();
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
       int result=InfixtoPostfixEvaluation(h);
       cout<<result;
}