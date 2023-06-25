#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

struct Tree
{
    string Make;
    string Model;
    int year;
    int horsepower;
    int Cylinders;
    int height;
    Tree *right=NULL;
    Tree *left=NULL;
 
};
struct Tree *root = NULL;

Tree* addNode(string Make, string Model, int year, int horsepower, int cylinders) {
    // Adding data to a new node
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
int height(Tree* node)
{
    if (node == NULL)
        return 0;
    else {
       
        int leftheight = height(node->left);
        int rightheight = height(node->right);
 
       
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}

int IsBalance(Tree *node)
{
    if (node == NULL){
        return 0;}
    else {
      
        int leftheight = height(node->left);
        int rightheight = height(node->right);
 
       
       return leftheight-rightheight;
    }
}

Tree *rightRotate(Tree *y)
{
    Tree *x = y->left;
    Tree *z = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = z;
 
    // Update heights
    x->height = height(x);
    y->height = height(y);
 
    // Return new root
    return x;
}

Tree *leftRotate(Tree *x)
{
    Tree *y = x->right;
    Tree *z = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = z;
 
    // Update heights
    x->height = height(x);
    y->height = height(y);
 
    // Return new root
    return y;
}

void print() {
    Tree* ptr = root;
    if (ptr == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
    while (ptr != NULL) {
        cout << ptr->Make << " , " << ptr->Model << " , " << ptr->year << " , "<< ptr->horsepower << " , " << ptr->Cylinders << endl;
        ptr = ptr->right;
    }
}

Tree* Insertion(Tree *node,string Make, string Model, int year, int horsepower, int cylinders){
   
    if(node==NULL){
      return  addNode(Make,  Model, year, horsepower, cylinders);
    }
    else if (horsepower > node->horsepower) {
        node->right = Insertion(node->right,Make,  Model, year, horsepower, cylinders);
    }
    else if (horsepower < node->horsepower) {
        node->left = Insertion(node->left, Make,  Model, year, horsepower, cylinders);
    }
    return node;

    node->height = height(node);
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = IsBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && horsepower < node->left->horsepower)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && horsepower > node->right->horsepower)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && horsepower > node->left->horsepower)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && horsepower < node->right->horsepower)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

void preOrder(Tree *node)
{
    if(node != NULL)
    {
        preOrder(node->left);
        cout << node->horsepower << " ";
        preOrder(node->right);
    }
}

Tree *minValueNode(Tree *node)
{
    Tree *current = node;

    // Find the leftmost leaf node
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Tree *deletion(Tree *node, int horsepower)
{
    // Perform the standard BST deletion
    if (node == NULL)
        return node;

    // If the key to be deleted is smaller than the node's key, go to the left subtree
    if (horsepower < node->horsepower)
        node->left = deletion(node->left, horsepower);

    // If the key to be deleted is greater than the node's key, go to the right subtree
    else if (horsepower > node->horsepower)
        node->right = deletion(node->right, horsepower);

    // If the key to be deleted is the same as the node's key, this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (node->left == NULL)
        {
            Tree *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Tree *temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Tree *temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->Make = temp->Make;
        node->Model = temp->Model;
        node->year = temp->year;
        node->horsepower = temp->horsepower;
        node->Cylinders = temp->Cylinders;

        // Delete the inorder successor
        node->right = deletion(node->right, temp->horsepower);
    }

    // Update the height of the current node
    node->height = height(node);

    // Check the balance factor and perform rotations if necessary
    int balance = IsBalance(node);

    // Left Left Case
    if (balance > 1 && IsBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && IsBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && IsBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && IsBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

int main()
{
	int years;
    //reading data from file
    ifstream fin;
    fin.open("cars1.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while(!fin.eof()){
        //reading data and adding to vector
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            lineData.push_back(word);
        }
        //type casting from string to int
        stringstream s1(lineData[2]);
        int year;
        s1>>year;
        stringstream s2(lineData[3]);
        int horsepower;
        s2>>horsepower;
        stringstream s3(lineData[4]);
        int cylinders;
        s3>>cylinders;
        //adding data to linked list
        if(lines!=0)
        {
            root= Insertion(root, lineData[0],lineData[1],year,horsepower,cylinders);
        }
        //clearing vector
        lineData.clear();
        lines++;
    }
    //switch to ask user what to do
    int choice = 0;
    do
    {
        cout<<"press 1 for avl insertion "<<endl;
        cout<<"press 2 for avl deletion "<<endl;
        cout<<"press 3 for avl traversal "<<endl;
        cout<< "Select an option and 0 to exit:";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                print();
                break;
            }
            case 2 :
            {
                
            }
            case 3 :
            {
               preOrder(root); 
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