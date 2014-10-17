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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        /* Get the size of the linkedlist */
        int size = 0;
        ListNode *cur = head;
        while (cur) {
            ++size;
            cur = cur->next;
        }

        ListNode *newHead = head, *prev;
        int subLen = 1;
        while (subLen < size) {
            
            cur = newHead; prev = NULL; 
            newHead = NULL;
            while (cur) {
                ListNode *l1 = cur, *l2 = NULL;
                /* Find l2's head */
                int ct = 0;
                while (ct < subLen && cur->next) {
                    ++ct;
                    cur = cur->next;
                }
                if (ct < subLen)
                    break;
                else
                    l2 = cur;
                
                /* find the next prev */
                ct = 1;
                while (ct++ < subLen && cur->next) {
                    cur = cur->next;
                }
                cur = cur->next;
                /* Merge l1 and l2 */
                ListNode *mergedHead = NULL, *p = NULL;
                int l1_ct = 0, l2_ct = 0;
                while (l1_ct < subLen && l2_ct < subLen && l1 && l2) {
                    ListNode *tmp = NULL;
                    if (l1->val < l2->val) {
                        tmp = l1;
                        l1 = l1->next;
                        ++l1_ct;
                    } else {
                        tmp = l2;
                        l2 = l2->next;
                        ++l2_ct;
                    }
                    if (!mergedHead) {
                        mergedHead = (p = tmp);
                    } else {
                        p->next = tmp;
                        p = p->next;
                    }
                }
                ListNode *next_prev;
                if (l1_ct < subLen && l1) {
                    p->next = l1;
                    while (l1_ct < subLen && p->next) {
                        ++l1_ct;
                        p = p->next;
                    }
                } else if (l2_ct < subLen && l2) {
                    p->next = l2;
                    while (l2_ct < subLen && p->next) {
                        ++l2_ct;
                        p = p->next;
                    }
                }
                next_prev = p;
                p->next = cur;
                if (!newHead)
                    newHead = mergedHead;
                if (prev)
                    prev->next = mergedHead;
                prev = next_prev;
            }

            subLen *= 2;
        }
        return newHead;
    }
};
