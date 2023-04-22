 void inorder(TreeNode<int>* root, vector<int>& inorderVal){
          //base case
        if(root == NULL)
            return ;
        //we perform inorder traversal
        inorder(root->left,inorderVal); //left
        inorderVal.push_back(root->data); //process the node(in this,push in vector)
        inorder(root->right,inorderVal); //right
    }
     //convert inorder int values into a BST
    TreeNode<int>* inorderToBST(int s, int e, vector<int>& inorderVal){
        //base case
        if(s>e)
            return NULL;

        int mid = (s+e)/2;
        TreeNode<int>* root = new TreeNode<int> (inorderVal[mid]); //make the middle element as node
        root->left = inorderToBST(s, mid-1, inorderVal); //left subtee would be from s to mid-1
        root->right = inorderToBST(mid+1, e, inorderVal); //right subtee would be from mid+1 to s
        return root;
    }

TreeNode<int>* balancedBst(TreeNode<int>* root) {
        vector<int> inorderVal;
        //inorder traversal->sorted values
        inorder(root, inorderVal);

        return inorderToBST(0, inorderVal.size()-1, inorderVal);
}
