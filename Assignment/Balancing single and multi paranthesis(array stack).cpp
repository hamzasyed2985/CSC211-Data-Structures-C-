#include <iostream>
using namespace std;
class Stackk
{
private:
    int tos;
    char values[10000];

public:
    Stackk()
    {
        tos = -1;
    }
    Stackk(char x)
    {
        tos = -1;
        values[x];
    }
    void push(char x)
    {
        if (tos == 100000)
        {
            cout << "\nStackk overflow condition" << endl;
        }
        else
            values[++tos] = x;
    }
    char pop()
    {
        if (tos == -1)
        {
            cout << "\nStackk Underflow condition" << endl;
            return ' ';
        }
        else
            return values[tos--];
    }
    char top()
    {
        return values[tos];
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
};
bool isBalanced(string str)
{
    Stackk myStackk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            char ch = str[i];
            myStackk.push(ch);
        }
        else if (str[i] == '}' && myStackk.top() == '{')
        {
            myStackk.pop();
        }
        else if (str[i] == '}' && myStackk.top() != '{')
        {
            return false;
        }
    }
    if (myStackk.isEmpty())
    {
        return true;
    }
    else
        return false;
}

bool isBalancedMulti(string str){
   Stackk myStackk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            char ch = str[i];
            myStackk.push(ch);
        }
    
        if (str[i]==')'||str[i]==']'||str[i]=='}'){

        char top=myStackk.top();
       
        if((str[i]==')'&& top=='(') || (str[i]==']'&& top=='[') || (str[i]=='}'&& top=='{'))
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


int main()
{
    string h;
    cout << "Enter String for bracket checker" << endl;
    cin >> h;
    Stackk myStackk;
    if (isBalancedMulti(h))
    {
        cout << "Balanced";
    }
    else
        cout << "Not Balanced";
}