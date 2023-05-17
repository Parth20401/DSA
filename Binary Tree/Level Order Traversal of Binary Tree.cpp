class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)  return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr_vec;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                ans.push_back(curr_vec);
                curr_vec.resize(0);
                if(q.size() > 0) //some child nodes left
                    q.push(NULL); //so we put null after all child nodes of one level
            }
            else{
                curr_vec.push_back(temp->val);
                if(temp->left) 
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};
