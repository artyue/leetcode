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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
        	return l2;
        if(l2 == NULL)
        	return l1;

        ListNode *cur1 = l1, *cur2 = l2;
     	ListNode *newHead = NULL, *last = NULL;
        int addOne = 0;

        while(cur1 != NULL && cur2 != NULL) {
        	ListNode *now = new ListNode(0);
        	if(newHead == NULL)
        		newHead = now;
        	if(last != NULL)
        		last->next = now;

        	now->val = ((cur1->val + cur2->val) + addOne) % 10;
        	addOne = ((cur1->val + cur2->val) + addOne) / 10;

        	cur1 = cur1->next;
        	cur2 = cur2->next;
        	last = now;
        }

        ListNode *goOn = ((cur1 == NULL) ? cur2 : cur1);

        while(goOn) {
        	ListNode *now = new ListNode(0);
        	now->val = (goOn->val + addOne) % 10;
        	addOne = (goOn->val + addOne) / 10;
        	last->next = now;
        	last = now;
        	goOn = goOn->next;
        }

        if(addOne >= 1) {
        	ListNode *now = new ListNode(1);
        	last->next = now;
        }

        return newHead;
    }
};
