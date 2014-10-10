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
	void sumNumbersRecursive(TreeNode *cur, int cur_sum, int &total_sum) {
		cur_sum = cur_sum * 10 + cur->val;

		if(!cur->left && !cur->right) {
			total_sum += cur_sum;
			return;
		}
		
		if(cur->left)
			sumNumbersRecursive(cur->left, cur_sum, total_sum);
		if(cur->right)
			sumNumbersRecursive(cur->right, cur_sum, total_sum);

	}

	int sumNumbers(TreeNode *root) {
		if(root == NULL)
			return 0;

		int total_sum = 0;
		sumNumbersRecursive(root, 0, total_sum);
		return total_sum;
	}
};
