// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graphh
#include<iostream>
#include <string>
#include <limits.h>
#include <stdbool.h>
#include <queue>
#include <stdio.h>
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
void dfs( int graph[5][5], int startNode) {
   bool visited[5] = { false }; // Array to keep track of visited nodes
    Stackk s1;  // Stack to store nodes to be visited

    s1.push(startNode);

    while (!s1.isEmpty()) {
        int currentNode = s1.top();
        s1.pop();

        if (!visited[currentNode]) {
            visited[currentNode] = true;
            cout << currentNode << " ";  // Process the node (in this case, print it)
            string cityNames[5] = {"New York", "London", "Paris", "Tokyo", "Sydney"};
            cout << cityNames[currentNode] << endl;

            for (int neighbor = 0; neighbor < 5; ++neighbor) {
                if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                    s1.push(neighbor);  // Push unvisited neighbors onto the stack
                }
            }
        }
    }
}

class Que {
public:
    int size;
    int front;
    int rear;
    int* q;

    Que() {
        size = 50;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    Que(int z) {
        size = z;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    bool is_empty() {
        if (rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool is_full() {
        if (rear == size - 1) {
            return true;
        }
        else {
            return false;
        }
    }
void Shift_left(int front,int rear){
int z=front;
    while(z!=rear){
        q[z]=q[z+1];
        z++;
    }
    front++;
}
    void Enque(int x) {
        if (is_full()) {
            cout << "Queue is full";
        }
        else {
            if (is_empty()) {
                front=0;  rear = 0;
            }
            else {
                rear++;
            }
            q[rear] = x;
        }
    }
        int frontt(){
            return q[front];
            }
    void Deque() {
        if (is_empty()) {
            cout << "Queue is already empty";
        }
        else {
            int x = q[front];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                Shift_left(front,rear);
               rear--;
            }
        }
    }

   
};

void bfs(int graph[5][5], int startNode) {
    bool visited[5] = { false };  // Array to keep track of visited nodes
    Que q1; // Queue to store nodes to be visited

    q1.Enque(startNode);
    visited[startNode] = true;

    while (!q1.is_empty()) {
        int currentNode = q1.frontt();
        q1.Deque();

        cout << currentNode << " ";  // Process the node (in this case, print it)
        string cityNames[5] = { "New York", "London", "Paris", "Tokyo", "Sydney" };
        cout << cityNames[currentNode] << endl;

        for (int neighbor = 0; neighbor < 5; ++neighbor) {
            if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                q1.Enque(neighbor);  // Add unvisited neighbors to the queue
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},  // Node 0 is connected to nodes 1 and 2
        {1, 0, 1, 1, 0},  // Node 1 is connected to nodes 0, 2, and 3
        {1, 1, 0, 1, 0},  // Node 2 is connected to nodes 0, 1, and 3
        {0, 1, 1, 0, 1},  // Node 3 is connected to nodes 1, 2, and 4
        {0, 0, 0, 1, 0}   // Node 4 is connected to node 3
    };

    int startNode = 0;

    bfs(graph, startNode);

    return 0;
}