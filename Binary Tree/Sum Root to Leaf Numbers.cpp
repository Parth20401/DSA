/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
    ll sum = 0;

    void solve(TreeNode* root, ll val){ //val is the value at each level
        if(root == NULL)
            return;

        val = val * 10 + root->val;//making the no

        if(root->left == NULL && root->right == NULL){
            sum += val;
        }

        solve(root->left, val);
        solve(root->right, val);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        solve(root, 0);
        return sum;
    }
};
