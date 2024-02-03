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
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || help(root->left, root->right);
    }

    bool help(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) //if both are null, then return true
            return left==right;

        if(left->val != right->val)//otherwise check values for both non null values
            return false;
        
        return help(left->left, right->right) && help(left->right, right->left);
    }
};

//TC - O(N)
//SC - O(H)->height of tree
