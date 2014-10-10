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
		
		queue<TreeNode *>lq, rq;

		if(!root->left && !root->right)
			return true;

		if(root->left)
			lq.push(root->left);
		if(root->right)
			rq.push(root->right);

		while(!lq.empty() && !rq.empty()) {
			TreeNode *l, *r;
			l = lq.front(); lq.pop();
			r = rq.front(); rq.pop();
			if(l->val != r->val) {
				return false;
			} else {
				if((l->left && !r->right) || (!l->left && r->right))
					return false;
				if((r->left && !l->right) || (!r->left && l->right))
					return false;
				if(l->left && r->right) {
					lq.push(l->left);
					rq.push(r->right);
				}
				if(r->left && l->right) {
					lq.push(l->right);
					rq.push(r->left);
				}
			}
		}

		if(lq.empty() && rq.empty())
			return true;
		else
			return false;
    }
};
