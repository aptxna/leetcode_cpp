/**
 * Given a linked list, remove the Nth node frome the end of the list
 * and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n=2.
 * After removing the second node from the end,
 * the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 * 	int val;
 * 	ListNode *next;
 * 	ListNode(int x): val(x), next(NULL) {}
 * 	}
 */

class RemoveNthNodeFromEndOfList {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode* pre=head;
		ListNode* cur=head;
		assert(head);
		while (n) {
			cur = cur->next;
			n--;
		}

		if (cur==NULL) {
			head = head->next;
			delete pre;
			return head;
		}

		while (cur->next != NULL) {
			pre = pre->next;
			cur = cur->next;
		}

		ListNode* temp = pre->next;
		pre->next = temp->next;
		delete temp;
		return head;
	}
};
