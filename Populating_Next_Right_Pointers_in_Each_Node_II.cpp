/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		TreeLinkNode* cur_root = root;
		
		while(cur_root != NULL) {
            TreeLinkNode *pre = NULL, *cur = NULL, *next_root = NULL;
            
            for(; cur_root != NULL; cur_root = cur_root->next) { // 对每一层上的节点进行遍历                 
                if(next_root == NULL) {
                    if(cur_root->left != NULL)
                        next_root = cur_root->left;
                    else if(cur_root->right != NULL)
                        next_root = cur_root->right;
                }
                
                if(cur_root->left != NULL) {
                    cur = cur_root->left;
                    if(pre != NULL)
                        pre->next = cur;    
                    pre = cur;    
                }
                if(cur_root->right != NULL) {
                    cur = cur_root->right;
                    if(pre != NULL)
                        pre->next = cur;    
                    pre = cur;    
                }
            }
            
            cur_root = next_root;
        }
    }
};
