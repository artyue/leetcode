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
	void minDepthRecursive(TreeNode *cur, int cur_depth, int &cur_min_depth) {
		if(!cur->left && !cur->right)
			if(cur_min_depth > cur_depth)
				cur_min_depth = cur_depth;

		if(cur_depth >= cur_min_depth)
			return;

		if(cur->left)
			minDepthRecursive(cur->left, cur_depth+1, cur_min_depth);
		if(cur->right)
			minDepthRecursive(cur->right, cur_depth+1, cur_min_depth);

	}

	int minDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
		
		int cur_min_depth = 99999999;
		minDepthRecursive(root, 1, cur_min_depth);
		return cur_min_depth;
    }
};
