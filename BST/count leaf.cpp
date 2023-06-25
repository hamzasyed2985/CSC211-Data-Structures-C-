int count=0;
int countLeaf(Tree *rooot){
    if(rooot == NULL){
        return 0;
    }
    if(rooot->left==NULL && rooot->right==NULL){
        return 1;
    }
    int leftCount = countLeaf(rooot->left);
    int rightCount = countLeaf(rooot->right);
    return leftCount + rightCount;
}