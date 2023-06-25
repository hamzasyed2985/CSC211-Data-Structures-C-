#include<iostream>
using namespace std;
int si= -1,li=-1, arr[6], length = 6;
void shift_right (int a, int b, int arr[]) {
for(int i = b; i >= a; --i ) {
    arr[i + 1] = arr[i];
    if(a == si) si++;
    if(b == li) li++;
}
}
void shift_left (int a, int b) {
for(int i = a; i <= b; ++i ) {
  arr[i - 1] = arr[i];
  if(a == si) si--;
  if(b == li) li--;
}
}
void InsertAtEnd(){
    int key;
    cout<<"\nEnter Element to Insert AT END : ";
    cin>>key;
    if(si==0 && li==length - 1){cout<<"Arr is FUll! ";}
    else 
        {
          if(li==-1)
        {
            si = 0,li=0;
            arr[li]=key;
            }
        else if(li < length - 1){
            li++;
            arr[li]=key;

            
        }  
        else 
        {   shift_left(si, li);
            li++;
            arr[li]=key;
            } 
            cout << endl << key << endl;
        }
}               
void InsertAtStart(){
    int key;
    cout<<"\nEnter The Element: ";
    cin>>key;
    if (li == (length - 1) && si == 0) {
         cout << "\n Arr is full\n";}
    // arr is empty
    else {
      if (li == -1) {
          si = li = 0;
          arr[si] = key;
        }
      else   if(si > 0) {
        --si;
      arr[si] = key;
      }
      else {
        shift_right(si, li, arr);
        --si;
        arr[si] = key;
      }
      
    }                 
}
void InsertAfterSpecific(int arr[]){
    int key,i,indexValue,found=0;
    cout<<"\nEnter Value at which after you want to Insert : ";
    cin>>indexValue;
    cout<<"\nEnter value that you want to Insert : ";
    cin>>key;
    if(si==0 && li==length-1){cout<<"Array is FUll! ";}
    else 
        if(li==-1)
        {
            si=li=0;
            arr[li]=key;
        }
        else
        {  
            for(int i=0;i<length;i++)
            {
                if(arr[i]==indexValue && li!=(i+1))
                {
                    
                    shift_right(i,li,arr);
                    arr[i+1]=key;
                    found=1;
                }
                
                
            }   
            if(found=0)
            {    
                cout<<"Index Value doesn't match! "<<endl;
            }
                
                
            
        }               
}
void DeleteAtEnd(){
      
    
        if(si,li==-1)
        {
            cout<<"arr Is Empty!";
        }        
        else 
        {
            cout<<"Element At index "<<li<<" Deleted";
            li--;
        }
        
}
void DeleteFromStart(){
        if(si,li==-1)
        {
            cout<<"arr Is Empty!";
        }        
        else 
        {   
            cout<<"Element At index "<<si<<" Deleted";
            si++;
            
            }
}
void DeleteSpecific(){
     int Index;
     if(si,li==-1)
        {
            cout<<"Array Is Empty!";
        }        
        else 
        {   
            cout<<"Enter the Index You Want to Delete: ";
            cin>>Index;
            cout<<"Element At index "<<Index<<" Deleted";
            if(Index<=length/2)
            {
                shift_right(si,Index-1,arr);
            }
            if(Index>length/2)
            {
                shift_left(Index+1,li);
            }

            
        }
            
}
void display(){
    for (int i=si;i<=li;i++){
        cout<<"\nElement at Index"<<i<<"is:"<<arr[i];
    }
}


int main(){
    int option;
    
                
do{
    cout<<"\nPress 1 to Insert At Start: ";
    cout<<"\nPress 2 to Insert At End: ";
    cout<<"\nPress 3 to Insert After Specific: ";
    cout<<"\nPress 4 to display: ";
    cout<<"\nPress 5 to Delete from End: ";
    cout<<"\nPress 6 to Delete from Start: ";
    cout<<"\nPress 7 to Delete Specific: ";
    cout<<"\nPress 0 to Exit"<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
        InsertAtStart();
        break;
    case 2:
        InsertAtEnd();
        break;
    case 3:
        InsertAfterSpecific(arr);
        // InsertAfterSpecific();
        break;
    case 4:
        display();
        break;
    case 5:
        DeleteAtEnd();
        break;
    case 6:
        DeleteFromStart();
        break;
    case 7:
        DeleteSpecific();
    case 0:

        break;
    default:
    cout<<"Please Enter Correct Choice";
        break;
    }
    }while(option!=0);

}



