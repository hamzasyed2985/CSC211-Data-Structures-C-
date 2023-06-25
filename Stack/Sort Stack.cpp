#include<iostream>
using namespace std;

class Stackk
{
public:
    int tos;
    int *q;

public:
    Stackk()
    {
        tos = -1;
        int size = 10;
        q = new int[size];
    }
    Stackk(int x)
    {
        tos = -1;
        q = new int[x];
    }
    void push(int x)
    {
        if (tos == 100000)
        {
            cout << "\nStackk overflow condition" << endl;
        }
        else
            q[++tos] = x;
    }
    int pop()
    {
        if (tos == -1)
        {
            cout << "\nStackk Underflow condition" << endl;
            return ' ';
        }
        else
            return q[tos--];
    }
    int top()
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

    void display()
    {
        for (int i = 0; i <= tos; i++)
        {
            cout << "\nElement at Index" << i << "is:" << q[i];
        }
    }
};

void sortStack(Stackk &s1)
{
    Stackk s2;
   
    s2.push(s1.pop());
    while (!s1.isEmpty())
    {
        int temp = s1.top();
        if (temp > s2.top())
        {
               s1.pop();
            s1.push(s2.pop());
            s1.push(temp);   
        }
        else
        {
         s2.push(s1.pop());
        }
    }
    while (!s2.isEmpty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
}

int main()
{
    Stackk obj(5);

    int option;
    do
    {
        cout << "\nPress 1 to push: ";
        cout << "\nPress 2 to pop: ";
        cout << "\nPress 3 to Display: ";
        cout << "\nPress 4 to sort: " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            int id;
            cout << "Enter the char" << endl;
            cin >> id;
            obj.push(id);
            break;
        case 2:
            obj.pop();;
            break;
        case 3:
            obj.display();
            break;
        case 4:
            sortStack(obj);
            break;

        default:
            cout << "Please Enter Correct Choice";
            break;
        }
    } while (option != 0);
}