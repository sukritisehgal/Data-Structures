int getMiddle(struct Node *head)
{
   // Your code here
    if(head==NULL)
        return -1;
    
    struct Node* ptr=head;
    int count=0;
    
    while(ptr!=NULL)
    {
        count=count+1;
        ptr=ptr->next;
    }
    
        int middle_pos=(count/2)+1;
        ptr=head;
        for(int i=0;i<middle_pos-1;i++)
        {
            ptr=ptr->next;
        }
        return ptr->data;
       // return middle_pos;
    
    
    
}