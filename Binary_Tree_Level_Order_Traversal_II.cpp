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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		queue<TreeNode *> q;
		vector<vector<int> > va, vb;
		int height;

		if(root == NULL) {
			vb.resize(0);
			return vb;
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
		
		vb.resize(height+1);
		for(int i = height; i >= 0; i--) {
			for(int j = 0; j < va[height-i].size(); j++) {
				vb[i].push_back(va[height-i][j]);
			}
		}
		return vb;
	}
};
