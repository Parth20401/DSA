class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;

        ListNode* ans = new ListNode(1);
        ListNode* temp = ans;
        while(a != NULL && b != NULL){
            if(a->val < b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if(a == NULL)
            temp->next = b;

        if(b == NULL)
            temp->next = a;

        return ans->next;
    }
};
