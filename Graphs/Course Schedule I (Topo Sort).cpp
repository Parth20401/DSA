class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        //form a graph
        vector<unordered_set<int>> adj(V);
       for(int i=0; i<prerequisites.size(); i++){
				 adj[prerequisites[i][1]].insert(prerequisites[i][0]);
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
	    if(topo.size() == V)   return true;
        return false;
    }
};
