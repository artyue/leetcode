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
	TreeNode *buildTreeRecursion(int in_s, int in_e, int post_i,
							     vector<int> &inorder, vector<int> &postorder) {
		if(in_s > in_e)
			return NULL;
		
		int root_val = postorder[post_i];
		int p = in_s;
        for(; p <= in_e; ++p) {
        	if(inorder[p] == root_val) {
        		break;
        	}
        }
        int l_in_s = in_s, l_in_e = p - 1, r_in_s = p + 1, r_in_e = in_e;
        int l_size = l_in_e - l_in_s + 1,
        	r_size = r_in_e - r_in_s + 1;
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTreeRecursion(l_in_s, l_in_e, post_i-r_size-1, inorder, postorder);
        root->right = buildTreeRecursion(r_in_s, r_in_e, post_i-1, inorder, postorder);
        return root;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        if(size == 0)
        	return NULL;

        int root_val = postorder[size-1];
        int p = 0;
        for(; p < size; ++p) {
        	if(inorder[p] == root_val) {
        		break;
        	}
        }
        int l_in_s = 0, l_in_e = p - 1, r_in_s = p + 1, r_in_e = size - 1;
        int l_size = p, r_size = size - 1 - p;
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTreeRecursion(l_in_s, l_in_e, (size-1)-r_size-1, inorder, postorder);
        root->right = buildTreeRecursion(r_in_s, r_in_e, (size-1)-1, inorder, postorder);
        return root;
    }
};

