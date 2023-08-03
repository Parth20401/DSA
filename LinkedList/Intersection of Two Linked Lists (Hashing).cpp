class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        while(headA != NULL){
            st.insert(headA);
            headA = headA->next;
        }

        //check for headA elments in headB
        while(headB != NULL){
            if(st.find(headB) != st.end())
                return headB;
            
            headB = headB->next;
        }
        return NULL;
    }
};
//Tc - O(n+m)
//Sc - O(N)
