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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		return isSameTreeRecursive(p, q);
	}

	bool isSameTreeRecursive(TreeNode *p, TreeNode *q) {
		if((p == NULL && q != NULL) || (p != NULL && q == NULL))
			return false;

		if(p == NULL && q == NULL)
			return true;
		
		if(p->val != q->val)
			return false;

		if(isSameTreeRecursive(p->left, q->left) && isSameTreeRecursive(p->right, q->right))
			return true;
		else
			return false;
	}
};
