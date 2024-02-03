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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;//map to hash all values in inorder array(so later we use it to find root in inorder)
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }

    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);//making the root into node

        int inRoot = mp[root->val];//finding location(index) of root in inorder array
        int numsOnLeft = inRoot - inStart;//no. of values on left of root in inorder

        root->left = solve(preorder, preStart + 1, preStart + numsOnLeft, inorder, inStart, inRoot - 1, mp);
        root->right = solve(preorder, preStart + numsOnLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

        return root;
    }
};

//TC - O(N)
//SC- O(2N)
