class Solution {
  private:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[N];
      //create the graph
      for(int i=0; i<M; i++){
          int u = edges[i][0];
          int v = edges[i][1];
          int wt = edges[i][2];
          adj[u].push_back({v, wt}); //push the {adj node, weight} of the current node
      }
      
      //find the topo sort
       //TC - O(N + M)
      vector<int> vis(N, 0);// visited array
      stack<int> st;
      for(int i=0; i<N; i++){
      if(!vis[i])
        topoSort(i, adj, vis, st);
        }
    
    //now fill out the distance array (Relax all the edges)
    vector<int> dist(N);
    for(int i=0; i<N; i++)  dist[i] = 1e9; //mark all the distances as infinity;
    dist[0] = 0; //mark the source as 0 (as dist from src to src is 0)
       //TC - O(N + M) -> elements in stack + no of edges which it will go through
     while(!st.empty()){
        int node = st.top();
        st.pop();
        
        //now define v and wt
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            
            //check if dist [node] + new added dist < already stored dist
            if(dist[node] + wt < dist[v])
            dist[v] = dist[node] + wt; //update the dist
        }
    }
    for(int i=0; i<N; i++){
        if(dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
  }
};
