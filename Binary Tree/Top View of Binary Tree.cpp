/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
       map<int,int> topNode; //to keep horizontal dist and node->data
       vector<int> ans;
       
       if(root == NULL)
            return ans;
        queue<pair<Node*,int> > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second; //horizontal dist
            
            //if one value is present for one HD,then do nothing
            if(topNode.find(hd) == topNode.end()) //value of data corresponding to HD 
                topNode[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
    }
    for(auto i:topNode){
        ans.push_back(i.second); //i represents a row which contains HD and data
    }
    return ans;
    }

};
