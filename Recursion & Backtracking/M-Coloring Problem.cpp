class Solution{
public:
    bool isSafe(int node, int colour[], bool graph[101][101], int n, int col){
        //above, col is the current colour we are assigning
        //traverse through all adjacent nodes
        for(int k=0; k<n; k++){
            if(k != node && graph[k][node] == 1 && colour[k] == col) //graph[k][node] == 1 means graph has an edge b/w these 2 nodes
                return false;                                       // colour[k] == col mens adj nodes having same colour
        }
        return true;
    }

    bool solve(int node, bool graph[101][101], int m, int n, int colour[]){
        //base case
        if(node == n){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(isSafe(node, colour, graph, n, i)){
                colour[node] = i; //if it possible to colour a node, then assign a colour to it
              if(solve(node + 1, graph, m, n, colour))  return true; //recursion
              //now if false, then backtrack
              colour[node] = 0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colour[n] = {0};
        if(solve(0, graph, m, n, colour))  return true;
        return false;
    }
};
//TC - O(n^m)
//SC - O(n)
