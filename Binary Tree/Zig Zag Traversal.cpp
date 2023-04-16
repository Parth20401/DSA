//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	 
    	 queue<Node*> q;
    	 q.push(root);
    	  
    	 bool leftToRight = true; //flag to check whether traversal will be left to right or vice versa
    	 
    	 while(!q.empty()){
    	      int size = q.size();
    	      vector<int> ans(size); //temporary vector to store values on one level
    	      
    	      //level process
    	      for(int i=0; i<size; i++){
    	          Node* frontNode = q.front();
    	          q.pop();
    	          
    	          //normal insert or reverse insert
    	          int index = leftToRight ? i :size - i -1; //if left to right, element inserted from front ,otherise from rear
    	          ans[index] = frontNode->data;
    	          
    	          if(frontNode->left)
    	            q.push(frontNode->left);
    	            
    	             
    	          if(frontNode->right)
    	            q.push(frontNode->right);
    	      }
    	      //changing the direction
    	      leftToRight = !leftToRight;
    	      
    	      for(auto i:ans){
    	          result.push_back(i);
    	      }
    	 }
    	 return result;
    }
};
