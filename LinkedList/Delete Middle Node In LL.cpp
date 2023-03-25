/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* head){
       if(head==NULL)
            return 0;
        ListNode* temp=head;
        int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
        return len;
}
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
            return NULL;

        if(head->next==NULL){
            delete head;
            return NULL;
        }
        int len=getLength(head);
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=1;

        while(cnt<((len/2)+1)){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;   

        return head;
    }
};
