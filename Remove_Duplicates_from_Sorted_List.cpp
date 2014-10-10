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
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return head;

		ListNode *cur = head;

		while(true) {
			if(cur->next == NULL)
				return head;

			if(cur->next->val == cur->val) {
				cur->next = cur->next->next;
				continue;
			} else {
				cur = cur->next;
			}
		}
    }
};
