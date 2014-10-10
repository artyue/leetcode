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
    bool isValidBSTRecursion(TreeNode *cur, int MIN, int MAX) {
    	if(cur == NULL)
    		return true;

    	if(cur->val <= MIN)
    		return false;
    	if(cur->val >= MAX)
    		return false;

    	bool lbool, rbool;
    	lbool = isValidBSTRecursion(cur->left, MIN, cur->val);
    	rbool = isValidBSTRecursion(cur->right, cur->val, MAX);

    	if(lbool && rbool)
    		return true;
    	return false;
    }

    bool isValidBST(TreeNode *root) {
        if(root == NULL)
        	return true;

        return isValidBSTRecursion(root, INT_MIN, INT_MAX);
    }
};