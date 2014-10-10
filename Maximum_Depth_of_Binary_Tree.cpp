/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
		if(root == NULL)
			return 0;

        int max_depth = 0;
        root->val = 1;
        maxDepthRecursive(root, max_depth);
        return max_depth;
    }
    
    void maxDepthRecursive(TreeNode *cur, int &max_depth) {
        max_depth = ((max_depth < cur->val) ? cur->val : max_depth);
        if(cur->left != NULL) {
            cur->left->val = cur->val + 1;
            maxDepthRecursive(cur->left, max_depth);
        }
        if(cur->right != NULL) {
            cur->right->val = cur->val + 1;
            maxDepthRecursive(cur->right, max_depth);
        }
    }
};
