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
bool isBalancedMulti(string str){
   LinkedStackk myStackk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            char ch = str[i];
            myStackk.push(ch);
        }
    }
    for (int j = 0; j < str.length(); j++)
    {   
        if (str[j]==')'||str[j]==']'||str[j]=='}'){

        char top=myStackk.top()->ch;
        if((str[j]==')'&& top=='(') || (str[j]==']'&& top=='[') || (str[j]=='}'&& top=='{'))
            {
                myStackk.pop();
            }
        else{return false;}
    }
    }


    if (myStackk.isEmpty())
    {
        return true;
    }
    else
        return false; 
}

int precedence(char a){
    if(a=='*'||a=='/' ){
        return 3;
    }
    else if(a=='+'||a=='-' ){
        return 2;
    }else return -1;
}
string InfixtoPostfix(string str){
    LinkedStackk myStackk;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')|| (str[i] >= '0' && str[i] <= '9'))
           { result += str[i];}
        else if(str[i]=='('){
            char ch = str[i];
            myStackk.push(ch);
        }
       else  if(str[i]==')'){
            while (myStackk.top()->ch!='(')
            {   
                result+=myStackk.pop();
            }myStackk.pop();
        }
        else{ char ch=str[i];
        if(myStackk.isEmpty()||(precedence(ch)>precedence(myStackk.top()->ch))){
            myStackk.push(ch);
        }
        else {
        while(!myStackk.isEmpty()&&(precedence(myStackk.top()->ch)>=precedence(ch)))
        {   
            result+=myStackk.pop();
        }
            myStackk.push(ch);
        }}
    }
    while(!myStackk.isEmpty()){
        
       result+= myStackk.pop();
    }
    return result;
        
    }
    


int main()
{
    string h;
    cout << "Enter String for bracket checker" << endl;
    cin >> h;
    //if (isBalancedMulti(h))
    //{
    //cout << "Balanced";
    //}
    //else
    //cout << "Not Balanced";
       string result=InfixtoPostfix(h);
       cout<<result;
}
