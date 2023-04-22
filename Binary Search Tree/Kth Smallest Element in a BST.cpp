class Solution {
public:
    int solve(TreeNode* root, int &count, int k){
        //base case
        if(root == NULL)
            return -1;

        //inorder traversal
        //left
        int left = solve(root->left, count, k);

        if(left != -1)
            return left;

        //Node
        count++;
        if(count == k)
            return root->val;

        //right
        return solve(root->right, count, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return solve(root, count, k);
    }
};
