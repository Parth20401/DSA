class Solution {
public:
    //to colour a single component
    bool dfs(int node, int col, vector<int>adj[], int colour[]){
        colour[node] = col; //assign the colour to the node
        for(auto it : adj[node]){
            
            //if adjacent node is not coloured yet, assign it with opposite colour of the node
            if(colour[it] == -1){
                if(dfs(it, !col, adj, colour) == false)  return  false;
            }
            
            //if adjacent node has same colour as that of node, then it has been coloured in a different path
            else if(colour[it] == colour[node])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   int colour[V]; //colour array to keep track of the nodes which have been coloured
	   for(int i=0; i<V; i++){
	       colour[i] = -1;
	   }
	   //for multiple components
	   for(int i=0; i<V; i++){
      
	       //if the component has not been touched
	       if(colour[i] == -1){
	       if(dfs(i, 0, adj,colour) == false)
	            return false;
	       }
	   }
	   return true;
	}
};
