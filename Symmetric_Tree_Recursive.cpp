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
	bool isSymmetric(TreeNode *root) {
		if(root == NULL)
			return true;
		return isSymmetricRecursive(root->left, root->right);
    }

	bool isSymmetricRecursive(TreeNode *lr, TreeNode *rr) {
		if(!lr && !rr)
			return true;
		if((!lr && rr) || (lr && !rr))
			return false;
		if(lr && rr) {
			if(lr->val != rr->val)
				return false;
			else
				return (isSymmetricRecursive(lr->left, rr->right) && 
						isSymmetricRecursive(lr->right, rr->left));
		}
	}
};
