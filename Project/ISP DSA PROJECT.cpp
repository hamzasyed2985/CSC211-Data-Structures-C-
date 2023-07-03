// INTERNET SERVICE PROVIDER SYSTEM
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// internet network provided in the following areas
string networkLocations[] = {"NUST", "SADDAR", "FAIZABAD", "RAWAL CHOWK", "WESTRIDGE", "I8", "LOK VIRSA", "G-9", "FAST", "F-9", "26-number"};
string packages[] = {"PREMIUM", "BUSINESS", "STUDENT"};
int totalCustomers = 0;

// a structure for the customers
struct Customer {
    string name;
    int package;
    int id;
    bool paid = 1;
    bool blocked = 0;
    Customer* left = 0;
    Customer* right = 0;
    int height = 1;
    Customer() {}
    Customer(string _name, int _package)
        {
            ++totalCustomers;
            name = _name;
            package = _package;
            id = totalCustomers;
        }
};


Customer *root = 0;

// required to create a priority queues for customers
struct CompareCustomers {
    bool operator()(Customer& c1, Customer& c2) {
        return c1.package > c2.package; // Min-heap based on package
    }
};

// priority queues for the requests of new internet connections where priority is assigned to premium package and then to business and then to student
priority_queue<Customer, vector<Customer>, CompareCustomers> connections;
// priority queues for complains related to the internet where priority is assigned to premium package and then to business and then to student
priority_queue<Customer, vector<Customer>, CompareCustomers> complains;

// avl to store data of customers

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Customer* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalance(Customer* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Customer* rotateRight(Customer* y) {
    Customer* x = y->left;
    Customer* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Customer* rotateLeft(Customer* x) {
    Customer* y = x->right;
    Customer* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Customer* insertCustomer(Customer* root, Customer* newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (newNode->id < root->id)
        root->left = insertCustomer(root->left, newNode);
    else if (newNode->id > root->id)
        root->right = insertCustomer(root->right, newNode);
    else
        return root; //

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && newNode->id < root->left->id)
        return rotateRight(root);

    if (balance < -1 && newNode->id > root->right->id)
        return rotateLeft(root);

    if (balance > 1 && newNode->id > root->left->id) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && newNode->id < root->right->id) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Customer* findMinValueNode(Customer* node) {
    Customer* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Customer* deleteCustomer(Customer* root, int id) {
    if (root == nullptr)
        return root;

    if (id < root->id)
        root->left = deleteCustomer(root->left, id);
    else if (id > root->id)
        root->right = deleteCustomer(root->right, id);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Customer* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            // delete temp;
        } else {
            Customer* temp = findMinValueNode(root->right);
            root->id = temp->id;
            root->name = temp->name;
            root->package = temp->package;
            root->paid = temp->paid;
            root->right = deleteCustomer(root->right, temp->id);
        }
    }
    if (root == nullptr)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrderTraversal(Customer* root) {
    if (root != 0) {
        inOrderTraversal(root->left);
        cout << "ID: " << root->id << ", Name: " << root->name << ", Package: " << packages[root->package] << ", Paid: " << (root->paid ? "Yes" : "No") << ", Blocked: " << (root->blocked ? "Yes" : "No") << endl;
        inOrderTraversal(root->right);
    }
}

// a function which blocks all the users who have not paid their bills or whose data member paid == false
void blockUnpaid(Customer* root) {
    if (root != nullptr) {
        blockUnpaid(root->left);
        if(root->paid == false) {
            root->blocked = true;
        }
        blockUnpaid(root->right);

    }
}

// a function to set the paid attribute of all the users to false when new month starts
void setPaidStatusFalse(Customer* root) {
    if (root != nullptr) {
        setPaidStatusFalse(root->left);
        root->paid = false;
        setPaidStatusFalse(root->right);

    }
}

// a function to search any customer data in the avl

Customer* search(Customer* root, int id)
{
    
    if (root == NULL || root->id == id)
        return root;
 
    
    if (root->id < id)
        return search(root->right, id);
 
    
    return search(root->left, id);
}
// a function for the users to pay their bills
void payBills(Customer* root, int id)
{
    
    if (root == NULL)
        return;
 
    if (root->id == id) {

        root->paid = 1;
        root->blocked = 0;
        cout << "bill paid by " << root->name << " id :" << root->id << endl; 
    }
 
    
    if (root->id < id)
        return payBills(root->right, id);
 
    
    return payBills(root->left, id);
}

// a function to change the package type of the customer
void changePackage(Customer* root, int id)
{
    
    if (root == NULL)
        return;
 
    if (root->id == id) {
        int p;
        cout << "Choose a Package"<< endl;
        cout << "\n1. PREMIUM"<< endl;
        cout << "2. BUSINESS"<< endl;
        cout << "3. STUDNET"<< endl;
        cin >> p;
        --p;
        root->package = p;

    }
    
    if (root->id < id)
        return changePackage(root->right, id);
 
    
    return changePackage(root->left, id);
}
 
// function to print the mst of of given areas
#define V 11
void printMST(int parent[], int graph[V][V]) {
	cout<< "" << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<< "" << networkLocations[parent[i]] << " - " << networkLocations[i] << " \t"
			<< graph[i][parent[i]] << " \n";
}


// function to find the best route for our internet network
void primMST(int graph[V][V]) {
	
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) {

    int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

		int u = min_index;

		
		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	
	printMST(parent, graph);
}

// function where we deal with the complain the of the users

void handleComplain() {
    if(complains.size() == 0) {
        cout << " no new complain \n";
        return;
        }
    Customer cus = complains.top();
            cout << "ID: " << cus.id << ", Name: " << cus.name << " complain solved" << endl;
            complains.pop();
}

// function to register the complains of the customers in the priority queue

void registerComplain(int id) {
    Customer c= *search(root, id);
    complains.push(c);
    cout << "Complain registered successfully" << endl;
}

// a function to request for new internet connection

void requestNewConnection() {
    string name;
    int package;
    cout << "Enter your name"<< endl;
    cin >> name;
    cout << "Choose a Package"<< endl;
    cout << "\n1. PREMIUM"<< endl;
    cout << "2. BUSINESS"<< endl;
    cout << "3. STUDNET"<< endl;

    cin >> package;
    --package;
    connections.push(Customer(name, package));
    cout << "Request added Successfully\nNow wait for Admin approval"<< endl;
    cout<< "Your ID is : " << totalCustomers << endl;
}

// function to add customers from the requests of connections priority queue to avl 
void acceptCustomerRequest() {
    if(connections.size() == 0) {
        cout << "no connection requests\n first customers have to request for new connection form sign up and then admin can accept their request and provide them with new connection" << endl;
        return;
    }
    string name = connections.top().name;
    int package = connections.top().package;
    int id = connections.top().id;
    Customer* cus = new Customer();
    cus->name = name;
    cus->package = package;
    cus->id = id;
    
    cout << packages[cus->package] <<" connection provided to " "ID: " << cus->id << ", Name: " << cus->name  << endl;
    
    root =  insertCustomer(root, cus);
    connections.pop();
}
int main() {

    int matrix[V][V] = {
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  12, 8},
        {0,  0,  11, 0, 4,  0,  0, 0, 0,  0,  0},
        {0,  11, 0,  5, 0,  2,  0, 0, 0,  0,  0},
        {0,  0,  5,  0, 0,  0,  2, 0, 0,  0,  0},
        {0,  4,  0,  0, 0,  0,  0, 0, 7,  0,  },
        {0,  0,  2,  0, 0,  0,  7, 6, 8,  0,  0},
        {0,  0,  0,  2, 0,  7,  0, 0, 0,  9,  0},
        {0 , 0,  0,  0, 0,  6,  0, 0, 9,  0,  0},
        {0,  0,  0,  0, 7,  8,  0, 9, 0,  10, },
        {12, 0,  0,  0, 0,  0,  9, 0, 10, 0,  },
        {8,  0,  0,  0, 11, 0,  0, 0, 14, 17, 0}      
        };

    while(true) {
        cout << "\n\n<<< MAIN MENU >>>"
        << "\n\n1. Admin"
        << "\n2. User"
        << "\n\nSelect Option: \n";
        int choice;
        cin >> choice;

        if(choice == 1) {
              cout << "<<< ADMIN MENU >>>"
                   << "\n\n1. GET THE BEST ROUTES USING PRIMS ALGORITHM"
                   << "\n2. CUSTOMER DETAILS"
                   << "\n3. ACCEPT NEW CONNECTION REQUEST"
                   << "\n4. REMOVE CUSTOMERS"
                   << "\n5. HANDLE COMPLAIN"
                   << "\n6. SET ALL CUSTOMER TO UNPAID"
                   << "\n7. BLOCK UNPAID"
                   << "\n\nSelect Option: ";
            cin >> choice;
            if(choice == 1) {
                primMST(matrix);
        }
            else if(choice == 2)
            {
                // show customers
                inOrderTraversal(root);
            }
            else if(choice == 3)
            {
                // add customer
                acceptCustomerRequest();

            }
            else if(choice == 4)
            {
                // delete customer
                cout << "Enter the ID of the customer : ";
                int deleteId;
                cin >> deleteId;
                root = deleteCustomer(root, deleteId);
            }
            else if(choice == 5)
            {
                // handle complain
                handleComplain();
            }
            else if(choice == 6)
            {
                setPaidStatusFalse(root);
            }
            else if(choice == 7)
            {
                blockUnpaid(root);
            }

        }
        else {

            cout << "\n1. Sign In";
            cout << "\n2. Sign Up";
            cout << "\n";
            cin >> choice;
            if(choice  == 1){

                int CustomerID;
                cout << "enter your id : ";
                cin >> CustomerID;
                if(search(root, CustomerID) == 0) {
                    cout << "\nno such id exists\n";
                    continue;
                }
                cout << "\n<<< USER MENU >>>"
                << "\n\n1. Register Complain"
                << "\n2. Pay Bills"
                << "\n3. Change Package"
                << "\n\nSelect Option: ";
                cin >> choice;

        
                if(choice == 1)
                {
                    // Register Complain
                    registerComplain(CustomerID);
                }
                else if(choice == 2)
                {
                    // pay bills
                    payBills(root, CustomerID);
                }
                else if(choice == 3)
                {
                    // change package
                    changePackage(root, CustomerID);
                }
            }
            else if(choice == 2) {
                // Req for new connection
                requestNewConnection();
            }
        }  
    }
    return 0;
}

