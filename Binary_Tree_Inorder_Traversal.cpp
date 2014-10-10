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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> ans;
		inorderTraversalRecursive(root, ans);
		return ans;
	}

	void inorderTraversalRecursive(TreeNode *cur, vector<int> &q) {
		if(cur == NULL)
			return;

		inorderTraversalRecursive(cur->left, q);
		q.push_back(cur->val);
		inorderTraversalRecursive(cur->right, q);
	}
};
