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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 0 || k == 1)
        	return head;

        int pass_cnt = 1;
        ListNode *last_node, *next_first, *cur;

        ListNode *myHead = new ListNode(0);
        myHead->next = head;
        last_node = myHead;
        cur = head;

        while(true) {
        	if(cur == NULL)
        		break;

        	ListNode *tmp_next = cur->next;

        	if(pass_cnt < k) {
        		++pass_cnt;
        	} else {
        		next_first = cur->next;
        		
        		ListNode *orig_head, *orig_tail;
        		orig_head = last_node->next;
        		orig_tail = cur;

        		ListNode *t = orig_head->next, *prev_t = orig_head;
        		while(true) {
        			ListNode *tmp_next_inner = t->next;
        			t->next = prev_t;

        			if(t == orig_tail) {
        				break;
        			} else {
        				prev_t = t;
        				t = tmp_next_inner;
        			}
        		}
        		last_node->next = orig_tail;
        		orig_head->next = next_first;

        		last_node = orig_head;

        		pass_cnt = 1;
        	}

        	cur = tmp_next;
        }

        ListNode *retVal = myHead->next;
        delete myHead;

        return retVal;
    }
};
