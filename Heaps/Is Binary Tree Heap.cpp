class Solution {
  public:
  int countNodes(struct Node* root){
      //base case
      if(root == NULL)
        return 0;
        
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
  }
  
  bool isCBT(struct Node* root, int index, int nodeCount){
      if(root == NULL)
        return true;
        
        //index is greater than total node count
      if(index >= nodeCount)
        return false;
    
      else{
          bool left = isCBT(root->left, 2*index + 1, nodeCount); //further calls for left subtree
          bool right = isCBT(root->right, 2*index + 2, nodeCount);
          return (left && right);
      }
  }
  
  bool MaxOrder(struct Node* root){
      if(root->left == NULL && root->right == NULL)
        return true; //leaf node is a heap in itself
        
    //if only left child exist, then return true if current node data > left->data
      if(root->right == NULL){
          return root->data > root->left->data; 
      }
      //both child exist
      else{
          bool left = MaxOrder(root->left);
          bool right = MaxOrder(root->right);
          
          return (left && right) && (root->data > root->left->data) && (root->data > root->right->data) ;
      }
  }
    bool isHeap(struct Node* tree) {
        int index = 0;
        int nodeCount = countNodes(tree);
        //two conditions to be satisfied for BT to be a heap 
        if(isCBT(tree, index, nodeCount) && MaxOrder(tree))
            return true;
        else
            return false;
    }
};
