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
    
    bool hasPathSumRecursive(TreeNode *cur, int pre_sum, int target_sum) {
        if(cur->left == NULL && cur->right == NULL) {
            if(pre_sum + cur->val == target_sum)
                return true;
            return false;
        }
        
        bool left = false, right = false;
        if(cur->left != NULL)
            left = hasPathSumRecursive(cur->left, pre_sum+cur->val, target_sum);
            
        if(cur->right != NULL)
            right = hasPathSumRecursive(cur->right, pre_sum+cur->val, target_sum); 
        
        return (left || right);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        return hasPathSumRecursive(root, 0, sum);
    }
};
