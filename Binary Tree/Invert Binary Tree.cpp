class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            //we do postorder processing
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};
