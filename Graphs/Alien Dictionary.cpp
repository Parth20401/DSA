class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	 //first create an indegree-> no of incoming edges on a node
	 int indegree[V] = {0};
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
	     return topo;
	}
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length()); //so that compaison is done only till length of smaller string
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); //non equality means s1[ptr] should be directed towards s2[ptr] in form of integer
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it : topo){
            ans += char(it + 'a');// convert number back to string
        }
        
        return ans;
    }
};
