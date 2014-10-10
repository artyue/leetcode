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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		preorderTraversalRecursive(root, ans);
		return ans;
	}

	void preorderTraversalRecursive(TreeNode *cur, vector<int> &q) {
		if(cur == NULL)
			return;

		q.push_back(cur->val);
		preorderTraversalRecursive(cur->left, q);
		preorderTraversalRecursive(cur->right, q);
	}
};
