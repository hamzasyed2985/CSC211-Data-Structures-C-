#include <iostream>
#include <list>

using namespace std;

const int TABLE_SIZE = 10; 


struct Node {
    int key;
    Node* next;

   
};


class HashTable {
private:
    Node* table[TABLE_SIZE]; 

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr; 
        }
    }

    
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }




void insert(int key) {
        int index = hashFunction(key);

        
        Node* newNode = new Node;
        newNode->key=key;

        
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            
            newNode->next = table[index];
            table[index] = newNode;
        }
    }
 void deleteKey(int key) {
    int index = hashFunction(key);

    Node* k = nullptr;
    Node* p = table[index];

    while (p != nullptr && p->key != key) {
        k = p;
        p = p->next;
    }
    if (p == nullptr) {
     cout<<"NOT FOUND";
        return;
    }
    if (k == nullptr) {
        table[index] = p->next;
    } else {
        k->next = p->next;
    }
}

    int search(int key) {
        int index = hashFunction(key);

        
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                return key;
            }
            curr = curr->next;
        }
        return -1;
    }
};

int main() {
    HashTable hashTable;

    
    hashTable.insert(5);
    hashTable.insert(2);
    hashTable.insert(15);

    
    int key = hashTable.search(2);
    cout << "Key : " << key << endl;


    return 0;
}