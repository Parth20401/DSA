pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int suc = -1;
    int pre = -1;
    //traversal using loop
    while(temp->data != key){
        if(temp->data > key){
            suc = temp->data; //if the data at current node(temp) > key,it can be a potential successor
            temp = temp->left;
        }
        else{
            pre = temp->data;
            temp = temp->right;
        }
    }
    
    //finding pred and succ
    //pred
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree != NULL){
        pre = leftTree->data; 
        leftTree = leftTree ->right; //pred is the max element of left subtree
    }
    
    //succ
    BinaryTreeNode<int>* rightTree = temp->right;
    while (rightTree != NULL) {
      suc = rightTree->data; // succ is the min element of right subtree
      rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pre, suc);
    return ans;
}
