#include <iostream>
using namespace std;
struct Tree
{
	int id;
	Tree *left = NULL;
    Tree* right= NULL;
};
Tree *root = NULL;

void displayInorderTraversal(Tree *rooot){
	if (rooot!=NULL){
        displayInorderTraversal(rooot->left);
        printf("%d ", rooot->id);
        displayInorderTraversal(rooot->right);
    }
}



Tree* InsertionRecursion(Tree *rooot,int idd){
   
    if(rooot==NULL){
       Tree* node=new Tree;
       node->id = idd;
       return node;
    }
    else if (idd > rooot->id) {
        rooot->right = InsertionRecursion(rooot->right, idd);
    }
    else if (idd< root->id) {
        rooot->left = InsertionRecursion(rooot->left, idd);
    }
    return rooot;
}
void searching(int idd){
    bool h=false;
    Tree* curr=root;
    while(curr!=NULL){
    if(idd==curr->id){
        h=true;
        break;
    }
    else if(idd>curr->id){
            curr=curr->right;
        }
    else if(idd<curr->id){
        curr=curr->left;
        }
    }
    if(h==true){
     cout<<"Element fount!"<<curr->id;}
     else{
    cout<<"ID Not Found";}
}

Tree* searchingRecursion(Tree* rooot,int idd){
    if (rooot==NULL){
    return root;
  } else if (rooot->id==idd){
    return root;
    }
    if (rooot->id< idd){
       return searchingRecursion(root->right, idd);}

    return searchingRecursion(root->left, idd);
}
int main()
{
	int option;
	do
	{
		cout << "\nPress 1 to Insert: ";
		cout << "\nPress 2 to display: ";
        cout << "\nPress 3 to Search: ";
        cout << "\nPress 4 to Search Recursion: ";

		cout << "\nPress 0 to Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			int id;
        cout<<"Enter id "<<endl;
        cin>>id;
		root =InsertionRecursion(root,id);
        break;
		case 2:
		displayInorderTraversal(root);
        break;
		case 3:
        cout<<"Enter id";
        cin>>id;
		searching(id);
        break;	
        case 4:
        cout<<"Enter id "<<endl;
        cin>>id;
		root =searchingRecursion(root,id);
        break;
        default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}

