#include<iostream>
#include<cmath>
using namespace std;
int Lineararray[25] = {56, 12, 85, 99, 8};
 int array[5][5]={
        {9, 3, 5, 1, 2},
        {7, 4, 8, 6, 0},
        {2, 6, 3, 9, 1},
        {5, 7, 0, 4, 8},
        {1, 2, 6, 3, 9}
    };

int rows = sizeof(array) / sizeof(array[0]);
int cols = sizeof(array[0]) / sizeof(array[0][0]); 

void swapp(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubble2d(){

    for (int i=0;i<rows;i++){
      for (int j=0;j<cols;j++){
        for(int k=0;k<cols-j-1;k++){
        if (array[i][k] > array[i][k + 1])
        {
          swapp(array[i][k], array[i][k + 1]);
        }
        }
      }
    }
for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      cout << array[i][j] << " ";
    cout << endl;
  }
}
void bubbleLinear(){
    
    for (int i=0;i<25;i++){
      for (int j=0;j<25-i;j++){
        if(Lineararray[j]>Lineararray[j+1]){
                swapp(Lineararray[j],Lineararray[j+1]);
        }
      }
    }
for (int i = 0; i < rows; i++)
  {

      cout << Lineararray[i] << " ";
    cout << endl;
  }
}

void Selection(){
   int comparisons = 0;
    int swaps = 0;

    int smallest = 0;
    for (int i = 0; i < 5; i++) {
        smallest = i;
        for (int j = i + 1; j < 5; j++) {
            comparisons++;  // Increment comparison counter
            if (Lineararray[j] < Lineararray[i]) {
                smallest = Lineararray[j];
                if (smallest != i) {
                    swaps++;  // Increment swap counter
                    swapp(Lineararray[i], Lineararray[j]);
                }
            }
        }
     cout << "Number of comparisons: " << comparisons << endl;
    }
    cout << "Number of swaps: " << swaps << endl;
    for (int i = 0; i < 25; i++)
  {
      cout << Lineararray[i] << " ";
   
  }

}
void Selection2d() {
    int smallest = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            smallest = j;
            for (int k = j + 1; k < cols; k++) {
                if (array[i][k] < array[i][smallest]) {
                    smallest = k;
                }
            }
            if (smallest != j) {
                int temp = array[i][j];
                array[i][j] = array[i][smallest];
                array[i][smallest] = temp;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

void InsertionLinear() {
    int shifts = 0;
    int comparisons = 0;

    int i, j, k, temp;
    for (i = 1; i < 5; i++) {
        temp = Lineararray[i];
        j = i;
        while ((j > 0) && (temp < Lineararray[j - 1])) {
            Lineararray[j] = Lineararray[j - 1];
            j = j - 1;
            shifts++;  // Increment shift counter
            comparisons++;  // Increment comparison counter
        }
        Lineararray[j] = temp;
    }

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << Lineararray[i] << " ";
    }

    // Print the counters
    cout << "\nNumber of shifts: " << shifts << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}
void Insertion2D(){
    
    int i,j,k,temp;
	for(i=0;i < 5;i++){
        for(int k=1;k<5;k++){
        temp=array[i][k]; 
        j=k;
	 while((j > 0)&&(temp < array[i][j-1]))	{
        array[i][j]=array[i][j-1];
		 j=j-1;	
         }	
         array[i][j]=temp;
         }}

 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
} 

// Function to merge two sorted arrays into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the two temporary arrays back into arr[]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[] if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[] if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to perform iterative merge sort
void mergeSort(int arr[], int n) {
    // Start with subarray size of 1 and double it in each iteration
    for (int currSize = 1; currSize < n; currSize *= 2) {
        // Pick starting points of subarrays
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = left + currSize - 1;
            int right = std::min(left + 2 * currSize - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}



int main(){
//bubble2d();
//bubbleLinear();
//Selection();
InsertionLinear();
//Insertion2D(); 


  return 0;
}




 
