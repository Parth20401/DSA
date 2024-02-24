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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;//min heap which stores {node->val, node} in order to get min value each time

        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});//insert the head of all the lists
            }
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            //if an element exists after the current element (next) then insert it into the heap
            if(it.second->next)
                pq.push({it.second->next->val, it.second->next});

            temp->next = it.second; //pointing next of dummy node to the 1st head
            temp = temp->next;
        }
        return dummyNode->next;//as this contains the head of smallest node
    }
};

//TC - O(K * log K) + (N * K * log K)
//SC - O(K)
