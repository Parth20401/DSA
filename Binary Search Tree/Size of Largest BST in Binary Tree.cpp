class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

class Solution{
public:
    info solve(Node* root, int& ans){
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};
       
     //postorder traversal 
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    //now process the node
    info currNode;
    
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);//we find the max value on the right subtree
    currNode.mini = min(root->data, left.mini);
    
    //now we check the conditions 
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
        ans = max(ans, currNode.size);
    }
    else
        currNode.isBST = false;
    
        
    return currNode;
        
}
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0;
    	info temp = solve(root, maxSize);
    	return maxSize;
    }
};

//TC - O(N)
