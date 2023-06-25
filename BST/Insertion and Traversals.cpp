#include <iostream>
using namespace std;


struct Tree
{
	int id;
	Tree *left = NULL;
    Tree* right= NULL;
};

Tree *root = NULL;
class Stackk
{
public:
    int tos;
    Tree** q;

public:
    Stackk()
    {
        tos = -1;
       int size=10;
       q = new Tree*[size];
    }
    Stackk(int x)
    {
        tos = -1;
       q = new Tree*[x];
    }
    void push(Tree* x)
    {
        if (tos == 100000)
        {
            cout << "\nStackk overflow condition" << endl;
        }
        else
            q[++tos] = x;
    }
    Tree* pop()
    {
        if (tos == -1)
        {
            cout << "\nStackk Underflow condition" << endl;
            return 0;
        }
        else
            return q[tos--];
    }
    Tree* top()
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

void display(){
    for (int i=0;i<=tos;i++){
        cout<<"\nElement at Index"<<i<<"is:"<<q[i];
    }
    }
};   
void displayInorderTraversal(Tree *rooot){
	if (rooot!=NULL){
        displayInorderTraversal(rooot->left);
        displayInorderTraversal(rooot->right);
        printf("%d ", rooot->id);
    }
}

void Insertion(){
    int ele;
    cout<<"Enter An Element";
    cin>>ele;
    Tree *curr=root;
    Tree *node=new Tree;
    node->id=ele;
    Tree *prev=NULL;
    if(root==NULL){
       root=node;
       return; 
    }
    else{
        while (curr!=NULL)
        {
            if(ele>curr->id){
                prev=curr;
                curr=curr->right;
            }
            else if(ele<curr->id){
                prev=curr;
                curr=curr->left;
            }
        }
        if(prev == NULL){
            root = node;
        }
            if(ele>prev->id){prev->right=node;}
            else{prev->left=node;} 
    }
}

Tree* InsertionRecursion(Tree *root,int idd){
   
    if(root==NULL){
       Tree* node=new Tree;
       node->id = idd;
       return node;
    }
    else if (idd > root->id) {
        root->right = InsertionRecursion(root->right, idd);
    }
    else if (idd< root->id) {
        root->left = InsertionRecursion(root->left, idd);
    }
    return root;
}

void PreorderTraversalIterative(){
    Stackk s1;
    s1.push(root);
    while(!s1.isEmpty()){
        Tree* curr = s1.top();
        s1.pop();
        cout<<curr->id<<" ";
        if(curr->right!=NULL){
            s1.push(curr->right);
        }
        if(curr->left!=NULL){
            s1.push(curr->left);
        }
    }
}
void InorderTraversalIterative(){
    Stackk s1;
    Tree* curr=root;
  while(curr!=NULL || !s1.isEmpty()){
    while(curr!=NULL ){
    s1.push(curr);
    curr=curr->left;}
    curr=s1.top();
    s1.pop();
    cout << curr->id << " ";
    curr = curr->right;
  }
}
void PostorderTraversalIterative(){
    Stackk s1, s2;
    s1.push(root);
    Tree* node;
    while (!s1.isEmpty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.isEmpty()) {
        node = s2.top();
        s2.pop();
        cout << node->id << " ";
    }
}

int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert: ";
		cout << "\nPress 2 to display: ";
        cout << "\nPress 3 to Insert Recursion: ";
        cout << "\nPress 4 to display Iterative: ";
        cout << "\nPress 5 to display inorder Iterative: ";
        cout << "\nPress 6 to display Postorder Iterative: ";
		cout << "\nPress 0 to Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			Insertion();
			break;
		case 2:
		displayInorderTraversal(root);
        break;
			case 3:
        int id;
        cout<<"Enter id "<<endl;
        cin>>id;
		root =InsertionRecursion(root,id);
        break;
        case 4:
		PreorderTraversalIterative();
        break;
		case 5:
		InorderTraversalIterative();
        break;
        case 6:
        PostorderTraversalIterative();
        break;
		default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}

