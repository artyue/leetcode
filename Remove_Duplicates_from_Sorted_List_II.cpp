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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
        	return head;

        ListNode *myHead = new ListNode(INT_MIN);
        myHead->next = NULL;
        ListNode *prev = myHead, *cur = head, *myHead_tail = myHead;

        while(true) {
        	ListNode *next = cur->next;
        	if(prev->val != cur->val) {
        		if(next == NULL || cur->val != next->val) {
        			myHead_tail->next = cur;
        			myHead_tail = myHead_tail->next;
        			myHead_tail->next = NULL;
        		}
        	}

        	if(next == NULL)
        		break;

        	prev = cur;
        	cur = next;
        }

        ListNode *retVal = myHead->next;
        delete myHead;
        return retVal;
    }
};