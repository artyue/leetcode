/**
    * Definition for binary tree
	** struct TreeNode {
	**     int val;
	**     TreeNode *left;
	**     TreeNode *right;
	**     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	** };
	**/
class Solution {
public:
	TreeNode *flattenRecursive(TreeNode *cur) {
		if(cur->left == NULL && cur->right == NULL)
			return cur;

		if(cur->left != NULL && cur->right == NULL) {
			TreeNode *ret = flattenRecursive(cur->left);
			cur->right = cur->left;
			cur->left = NULL;
			return ret;
		}
		
		if(cur->left == NULL && cur->right != NULL) {
			return flattenRecursive(cur->right);
		}

		if(cur->left != NULL && cur->right != NULL) {
			TreeNode *tmp_tail = flattenRecursive(cur->left);
			TreeNode *ret = flattenRecursive(cur->right);
			tmp_tail->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
			return ret;
		}
	}

	void flatten(TreeNode *root) {
		if(root == NULL)
			return;

		flattenRecursive(root);
	}
};
