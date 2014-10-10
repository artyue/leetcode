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
	vector<TreeNode *> generateTreesRecursion(int start, int end) {
		vector<TreeNode *> v;
		if(start > end) {
			v.push_back(NULL);
			return v;
		}

		for(int i = start; i <= end; i++) {
			vector<TreeNode *> leftNodes = generateTreesRecursion(start, i-1);
			vector<TreeNode *> rightNodes = generateTreesRecursion(i+1, end);
			for(int j = 0; j < leftNodes.size(); j++) {
				for(int k = 0; k < rightNodes.size(); k++) {
					TreeNode *cur_root = new TreeNode(i);
					cur_root->left = leftNodes[j];
					cur_root->right = rightNodes[k];
					v.push_back(cur_root);
				}
			}
		}
		return v;
	}

    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> v = generateTreesRecursion(1, n);
        return v;
    }
};