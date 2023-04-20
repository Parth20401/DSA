bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root == NULL)
        return false;

    if(root->data == x)
        return true;

    //recursive calls
    if(root->data > x) //go to left side
        return searchInBST(root->left, x);
    else
        return searchInBST(root->right, x);
}

//here, TC --> O(log n), in case of skewed tree it is O(n)
// SC-> O(H) because of recursive stack
