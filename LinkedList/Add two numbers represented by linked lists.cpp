class Solution
{
    private:
    Node* reverse(struct Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void insertAtTail(struct Node* &head, struct Node* &tail,int data){
        Node* temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        
    }
    
   struct Node* add(struct Node* first, struct Node* second){
       int carry=0;
       Node* ansHead=NULL;
       Node* ansTail=NULL;
       
       while(first!=NULL || second!=NULL || carry!=0){
           
           int val1=0;
           if(first!=NULL)
               val1=first->data;
               
            int val2=0;
            if(second!=NULL)
             val2=second->data;
             
             int sum=carry+val1+val2;
             
             int digit=sum%10;
             
             //create node and add in answer LL
             insertAtTail(ansHead,ansTail,digit);
             
             carry=sum/10;
             //left side not finished
             if(first!=NULL)
                first=first->next;
                
            //right side not finished    
            if(second!=NULL)
                second=second->next;
       }
       return ansHead;
       
   }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reversing input LL
        first=reverse(first);
        second=reverse(second);
        
        Node* ans=add(first,second);
        
        ans=reverse(ans);
        
        return ans;
        
    }
};
