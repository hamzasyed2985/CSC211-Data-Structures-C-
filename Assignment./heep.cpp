#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Tree
{
    string Make;
    string Model;
    int year;
    int horsepower;
    int Cylinders;
    int height;
    Tree* right = NULL;
    Tree* left = NULL;

};
void swapp(Tree* &a, Tree* &b)
{
  Tree* temp=new Tree; 
  temp=b; 
  b = a;
  a = temp;
}

void heapify(Tree* arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->horsepower > arr[largest]->horsepower)
        largest = left;

    if (right < n && arr[right]->horsepower > arr[largest]->horsepower)
        largest = right;

    if (largest != i) {
        swapp(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(Tree* arr[], int n)
{
    int startIndex = (n / 2) - 1;
    for (int i = startIndex; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(Tree* arr[], int n)
{
   cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i]->Make << " , " << arr[i]->Model << " , " << arr[i]->year << " , "<< arr[i]->horsepower << " , " << arr[i]->Cylinders << endl;
    }
}

void deleteNode(Tree* arr[], int& n, int horsepower)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i]->horsepower == horsepower)
            break;
    }

    if (i == n)
    {
        cout << "Node not found" << endl;
        return;
    }

    delete arr[i];
    arr[i] = arr[n - 1];
    n--;

    buildHeap(arr, n);
}

void insert(Tree* ele, Tree* heap[], int& last, int HeapSize) {
    if (last == HeapSize - 1) {
        cout << "No space in the heap." << endl;
    } else {
        heap[++last] = ele; 
        int tLast = last;
        bool adjusted = false;

        while (!adjusted && tLast != 0) {
            int p;
            if (tLast % 2 != 0) { 
                p = ceil((tLast - 1) / 2);
            } else { 
                p = (tLast - 2) / 2;
            }

            if (heap[tLast]->horsepower > heap[p]->horsepower) { 
                swapp(heap[tLast], heap[p]); 
                tLast = p; 
            } else {
                adjusted = true;
            }
        }
    }
}


Tree* addNode(string Make, string Model, int year, int horsepower, int cylinders) {
    Tree* new_node = new Tree;
    new_node->Make = Make;
    new_node->Model = Model;
    new_node->year = year;
    new_node->horsepower = horsepower;
    new_node->Cylinders = cylinders;
    new_node->right = NULL;
    new_node->left = NULL;

    return new_node;
}
Tree* TdeleteFromHeap(Tree* heap[], int& last) {
    if (last == -1) {
        cout << "Empty heap." << endl;
        return nullptr;
    } else {
        Tree* value = heap[0]; // Remove root value

        heap[0] = heap[last]; 
        heap[last]= 0; // Remove last inserted leaf
        last--;

        int first = 0;
        int largest = 1;

        while (largest <= last) {
            if (largest < last && heap[largest] < heap[largest + 1]) {
                largest++; // Right child is larger, move to the right child
            }

            if (heap[first] < heap[largest]) {
                swap(heap[first], heap[largest]);
                first = largest;
                largest = 2 * first + 1;
            } else {
                largest = last + 1; 
            }
        }
        return value; // Return the removed value
    }
}
int main()
{
    int i = 0;
    Tree* arr[10];

    ifstream fin;
    fin.open("cars1.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;

    while (!fin.eof()) {
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ',')) {
            lineData.push_back(word);
        }

        if (lines != 0) {
            stringstream s1(lineData[2]);
            int year;
            s1 >> year;
            stringstream s2(lineData[3]);
            int horsepower;
            s2 >> horsepower;
            stringstream s3(lineData[4]);
            int cylinders;
            s3 >> cylinders;

            Tree* returned = addNode(lineData[0], lineData[1], year, horsepower, cylinders);
            arr[i] = returned;
            i++;
        }

        lineData.clear();
        lines++;
    }
    for (int i=0;i<50;i++){
        insert(arr[i],arr,i,50);
    }
    
   
    cout << endl;
 int choice = 0;
    do
    {
        cout<<"press 1 for Heap insertion "<<endl;
        cout<<"press 2 for HEap deletion "<<endl;
        cout<<"press 3 for Print "<<endl;
        cout<< "Select an option and 0 to exit:";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                TdeleteFromHeap(arr,i);
                break;
            }
            case 2 :
            {
              deleteNode(arr, i, 819);
              break;  
            }
            case 3 :
            {
               printArray(arr, i);
                break;
            }
            
        default:
            {
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    while(choice!=0);
    return 0;

}