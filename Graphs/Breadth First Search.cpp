class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; //visited array
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            //now we check for neighbours of particular nodes
            for(auto it : adj[node]){
                if(!vis[it]){  //if current node is not visited
                    vis[it] = 1; //mark it visited
                    q.push(it); //also,push it into queue for further processing
                }
            }
        }
        return bfs;
    }
};
