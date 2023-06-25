stu* ReverseRecursion(stu *p){

	  if(p->next==NULL) {
		first=p;
        return p;
    }
    
    stu* newHead=ReverseRecursion(p->next);
    p->next->next=p;
    p->next=NULL;
    return newHead;
}