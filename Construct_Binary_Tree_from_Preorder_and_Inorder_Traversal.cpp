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
	TreeNode *buildTreeRecursion(int in_s, int in_e, int pre_pos, 
								 vector<int> &preorder, vector<int> &inorder) {
		if(in_s > in_e)
			return NULL;

		int cur_root_val = preorder[pre_pos];
		int crp = in_s;
		for(; crp <= in_e; ++crp) {
			if(inorder[crp] == cur_root_val) {
				break;
			}
		}
		TreeNode *cur_root = new TreeNode(cur_root_val);
		int l_in_s = in_s, l_in_e = crp - 1, r_in_s = crp + 1, r_in_e = in_e;
        int l_size = l_in_e - l_in_s + 1;
		cur_root->left = buildTreeRecursion(l_in_s, l_in_e, pre_pos+1, preorder, inorder);
		cur_root->right = buildTreeRecursion(r_in_s, r_in_e, pre_pos+l_size+1, preorder, inorder);
		return cur_root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = preorder.size();
        if(size == 0)
        	return NULL;

        int root_val = preorder[0];
        int rp = 0;
        for(; rp < size; ++rp) {
        	if(inorder[rp] == root_val) {
        		break;
        	}
        }
        int l_in_s = 0, l_in_e = rp - 1, r_in_s = rp + 1, r_in_e = size - 1;
        int l_size = rp;
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTreeRecursion(l_in_s, l_in_e, 1, preorder, inorder);
        root->right = buildTreeRecursion(r_in_s, r_in_e, rp+1, preorder, inorder);;
        return root;
    }
};