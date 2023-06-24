class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        //create the graph
        //for undirected graph connect both nodes to each other
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(N, 1e9); //define a distance array
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){//check if new dist is less
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }
    for(int i=0; i<N; i++){
        if(dist[i] == 1e9)  
            dist[i] = -1;
    }
    return dist;
  }
};
