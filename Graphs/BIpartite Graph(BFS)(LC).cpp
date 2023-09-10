class Solution {
public:

    bool checkBipartite(int start, int V, vector<vector<int>> adj, int color[]){
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){

            if(color[it] == -1){
                color[it] = !color[node];//opposite color to the prev node
                q.push(it);
            }

            else if(color[it] == color[node])
                return false;
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {

       int V = graph.size();
       vector<vector<int>> adj(V);

        for(int u=0; u<V; u++){
            for(int v : graph[u]){
                adj[u].push_back(v);
            }
        }

        int color[V];
        for(int i=0; i<V; i++){
            color[i] = -1;
        }

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(checkBipartite(i, V, adj, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
