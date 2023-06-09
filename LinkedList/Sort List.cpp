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
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            if(fast!=NULL){
            slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right ){
        if(left==NULL)  return right;
        if(right==NULL)  return left;

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
               temp=temp->next;
                right=right->next;
            }
        }

        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
            }

        while(right!=NULL){
            temp->next=right;
            temp=right;
           right=right->next;
        }

        ans=ans->next;
        return ans;
        }
public:
    ListNode* sortList(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
            return head;
            //break list into 2 halves after finding mid
        ListNode* mid=findMid(head);
        if(mid->next==NULL)
            return head;
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        //recursive calls to sort left & right
        left=sortList(left);
        right=sortList(right);

        //merge both halves
        ListNode* ans=merge(left,right);
        return ans;
    }
};
