class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head==NULL)
            return NULL;

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        int count=0;

        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(count<k){
              curr = prev;
            prev = nullptr;
            while (curr != nullptr) {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }

        //recursive call
        ListNode* res=reverseKGroup(forward,k);
         if(forward!=NULL)
            head->next=res;

        return prev;
    }
};
