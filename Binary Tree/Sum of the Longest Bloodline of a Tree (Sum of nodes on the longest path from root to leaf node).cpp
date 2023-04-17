struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, int len, int& maxLen, int sum, int& maxSum){
        //base case
        if(root == NULL){ //maybe the path has ended, so we need to check it
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
             maxSum = max(maxSum, sum);   
            }
         return;   
        }
        
        sum = sum + root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum); //calling for left subtree
        solve(root->right, len+1, maxLen, sum, maxSum); //calling for right subtree
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};
