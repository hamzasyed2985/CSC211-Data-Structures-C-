#include <iostream>

using namespace std;

const int size = 10; 


class HashTable {
public:
    int arr[size]; 

public:
    HashTable() {
        for (int i = 0; i < size; ++i) {
            arr[i] = -1; 
            // cout << " dafsdf \n" ;
        }
    }


    
    void insert(int key) {
        int index = key % size;

        int i = 0;
        int collisions = 0;
        while (arr[index] != -1 && i != size) {
            ++collisions;
            index = (index + 1) % size; 
            ++i;
        }

        cout << "collisions : " << collisions << " \n";
        arr[index] = key;
    }
    void deleteKey(int key) {
       int index = key % size;

        int i = 0;
        int collisions = 0;
        while (arr[index] != key && i != size) {
            ++collisions;
            index = (index + 1) % size; 
            ++i;
        }

        arr[index] = -1;
        cout << "collisions : " << collisions << " \n";
    }

    
    int search(int key) {
        int index = key % size;

        int i;
        while (arr[index] != key && i != size) {
            index = (index + 1) % size; 
            ++i;
        }
        if(i != size) return arr[index];
        
        return -1;
    }
};



int main() {
    HashTable hashTable;

    
    hashTable.insert(5);
    hashTable.insert(2);
    hashTable.insert(15);


    // Search for keys
    int key = hashTable.search(2);
    cout << "Key : " << key << endl;


    return 0;
}