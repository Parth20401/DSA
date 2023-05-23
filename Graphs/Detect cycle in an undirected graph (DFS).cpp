class Solution {
  private:
  bool dfs(int node, int parent, int vis[], vector<int> adj[]){
      vis[node] = 1;
      for(auto adjacentNode : adj[node]){
          if(!vis[adjacentNode]){
              if(dfs(adjacentNode, node, vis, adj) == true){
                  return true;
              }
          }
              else if(adjacentNode != parent)   return true;
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0}; //for connected components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
