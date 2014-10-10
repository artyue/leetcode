/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head, *cur, *p1 = l1, *p2 = l2;

		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		
		if(p1->val < p2->val) {
			head = cur = p1;
			p1 = p1->next;
		} else {
			head = cur = p2;
			p2 = p2->next;
		}

		while(true) {
			if(p1 == NULL && p2 == NULL)
				return head;
			if(p1 == NULL) {
				cur->next = p2;
				return head;
			}
			if(p2 == NULL) {
				cur->next = p1;
				return head;
			}
			if(p1->val < p2->val) {
	   		 	cur->next = p1;
				cur = cur->next;
	   		 	p1 = p1->next;
	   		} else {
	   		 	cur->next = p2;
				cur = cur->next;
	   			p2 = p2->next;
	   		}
		}

		return head;
    }
};
