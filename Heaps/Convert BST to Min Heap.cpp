void inorderTraversal(BinaryTreeNode* root,vector<int>& ans){

	if(root == NULL)
		return ;

	inorderTraversal(root->left, ans);
	ans.push_back(root->data);
	inorderTraversal(root->right, ans);
}
void fillPreOrder(BinaryTreeNode* root, vector<int>& ans, int &i){
	//ans vector contains inorder 
	if(i == ans.size())
		return;
	if(root == NULL)
		return;
	
	root->data = ans[i++];
	fillPreOrder(root->left, ans, i);
	fillPreOrder(root->right, ans, i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> inorder;
	//Step 1-> inorder traversal (sorted)
	inorderTraversal(root, inorder);
	//Step 2-> pre order of that inorder as given by conditions
	int index = 0;
	fillPreOrder(root, inorder, index);
	return root;
}
