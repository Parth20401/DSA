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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)  return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy, *prev = dummy, *nex = dummy;

        int len = 0;
        //find length of list
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }

        while(len >= k){
            //assigning values to curr and nex
            curr = prev->next;
            nex = curr->next;
            //now perform (k-1) reversals for each group
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;//moving nex forward (can't write nex = nex->next as it points to curr)
            }
            len = len - k;
            prev = curr;
        }
        return dummy->next;
    }
};
//Tc - O(N/K)*N = O(N)
//SC - O(1)
