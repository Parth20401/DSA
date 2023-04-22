class Solution {
public:
    void inorder(TreeNode* root,vector<int>& inorderVal){
          //base case
        if(root == NULL)
            return ;
        //we perform inorder traversal
        inorder(root->left,inorderVal); //left
        inorderVal.push_back(root->val); //process the node(in this,push in vector)
        inorder(root->right,inorderVal); //right
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        //inorder traversal->sorted values
        inorder(root, inorderVal);

        int i = 0, j = inorderVal.size()-1;
        //2 pointer approach
        while(i < j){
            int sum = inorderVal[i] + inorderVal[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};
