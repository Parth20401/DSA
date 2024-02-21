class Solution
{   
    private:
    void findPred(Node* root, Node*& pre, int key){
        
        while(root != NULL){
            
            if(root->key >= key){
                root = root->left;
            }
            else{
                pre = root;//storing as it cud be a potential ans
                root = root->right;
            }
        }
    }
    
    void findSucc(Node* root, Node*& suc, int key){
        
        while(root != NULL){
            
            if(root->key <= key){
                root = root->right;
            }
            else{
                suc = root;//storing as it cud be a potential ans
                root = root->left;
            }
        }
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        
        findPred(root, pre, key);
        findSucc(root, suc, key);
      
    }
};
