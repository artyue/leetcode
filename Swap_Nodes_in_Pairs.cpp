/**
    * Definition for singly-linked list.
	** struct ListNode {
	**     int val;
	**     ListNode *next;
	**     ListNode(int x) : val(x), next(NULL) {}
	** };
	**/
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if(head == NULL)
			return NULL;
		if(head->next == NULL)
			return head;

		ListNode *tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		head = tmp;

		ListNode *cur = head->next;
		while(true) {
			if(cur->next == NULL)
				break;
			ListNode *n1, *n2;
			n1 = cur->next;
			n2 = cur->next->next;
			if(n2 == NULL)
				break;
			cur->next = n2;
			n1->next = n2->next;
			n2->next = n1;
			cur = cur->next->next;
		}
		return head;
    }
};
