class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)    return head;
        ListNode* temp = head;
        int len = 1;
        //calculating length of LL
        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }

        //connecting the last node to the first node
        temp->next = head;
        k = k%len; //if k > len of LL
        int end = len - k; //to get end of list
        while(end--){
            temp = temp->next;
        }
        head = temp->next; //getting new head
        temp->next = NULL; //pointing end of LL to null

        return head;
    }
};
//TC - O(len) +  O(len - (len%k))
