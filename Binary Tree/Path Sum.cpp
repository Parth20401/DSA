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
    bool hasPathSum(TreeNode* root, int targetSum) {
       int currSum = 0;
       return rootToLeafSum(root, targetSum, currSum);  
    }
private:
    bool rootToLeafSum(TreeNode* root, int targetSum, int currSum){
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL){
            currSum += root->val;
            if(currSum == targetSum)
                return true;
        }
        return rootToLeafSum(root->left, targetSum, currSum + root->val) || rootToLeafSum(root->right, targetSum, currSum + root->val);
    }
};
