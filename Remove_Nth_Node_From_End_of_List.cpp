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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head, *slow = head, *slow_pre = head;
        int cnt = 0;
        
        while(cnt < n - 1) {
            fast = fast->next;
            cnt++;
        }
        
        bool sp_start = false;
        while(true) {
            if(fast->next == NULL) {
                if(slow == head) {
                    return (head = slow->next);
                } else {
                    slow_pre->next = slow->next;
                    return head;
                }
            }
            
            fast = fast->next;
            slow = slow->next;
            if(sp_start == false)
                sp_start = true;
            else
                slow_pre = slow_pre->next;
        }
    }
}; 
