class disjointSet {
public:
    vector<int> rank, parent, size;
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
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointSet ds(n); //here n is no of vertices

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                // i-j or j-i
                ds.unionBySize(i, j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i)
                count++;
        }
        return count;
    }
};
