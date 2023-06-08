class Solution {
public:
    //to colour a single component
    bool check(int start, int V, vector<int>adj[], int colour[]){
        queue<int> q;
        q.push(start); //start is the starting index of the component
        colour[start] = 0; //initialize the first node as colour 0
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //process neighbours of the node
            for(auto it : adj[node]){
                
                //if the adjacent node is yet not coloured
                //give the opposite colour of the node
                if(colour[it] == -1){
                    colour[it] = !colour[node]; //0 becomes 1 and vice versa
                    q.push(it);
                }
                
                //if adjacent node has same colour 
                //then it has been cloured in some other path
                else if(colour[it] == colour[node])
                    return false;
            }
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
	       if(check(i, V, adj, colour) == false)
	            return false;
	       }
	   }
	   return true;
	}
};
