void inorder(TreeNode<int>* root,vector<int>& inorderVal){
          //base case
        if(root == NULL)
            return ;
        //we perform inorder traversal
        inorder(root->left,inorderVal); //left
        inorderVal.push_back(root->data); //process the node(in this,push in vector)
        inorder(root->right,inorderVal); //right
    }

TreeNode<int>* flatten(TreeNode<int>* root)
{
        vector<int> inorderVal;
        //inorder traversal->sorted values
        inorder(root, inorderVal);
        int n = inorderVal.size();

        TreeNode<int>* newRoot = new TreeNode<int> (inorderVal[0]); //store first value as a node
        TreeNode<int>* curr = newRoot;

        //
        for(int i=1;i<n;i++){
            //create the nodes from vector
            TreeNode<int>* temp = new TreeNode<int> (inorderVal[i]);
            //connect left pointer to null and right pointer to next value, except fot last value
            curr->left = NULL; 
            curr->right = temp;
            curr = temp; 
        }

        //now,for last element, both left and right pointers will be null
        curr->left = NULL;
        curr->right = NULL;

        return newRoot;
}
