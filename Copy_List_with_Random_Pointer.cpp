/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
        	return NULL;

        int size = 1;

        RandomListNode *cur = head;
        while(cur->next) {
    		cur = cur->next;
    		++size;
        }

		RandomListNode *newAdd[size];
		int oldRef[size], oldLabel[size];
		memset(oldRef, -1, sizeof(oldRef));

		cur = head;
		RandomListNode *newHead = NULL, *last = NULL;
		for(int i = 0; i < size; ++i) {
			RandomListNode *newNode = new RandomListNode(cur->label);
			oldLabel[i] = cur->label;
			cur->label = i;
			if(newHead == NULL)
				newHead = newNode;
			else
				last->next = newNode;
			newAdd[i] = newNode;
			last = newNode;
			cur = cur->next;
		}

		cur = head;
		for(int i = 0; i < size; ++i) {
			if(cur->random != NULL)
				oldRef[i] = cur->random->label;
			cur = cur->next;
		}

		cur = head;
		for(int i = 0; i < size; ++i) {
			cur->label = oldLabel[i];
			cur = cur->next;
		}

		cur = newHead;
		for(int i = 0; i < size; ++i) {
			if(oldRef[i] == -1)
				cur->random = NULL;
			else
				cur->random = newAdd[oldRef[i]];
			cur = cur->next;
		}

		return newHead;
    }
};
