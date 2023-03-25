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
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=getLength(head);
        if((l-n+1)==1){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            ListNode* curr=head;
            ListNode* prev=NULL;
            int cnt=1;

            while(cnt<(l-n+1)){
                prev=curr;
                curr=curr->next;
                cnt++;

            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
        }
        return head;
    }
};
