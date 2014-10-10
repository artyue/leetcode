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
	ListNode *detectCycle(ListNode *head) {
		if(!head)
			return NULL;

		ListNode *fast, *slow;
		fast = slow = head;
		while(true) {
			slow = slow->next;
			if(!slow)
				return NULL;

			fast = fast->next;
			if(!fast)
				return NULL;
			fast = fast->next;
			if(!fast)
				return NULL;

			if(fast == slow)
				break;
		}
		
		fast = head;
		while(fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
