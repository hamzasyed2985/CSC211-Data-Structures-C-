#include<iostream>
using namespace std;
 
class Stackk
{
private:
int top;
char array[10000];
public:
Stackk()
{
top=-1;
}
Stackk(char x)
    {
        top = -1;
        array[x];
    }
void push(char x){
        if (top == 100000)
        {
            cout << "\nStackk overflow condition" << endl;
        }
        else
            array[++top] = x;
}
char pop(){
   if(top==-1){
    cout << "\nStackk Underflow condition" << endl;
            return ' ';
   }else
        return array[top--];
}
char topp(){
    return array[top];}
bool isEmpty()
    {
       if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
};   
bool IsPalindrome(string str){
   Stackk obj;
    for (int i=0;i<str.length();i++){
        obj.push(str[i]);
    }
    for (int i=0;i<str.length();i++){
    
        if(obj.pop()!=str[i]){
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