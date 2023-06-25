void putidinsortedorder(Que q1){
    
    Stackk s1;
    int min,x;
    for(int i=0;i<q1.rear;i++){
    x=q1.Deque();
    min=x;
    if(x<3){
        s1.push(x);
    }
    else{
        q1.Enque(x);
    }
    }
    
q1.display();
