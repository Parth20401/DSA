class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

     //first create an indegree-> no of incoming edges on a node
	 vector<int> indegree(V, 0);
	 for(int i=0; i<V; i++){
	     for(auto it : adj[i]){
	         indegree[it]++; //increase the value as we get node pointing another node
	     }
	 }
	     //push the elements in queue which have no indegree initially
	     queue<int> q;
	     for(int i=0; i<V; i++){
	         if(indegree[i] == 0){
	            q.push(i);
	         }
	     }
	     
	     vector<int> topo;
	     //process the elements in queue
	     while(!q.empty()){
	         int node = q.front();
	         q.pop();
	         topo.push_back(node);
	         
	         //node is in topo sort so please remove it from indegree
	         for(auto it : adj[node]){
	             indegree[it]--;
	             if(indegree[it] == 0)  
	                q.push(it);
	         }
	     }
         //here we check if we have traversed whole graph
	    if(topo.size() == V)   return topo;
        return {};
    }
};
