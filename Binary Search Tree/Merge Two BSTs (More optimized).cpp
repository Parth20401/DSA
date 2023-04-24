void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>*& head){
    //base case
    if(root == NULL)
        return ;

    convertIntoSortedDLL(root->right, head);

    root->right = head; //point right side to head

    if(head != NULL)
        head->left = root; //point left of head to root

    head = root;

    convertIntoSortedDLL(root->left, head); //call for left
}

TreeNode<int> *mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2){
    TreeNode<int> * head = NULL;
    TreeNode<int> * tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){ 
            if(head == NULL){
                //we assign head and tail as head1 bcos it is smaller 
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;    //assign tail to prev head1
                head1 = head1->right; //increment head1
            }
        }
        else{
            if(head == NULL){
                //we assign head and tail as head2 bcos it is smaller 
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else {
              tail->right = head2;
              head2->left = tail;
              tail = head2;         // assign tail to prev head1
              head2 = head2->right; // increment head1
            }
        }
    }
        //for any remaining/extra elements
        while(head1 != NULL){
            tail->right = head1;
            head1->left = tail;
            tail = head1;    //assign tail to prev head1
            head1 = head1->right; //increment head1
        }

        while(head2 != NULL){
            tail->right = head2;
            head2->left = tail;
            tail = head2;    //assign tail to prev head1
            head2 = head2->right; //increment head1
            }

        return head;
}
int countNodes(TreeNode<int>* head){
    int cnt = 0;
    TreeNode<int>* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp->right;
    } 
    return cnt;
}

TreeNode<int> * sortedLLToBST(TreeNode<int>*& head, int n){
    //base case
    if(n <= 0 || head == NULL)
        return NULL;

    //make left subtree
    TreeNode<int>* left = sortedLLToBST(head, n/2); //first n/2 nodes will make left subtree

    
    TreeNode<int>* root = head; //creating root node
    root->left = left; //attaching left subtree to root

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1); //remaining part will be right subtree

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
 //Step 1->convert BST into sorted LL in-place
       TreeNode<int>* head1 = NULL;
       convertIntoSortedDLL(root1, head1);
       head1->left = NULL;

       TreeNode<int>* head2 = NULL;
       convertIntoSortedDLL(root2, head2);
       head2->left = NULL;

       //Step 2-> merge the two LL's
       TreeNode<int>* head = mergeLinkedList(head1, head2);

       //Step 3-> convert sorted LL into BST
       return sortedLLToBST(head, countNodes(head));
   
}
//TC - O(m+n)
//SC - O(H1+H2)
