class Solution {
public:
    /* This function returns the max value of one tree rooted by *cur. */
    int maxPathSumRecursion(TreeNode *cur, int &cur_max) {
        if (!cur)
            return 0;
        
        int l_tree = maxPathSumRecursion(cur->left, cur_max);
        int r_tree = maxPathSumRecursion(cur->right, cur_max);
        cur_max = max(cur_max,
                      max(cur->val,
                          max(cur->val + l_tree,
                              max(cur->val + r_tree,
                                  cur->val + l_tree + r_tree)))
                      );
        return max(cur->val, cur->val + max(l_tree, r_tree));
    }
    
    int maxPathSum(TreeNode *root) {
        int res = 0;
        if (!root)
            return res;
        
        res = root->val;
        maxPathSumRecursion(root, res);
        return res;
    }
};
