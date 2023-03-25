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
    bool checkPallindrome(vector <int> v){
        int n=v.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(v[e]!=v[s])
                return 0;
            
            s++;
            e--;
        }
        return 1;
    }

public:
    bool isPalindrome(ListNode* head) {
        vector <int> v;
      ListNode* temp=head;

      while(temp!=NULL){
          v.push_back(temp->val);
          temp=temp->next;
      }  
        return checkPallindrome(v);
    }
};
