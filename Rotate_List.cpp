/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        /* Get the length of the list */
        int size = 0;
        ListNode *cur = head;
        do {
            ++size;
            cur = cur->next;
        } while (cur);
        
        k %= size;

        /* Rotate the list */
        int cur_index = 0, new_head_prev = size - k - 1;
        cur = head;
        while (cur_index < new_head_prev) {
            cur = cur->next;
            ++cur_index;
        }
        ListNode *prev = cur;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        head = prev->next;
        prev->next = NULL;

        return head;
    }
};
