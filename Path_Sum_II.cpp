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

	void pathSumRecursive(TreeNode *cur, vector<vector<int> > &v, int pre_sum, int sum, int layer, int tmp_arr[]) {
		if(!cur->left && !cur->right) {
			if(pre_sum + cur->val == sum) {
				vector<int> tmp;
				for(int i = 0; i < layer; i++)
					tmp.push_back(tmp_arr[i]);
				tmp.push_back(cur->val);
				v.push_back(tmp);
			}
			return;
		}
		
		tmp_arr[layer] = cur->val;
		if(cur->left)
			pathSumRecursive(cur->left, v, pre_sum+cur->val, sum, layer+1, tmp_arr);

		tmp_arr[layer] = cur->val;
		if(cur->right)
			pathSumRecursive(cur->right, v, pre_sum+cur->val, sum, layer+1, tmp_arr);
	}

	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > v;
		if(root == NULL)
			return v;

		int path_num = 0;
		int tmp_arr[9999];
		pathSumRecursive(root, v, 0, sum, 0, tmp_arr);
		return v;
	}
};
