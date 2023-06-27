class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        //create the directed graph
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]}); //takes the source node and pushes the destination node and the cost as a pair into the adjacency list
        }
        //{stops, {node, dist}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9); //store the cost to reach 
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue; //if stops > k, go for next iteration
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second; //edge weight
                //check if cost + new edge weight < already stored cost in dist array
                if(cost + edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}}); //update the queue
                }
            } 
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst]; //return the number at index of dst
    }
};
