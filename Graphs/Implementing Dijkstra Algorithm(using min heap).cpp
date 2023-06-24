class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap 
        vector<int> dist(V);
        for(int i=0; i<V; i++)  dist[i] = 1e9;
        
        dist[S] = 0; 
        pq.push({0, S}); //push {dist, node} into pq
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                //declare variables which store weight of edge and node
                int edgeWeight = it[1]; //weight stored in 2nd place
                int adjNode = it[0]; //node stored in 1st place

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
