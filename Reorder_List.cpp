class Solution {
public:
    ListNode *reverseList (ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
    
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        /* Get list's size */
        int size = 0;
        ListNode *cur = head;
        do {
            ++size;
            cur = cur->next;
        } while(cur);
        
        /* Slpit the original list into two halves */
        int half = size / 2;
        cur = head;
        int ct = 0;
        do {
            cur = cur->next;
        } while (++ct < half - 1);
        ListNode *second_list = reverseList(cur->next);
        cur->next = NULL;
        
        /* Merge */
        ListNode *first_list = head->next;
        cur = head;
        cur->next = second_list;
        second_list = second_list->next;
        cur = cur->next;
        while (first_list && second_list) {
            cur->next = first_list;
            first_list = first_list->next;
            cur = cur->next;
            cur->next = second_list;
            second_list = second_list->next;
            cur = cur->next;
        }
        if (first_list)
            cur->next = first_list;
        else if (second_list)
            cur->next = second_list;
    }
};
