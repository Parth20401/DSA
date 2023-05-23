class Solution {
  private:
  bool detectCycle(int src, vector<int> adj[], int vis[]){
      vis[src] = 1;
      queue<pair<int,int>> q; // ({node, place where it came from in the adjacency list})
      q.push({src, -1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjacentNode : adj[node]){
              if(!vis[adjacentNode]){
                  vis[adjacentNode] = 1; //mark the visited node
                  q.push({adjacentNode, node});
              }
              else if(parent != adjacentNode) //the node found has already been visited but is not a parent(or not found before)
                return true; //it is a cycle
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if (detectCycle(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
