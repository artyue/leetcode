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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		postorderTraversalRecursive(root, ans);
		return ans;
	}

	void postorderTraversalRecursive(TreeNode *cur, vector<int> &q) {
		if(cur == NULL)
			return;

		postorderTraversalRecursive(cur->left, q);
		postorderTraversalRecursive(cur->right, q);
		q.push_back(cur->val);
	}
};
