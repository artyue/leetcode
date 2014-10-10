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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if(num.size() == 0)
			return NULL;
		return sortedArrayToBSTRecursive(num, 0, num.size()-1);
    }

	TreeNode *sortedArrayToBSTRecursive(vector<int> &num, int s, int e) {
		if(s == e)
			return (new TreeNode(num[s]));
		if(e - s == 1) {
			TreeNode *ns = new TreeNode(num[s]);
			TreeNode *ne = new TreeNode(num[e]);
			ns->right = ne;
			return ns;
		}
		int mid = (s + e) / 2;
		TreeNode *r = new TreeNode(num[mid]);
		r->left = sortedArrayToBSTRecursive(num, s, mid-1);
		r->right = sortedArrayToBSTRecursive(num, mid+1, e);
		return r;
	}
};
