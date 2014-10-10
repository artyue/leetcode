/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void sortedListToBSTRecursive(int arr[], int s, int e, TreeNode **cur_root_add) {
        if(s > e)   return;
        int mid = s + (e - s) / 2;
        *cur_root_add = new TreeNode(arr[mid]);
        sortedListToBSTRecursive(arr, s, mid-1, &((*cur_root_add)->left));
        sortedListToBSTRecursive(arr, mid+1, e, &((*cur_root_add)->right));
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return NULL;
            
        int last = -1, arr[999999];
        ListNode *cur = head;
        while(cur != NULL) {
            arr[++last] = cur->val;
            cur = cur->next;
        }
        
        TreeNode *root;
        sortedListToBSTRecursive(arr, 0, last, &root);
        return root;
    }
};