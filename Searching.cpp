#include<iostream>
#include<cmath>
using namespace std;
int Lineararray[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
 int array[5][5]= {{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};
int rows = sizeof(array) / sizeof(array[0]);
int cols = sizeof(array[0]) / sizeof(array[0][0]); 

void Linear(){

    cout<<"Enter Number to Search";
    int num;
    int found=0;
    int indexcol;
    int indexrow;
    cin>>num;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(num==array[i][j]){
                found=1;
                indexrow=i;
                indexcol=j;
            }
    }
    }
    if(found==1){
        cout<<"Value is found at row "<<indexrow<<" and Column "<<indexcol;
    }else{
        cout<<"Value not found";
    }
    
 }

void Binary(){
    int size=sizeof(Lineararray)/sizeof(Lineararray[0]);
    cout<<"Enter Number to Search";
    int num;
    cin>>num;
    int first=0;
    int last=size;
    int found=0;
    int middle=floor((first+last)/2);
    while(found!=1 && first<=last){
        if(num==Lineararray[middle]){
            found=1;
        }
        else if(num<Lineararray[middle]){
            last=middle-1;

        }
        else if(num>Lineararray[middle]){
            first=middle+1;
        }
        middle=floor((first+last)/2);
    }
    if (found==1){
        cout<<"Found";
    }
    else{
        cout<<"Not found";
    }
}

void Binary2(){
cout<<rows;
cout<<cols;
    cout<<"Enter Number to Search";
    int num;
    cin>>num;
    int first=0;
    int indexrow;
    int indexcol;
    int last=rows*cols -1;
    int found=0;
    int middle=floor((rows+cols)/2);
    while(found!=1 && first<=last){
        int row = middle / cols;
        int column = middle % cols;
        cout<<"row is"<< row;
        cout<<"col is "<<column;
        int element = array[row][column];
        if(num==array[row][column]){
            found=1;
            indexrow=row;
             indexcol=column;
        }
        else if(num<array[row][column]){
            last=middle-1;

        }
        else if(num>array[row][column]){
            first=middle+1;
        }
        middle=floor((first+last)/2);
    }
    if (found==1){
         cout<<"Value is found at row "<<indexrow<<" and Column "<<indexcol;
    }
    else{
        cout<<"Not found";
    }
}

int main(){
   

//Linear();
//Binary();  
Binary2();

 }
