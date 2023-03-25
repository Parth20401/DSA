int getlength(Node *head){
    Node* temp=head;
    int len=0;
    while(temp->next!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    if(head==NULL || head->next==NULL)
        return 0;
        
    Node* fast=head;
    Node* slow=head;
    Node* entry=head;
    int c=0;
    int len1=getlength(head);
    
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        
        if(fast==slow){
            while(entry!=slow){
                slow=slow->next;
                entry=entry->next;
                c++;
            }
            return len1-c;
        }
    }
    
        //return len1-c;
    return 0;
}
