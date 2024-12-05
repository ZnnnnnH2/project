struct node{
    int m;
    node *next;
};

node *inserNode(node *head,int n, int m){
    if(n==0){
        node *newNode = new node;
        newNode->m = m;
        newNode->next = head;
        return newNode;
    }
    int i=1;
    node *temp = head;
    while(i<n){
        temp = temp->next;
        i++;
    }
    node *newNode = new node;
    newNode->m = m;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

node *delNode(node *head,int n){
    if(n==1){
        return head->next;
    }
    int i=1;
    node *temp = head;
    while(i<n-1){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    return head;
}