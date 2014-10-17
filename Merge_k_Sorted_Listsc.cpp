/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Compare {
    bool operator() (const ListNode *left, const ListNode *right){
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int list_size = lists.size();
        if (list_size == 0)
            return NULL;

        priority_queue<ListNode *, vector<ListNode *>, Compare> pQ;

        /* Initialize the heap */
        for (int i = 0; i < list_size; ++i) {
            if (lists[i] != NULL) {
                pQ.push(lists[i]);
            }
        }

        ListNode *retHead = NULL, *cur = NULL;
        /* Get the head of the return list */
        if(!pQ.empty()) {
            retHead = pQ.top(); pQ.pop();
            if(retHead->next)
                pQ.push(retHead->next);
            cur = retHead;
        }

        while (!pQ.empty()) {
            ListNode *top = pQ.top(); pQ.pop();
            cur->next = top;
            if (top->next)
                pQ.push(top->next);
            cur = cur->next;
            cur->next = NULL;
        }

        return retHead;
    }
};
