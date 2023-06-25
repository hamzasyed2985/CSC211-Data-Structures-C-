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
 else{
    return searchingRecursion(root->left, idd);}
}

void Deletion(Tree* root,int idd){
    Tree* curr=root;
    Tree* prev=NULL;
    while(curr!=NULL && idd!=curr->id){
        prev=curr;
        if(idd>curr->id){
            curr=curr->right;
        }
        else if(idd<curr->id){
            curr=curr->left;
        }
    }if (curr->left == NULL && curr->right == NULL) {
        if (prev == NULL) {
            // Deleting root node
            root = NULL;
        } else if (prev->left == curr) {
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
        free(curr);
    }
    else if(curr->left==NULL || curr->right==NULL){
        if(curr->left!=NULL  ){
            if(curr == prev->left){
        prev->left=curr->left;}
        else{prev->right=curr->left;}
        }
        else {
            if(curr == prev->left){
        prev->left=curr->right;}
        else{prev->right=curr->right;}
        }
    }
    else{ 
       Tree* p = NULL;
        Tree* temp;

        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }

        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;
 
        curr->id = temp->id;
        free(temp);
    }



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
        cout << "\nPress 5 to Delete: ";
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
        case 5:
        cout<<"Enter id To Delete: "<<endl;
        cin>>id;
        Deletion(root,id);
        break;
        default:
			cout << "Please Enter Correct Choice";
			break;
		}
	} while (option != 0);
}

