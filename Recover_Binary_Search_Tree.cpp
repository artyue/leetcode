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
	void inOrderTraverse(TreeNode *node, vector<TreeNode *> &nodes, vector<int> &values) {
		if(node != NULL) {
			inOrderTraverse(node->left, nodes, values);
			nodes.push_back(node);
			values.push_back(node->val);
			inOrderTraverse(node->right, nodes, values);
		}
	}

    void recoverTree(TreeNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
        	return;

        vector<TreeNode *> nodes;
        vector<int> values;

        inOrderTraverse(root, nodes, values);
        sort(values.begin(), values.end());
        for(int i = 0; i < nodes.size(); ++i) {
        	nodes[i]->val = values[i];
        }
    }
};
