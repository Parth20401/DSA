class Solution {
public:
    int FindPosition(vector<int>& inorder, int inorderStart, int inorderEnd, int n, int element){
        for(int i=inorderStart; i<=inorderEnd; i++){
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int & index, int inorderStart, int inorderEnd, int n){
        //base case
        if(index >= n || inorderStart > inorderEnd)
            return NULL;

        //create root node for an element
        int element = preorder[index++]; //ater every iteration index is increasing
        TreeNode* root = new TreeNode (element); //making the node
        int position = FindPosition(inorder, inorderStart, inorderEnd, n, element);

        //recursive calls
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n); //left subtree has values one before root in inorder
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};
