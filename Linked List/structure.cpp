#include <iostream>
using namespace std;

struct stu
{
	int id;
	float marks;
};
stu s[5];	
int main() 
{
    stu stuObj;
    for (int i=0;i<5;i++)
	{
    	int id;
    	float marks;
    	cout<<"Student Number"<<i<<endl;
    	cout<<"Enter Your Id"<<endl;
    	cin>>stuObj.id;
		cout<<"Enter Your Marks"<<endl;
    	cin>>stuObj.marks;
	}
    return 0;    
}