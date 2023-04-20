bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL){
        
        if(temp->data == x)
            return true;
            
        if(temp->data > x) 
            temp = temp->left; //go to left part

        else
            temp = temp->right;
    }
    return false;
}

//TC-->O(log n) and SC->constant space O(1)
