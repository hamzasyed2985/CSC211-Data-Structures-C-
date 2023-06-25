void deletespecificnode(stu* node){
    if (first == NULL)
    {
        cout<<"Linked List is Empty: ";
    }
    else if(first == last && first == node)
    {
        delete node;
        first = last = NULL;
    }
    else if(node == first)
    {
        first = first->next;
        first->prev = NULL;
        delete node;
    }
    else if(node == last)
    {
        last = last->prev;
        last->next = NULL;
        delete node;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
}



void DeleteSmallOrGreater(){
	int id;
	cout<<"Etner id";
	cin>>id;
	stu* curr=first;
	while (curr!=NULL)
	{
		 stu* nextNode = curr->next;
		if(curr->id>id){
			deletespecificnode(curr);
		}
		curr=nextNode;
	}
	
}