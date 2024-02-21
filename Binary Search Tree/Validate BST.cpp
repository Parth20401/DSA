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
class Solution {

private:
    bool validateBST(TreeNode* root, long long mini, long long maxi){
        if(root == NULL)
            return true;

        if(root->val > mini && root->val < maxi){
            bool left = validateBST(root->left, mini, root->val);
            bool right = validateBST(root->right, root->val, maxi);
            return left && right;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
       bool ans = validateBST(root, LLONG_MIN, LLONG_MAX);
        return ans;
    }
};
