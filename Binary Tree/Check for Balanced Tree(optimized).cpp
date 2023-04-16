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
    pair<bool,int> isBalancedFast(TreeNode* root){
        //base case
        //take pair to which takes whether tree is balanced and its height in one variable to reduce complexity
        if(root == NULL){
            pair<bool,int> p = make_pair(true, 0);  //if root is null, it means tree is balanced (true) and height is 0
            return p;
    }
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool leftAns = left.first; //gives whether left subtree is balanced or not
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1; //checking for height condition

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
            return isBalancedFast(root).first;
        }
};
