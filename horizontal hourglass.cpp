#include<iostream>
using namespace std;
int main(){
	int n=6,i,j;
    for( i=0;i<n;i++){
    	cout<<"\n";	
	for( j=0;j<i;j++){
		cout<<"* ";	}
	for( j=n-1;j>i;j--){
		cout<<"  ";	}		
	for( j=i;j<n-1;j++){
		cout<<"  ";	}
	for( j=0;j<i;j++){
		cout<<"* ";	}
    }
    for( i=n-1;i>0;i--){
        if (i>0){
    	cout<<"\n";}	
	for( j=0;j<i-1;j++){
		cout<<"* ";	}
	for( j=n-1;j>i-2;j--){
		cout<<"  ";	}		
	for( j=i;j<n-1;j++){
		cout<<"  ";	}
	for( j=0;j<i-1;j++){
		cout<<"* ";	}
    
 }