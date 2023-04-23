void inorder(TreeNode<int>* root, vector<int>& inorderVal){
        //base case
        if(root == NULL)
            return ;
            
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->data);
        inorder(root->right, inorderVal);
    }
    
vector<int> mergeArrays(vector<int>& a, vector <int>& b){
        vector<int> ans(a.size() + b.size());
        
        int i = 0, j = 0;
        int k = 0;
        
        while(i < a.size() && j < b.size()){ //comparing values and storing in ans
          if (a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
          }
           else {
            ans[k++] = b[j];
            j++;
          }
        }
        
        while(i < a.size()){  //in case any elments are left in vector a
            ans[k++] = a[i];
            i++;
        }
        while(j < b.size()){  ////in case any elments are left in vector b
            ans[k++] = b[j];
            j++;
        }
        
        return ans;
    }
    
    TreeNode<int>* inorderToBST(int s, int e, vector<int>& inorderVal){
        //base case
        if(s>e)
            return NULL;
            
        int mid = (s+e)/2;
        TreeNode<int>* root = new TreeNode<int> (inorderVal[mid]);
        root->left = inorderToBST(s, mid-1, inorderVal);
        root->right = inorderToBST(mid+1, e, inorderVal);
        return root;
    }
    
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
        if (root1 == NULL) {
        return root2;
        }
        if (root2 == NULL) {
        return root1;
        }
     //store inorder
       vector<int> bst1,bst2;
       
       inorder(root1, bst1);
       inorder(root2, bst2);
       
       //merge 2 sorted arrays
       vector<int> mergedArray = mergeArrays(bst1, bst2);
       
       //convert sorted inorder array into BST
       int s = 0;
       int e = mergedArray.size() - 1;
       return inorderToBST(s, e, mergedArray);
   
}

//TC- O(m+n)
//SC- O(m+n)
