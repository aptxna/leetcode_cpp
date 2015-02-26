/**
 * Definition for singly-linked list.
 * struct ListNode {
 * 	int val;
 * 	ListNode *next;
 * 	ListNode(int x): val(x), next(NULL) {}
 * };
 */
class RDfSL {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;
		ListNode *pre = head, *p = head->next;
		while (p != NULL) {
			if (pre->val < p->val) {
				pre = p;
				p = p->next;
			}
			else {
				pre->next = p->next;
				p = p->next;
			}
		}
		return head;
	}
};
