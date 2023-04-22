bool isBST(BinaryTreeNode<int> *root, int min, int max){
    //base case
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max){  //checking for current node
        bool left = isBST(root->left, min, root->data); //min value is same as above and max value is data of prev node
        bool right = isBST(root->right, root->data, max);
        return left && right;
        } 
        return false;
    }
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);  //for range we use max and min values of int
}
