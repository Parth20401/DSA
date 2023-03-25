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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;

        ListNode* temp=head;
        ListNode* temp1=head->next;
        ListNode* firstEven=temp1;

       while(temp->next!=NULL && temp1->next!=NULL){

                temp->next=temp1->next;
                temp1->next=temp->next->next;
                temp=temp->next;
                temp1=temp1->next;
            
        }
        temp->next=firstEven;

        return head;
    }
}; 
