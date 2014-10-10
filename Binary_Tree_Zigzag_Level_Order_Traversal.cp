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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int> > v;
    	if(root == NULL)
    		return v;

    	queue<TreeNode *> q;
    	bool reverse = false;
    	vector<int> tmp_row;

    	q.push(root);
    	q.push(NULL);

    	while(!q.empty()) {
    		TreeNode *cur = q.front(); q.pop();

    		if(cur != NULL) {
    			tmp_row.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
    			if(cur->right)
                    q.push(cur->right);
    		} else {
                if(reverse) {
                    int i = 0, j = tmp_row.size() - 1;
                    while(i < j) {
                        int tmp = tmp_row[i];
                        tmp_row[i] = tmp_row[j];
                        tmp_row[j] = tmp;
                        i++; j--;
                    }
                }
                v.push_back(tmp_row);
                tmp_row.resize(0);
                reverse = (!reverse);
                if(q.empty())
                    break;
                q.push(NULL);
    		}
    	}

    	return v;
    }
};
