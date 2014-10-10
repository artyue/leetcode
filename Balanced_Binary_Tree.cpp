/**
 ** Definition for binary tree
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if(!root)
			return true;
		if(abs(isBalancedRecursive(root->left) - isBalancedRecursive(root->right)) > 1)
			return false;
		else
			return isBalanced(root->left) && isBalanced(root->right);
	}

	int isBalancedRecursive(TreeNode *cur) {
		if(cur == NULL)
			return 0;
		
		int ll = isBalancedRecursive(cur->left);
		int rr = isBalancedRecursive(cur->right);

		return ((ll > rr) ? ll : rr) + 1;
	}
};
