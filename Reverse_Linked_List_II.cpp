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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n)
        	return head;

        int cnt = 0;
        ListNode *pre_head = new ListNode(0), *cur = pre_head, *pre_m = NULL;
        pre_head->next = head;

        while(true) {
        	if(cnt + 1 == m) {
        		if(pre_m == NULL) {
        			pre_m = cur;
        		}
        	}
        	if(cnt >= n)
        		break;

        	if(cnt >= m && cnt < n) {
        		ListNode *tmp = cur->next;
        		cur->next = cur->next->next;
        		tmp->next = pre_m->next;
        		pre_m->next = tmp;
        	}

        	if(cnt < m) {
        		cur = cur->next;
        	}

        	++cnt;
        }

        ListNode *ret = pre_head->next;
        delete pre_head;
        return ret;
    }
};