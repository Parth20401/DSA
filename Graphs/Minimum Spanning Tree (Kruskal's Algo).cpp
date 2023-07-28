class disjointSet {
    vector<int> rank, parent, size;
public:
    //constructor to assign initial values
    disjointSet(int n){
        rank.resize(n + 1, 0); //resizing so it works in 0-based or 1-based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i=0; i<=n; i++){
            parent[i] = i; //assign the parent array values
        }
    }
    //function to find ultimate parent
    int findUPar(int node){
        //base case
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); //ultimate parent of u
        int ulp_v = findUPar(v); //ultimate parent of v

        if(ulp_u == ulp_v)  return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{ //if size of v is greater
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //here we are given bi-directional graph i.e, 
        //1 - 2, wt=5 so 1->(2,5) and 2->(1,5) means 5,1,2 and 5,2,1 both will be stored
        //each connection will be stored twice but we don't care about it as disjoint set will automatically remove them
        vector<pair<int, pair<int, int>>> edges; //{wt, {u, v}}
        //tc - O(N + E)
        //storing the weight, adjacent node for a node (i)
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        //now disjoint set will tell us if the nodes are of the same component or not
        disjointSet ds(V); //call the constructor
        sort(edges.begin(), edges.end()); //tc - M log M
        // tc - O(M * 4 * alpha) 
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u ,v); //connect those components
            }
        }
        
        return mstWt;
    }
};
