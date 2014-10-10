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
	vector<vector<int> > levelOrder(TreeNode *root) {
		queue<TreeNode *> q;
		vector<vector<int> > va;
		int height;

		if(root == NULL) {
			va.resize(0);
			return va;
		}

		if(!root->left && !root->right) {
			va.resize(1);
			va[0].push_back(root->val);
			return va;
		}

		height = 0;
		q.push(root);
		q.push(NULL);
		va.resize(1);

		while(!q.empty()) {
			TreeNode *cur = q.front(); q.pop();
			if(cur != NULL) {
				if(cur->left) q.push(cur->left);
				if(cur->right) q.push(cur->right);
				va[height].push_back(cur->val);
			} else {
				if((q.size() == 1 && q.front() != NULL) || q.size() > 1) {
					q.push(NULL);
					height++;
					va.resize(height+1);
				}
			}
		}
		
		return va;
	}
};
