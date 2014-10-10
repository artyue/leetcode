/**
 ** Definition for binary tree with next pointer.
 ** struct TreeLinkNode {
 **  int val;
 **  TreeLinkNode *left, *right, *next;
 **  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 ** };
 **/
class Solution {
public:
    void connect(TreeLinkNode *root) {
		connectRecursive(root);
    }

	void connectRecursive(TreeLinkNode *cur) {
		if(cur == NULL)
			return;

		if(cur->left != NULL) {
			cur->left->next = cur->right;
			connectRecursive(cur->left);
			connectRecursive(cur->right);
		} else {
			return;
		}

		if(cur->left->left != NULL) {
			TreeLinkNode *nl, *nr;
			nl = cur->left->right;
			nr = cur->right->left;
			while(true) {
				nl->next = nr;
				if(nl->right != NULL) {
					nl = nl->right;
					nr = nr->left;
				} else {
					break;
				}
			}
		}
	}
};
