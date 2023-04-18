/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node* root, int& k, int node){
    //base case
    if(root == NULL)
        return NULL;
    
    if(root->data == node)
        return root;
        
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){ //checking if leftside has non null value
        k--;
        if(k == 0){  //if zero, then return that root
            k = INT_MAX; //when in next step when we do k-- ,it should not go towards 0,hence a big value
            return root;
        }
        return leftAns; //when k!=NULL, then return the non null root
    }
        if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k == 0){
            k = INT_MAX; //when in next step when we do k-- ,it should not go towards 0,hence a big value
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node) //2nd cond-->if k>=1 and node is the root itself,so return -1
        return -1;
    else
        return ans->data;        
}
