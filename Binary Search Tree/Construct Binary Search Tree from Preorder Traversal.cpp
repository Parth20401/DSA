class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int &i){
        //base case 1
        if(i >= preorder.size()) //index goes out of bounds
            return NULL; 

        //base case 2
        if(preorder[i] < mini || preorder[i] > maxi)  //value is not in range
            return NULL;

        TreeNode* root = new TreeNode (preorder[i++]); //create node
        root->left = solve(preorder, mini, root->val, i);
        root->right = solve(preorder, root->val, maxi, i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};
