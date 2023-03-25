class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
       Node* head=new Node(-1);
       Node* temp=head;
       map<int,int> mp;
       
       while(head2!=NULL){
           mp[head2->data]++;
           head2=head2->next;
       }
       while(head1!=NULL){
           if(mp.find(head1->data)!=mp.end()) //present
           {
               Node* n=new Node(head1->data);
               temp->next=n;
               temp=n;
           }
           head1=head1->next;
       }
       return head->next;
    }
};
