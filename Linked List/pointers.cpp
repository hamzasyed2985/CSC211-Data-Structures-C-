#include <iostream>
using namespace std;
int swaper(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main() {
//    int arr[]={1,2,3,4,5};
//    cout<<*(arr+4)<<endl;
//    int x=2,y=4;
//    int* XP=&x;
//    int* YP=&y;
//    cout<<*XP<<endl;
//    cout<<*YP<<endl;
//    cout<<XP<<endl;
//    cout<<YP<<endl;
//    *XP=*YP;
//    cout<<*XP<<endl;
//    char hello='h';
//    cout<<&hello<<endl;
//    XP=YP;
//    cout<<XP<<endl;
//    cout<<YP<<endl;
    
    
    
    
    int a=1, b=5;
    swaper(&a,&b);
    cout<<a<<endl<<b<<endl;
    return 0;    
}