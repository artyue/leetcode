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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL || (head != NULL && head->next == NULL))
        	return head;

        ListNode *insert_pointer = NULL, *cur = head;

        while(cur->next != NULL) {
        	/* find the insert pointer: cur */
        	if(insert_pointer == NULL && cur->val < x && cur->next->val >= x) {
 				insert_pointer = cur;   
 				cur = cur->next; 
 				continue; 		
        	}

        	/* cur->next is the node that should be moved forward */
        	if(cur->val >= x && cur->next->val < x) {
        		ListNode *t = cur->next;
        		cur->next = t->next;
        		if(insert_pointer == NULL) {
        			t->next = head;
        			head = t;
        		} else {
        			t->next = insert_pointer->next;
        			insert_pointer->next = t;
        		}
        		insert_pointer = t;
        		continue;
        	}

        	/* other cases */
        	cur = cur->next; 
        }

        return head;
    }
};




























