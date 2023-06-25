void deleteandnthoccurences(int m,int n){
stu* curr=first;
int count=0;
while(m!=curr->id && curr!=NULL){
    curr=curr->next;
}
if (curr == NULL) {
        return;
    }
else if (curr == first) {
        first = curr->next;
    } else {
        curr->prev->next = curr->next;
    }
    if (curr == last) {
        last = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }
    count++;
curr=first;
stu* pre;
while(count!=n && curr!=NULL){
    if(curr->id==m){
        count++;}
        pre=curr;
    curr=curr->next;
}
curr=pre;
if (curr == NULL) {
        return;
    }
else if (curr == first) {
        first = curr->next;
    } else {
        curr->prev->next = curr->next;
    }
    if (curr == last) {
        last = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }
    
}