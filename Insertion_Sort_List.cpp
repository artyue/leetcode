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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
        	return head;

        ListNode *cur = head->next, *cur_next;
        head->next = NULL;

        while(true) {
            cur_next = cur->next;

            /* Insert the cur-node into the new sorted Linked-List */
            if(cur->val <= head->val) {
                cur->next = head;
                head = cur;
            } else {
                ListNode *prev = head, *prev_next = head->next;
                bool midInsert = false;
                while(prev_next != NULL) {
                    if(prev->val < cur->val && cur->val <= prev_next->val) {
                        prev->next = cur;
                        cur->next = prev_next;
                        midInsert = true;
                        break;
                    } else {
                        prev = prev_next;
                        prev_next = prev_next->next;
                    }
                }
                
                /* The cur-node should be inserted into the tail of the new Linked-List. */
                if(!midInsert) {
                    prev->next = cur;
                    cur->next = NULL;
                }
            }

            cur = cur_next;
            if(cur == NULL)
                break;
        }

        return head;
    }
};
