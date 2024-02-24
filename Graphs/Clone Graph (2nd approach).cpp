/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;//This map will store the mapping between original nodes and their corresponding cloned nodes
    Node* cloneGraph(Node* node) {
        //2nd approach
        if(node == NULL)
            return NULL;

        if(mp.find(node) == mp.end()){//checks if the node has already been cloned
            mp[node] = new Node(node->val, {});//It creates a new node with the same value as the original node and an empty neighbor list initially.

            for(auto adj : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(adj));//cloning each neighbor of the original node and adding the corresponding cloned neighbor to the list of neighbors of the cloned node
            }
        }
        return mp[node];
    }
};
//TC - O(V + E)
//Sc - O(V)
