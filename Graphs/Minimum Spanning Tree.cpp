class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       vector<int> vis(V, 0); //visited array
       
       pq.push({0,0}); //{weight, node}
       int sum = 0;
       
       while(!pq.empty()){
           
           auto it = pq.top();
           pq.pop();
           
           int weight = it.first;
           int node = it.second;
           
           if(vis[node] == 1)   continue;
           //add it to the MST
           vis[node] = 1; //mark it as 1
           sum += weight;
           
           //now traverse to all neighbours
           for(auto i : adj[node]){
               int adjNode = i[0];
               int edW = i[1];
               
               if(!vis[adjNode])
                    pq.push({edW, adjNode});
           }
       }
       return sum;
    }
};
