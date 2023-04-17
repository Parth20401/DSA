class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int> > > nodes; //int->horizontal dist, int->level, int->list of nodes
        queue<pair<Node*,pair<int,int> > > q; 
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root,make_pair(0,0))); //hd and lvl initially is 0
        
        while(!q.empty()){
            pair<Node*,pair<int,int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first; //horizontal distance
            int lvl = temp.second.second; //level of tree
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left) //if frontNode->left is non null
                q.push(make_pair(frontNode->left, make_pair(hd - 1,lvl + 1))); //for left subtree, hd will be -1 and level will increase
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1,lvl + 1)));
                
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
