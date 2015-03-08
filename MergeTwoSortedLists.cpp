/**
 * Merge Two Sorted Lists
 * 
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 	};
 */

 class MergeTwoSortedLists {
 public:
 	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
 		ListNode *head = new ListNode(-1);
 		ListNode *p = head;

 		while (l1 != NULL || l2 != NULL) {
 			int val1 = l1==NULL ? INT_MAX : l1->val;
 			int val2 = l2==NULL ? INT_MAX : l2->val;

 			if (val1 <= val2) {
 				p->next = l1;
 				l1 = l1->next;
 			}
 			else {
 				p->next = l2;
 				l2 = l2->next;
 			}

 			p = p->next;
 		}

 		p = head->next;
 		delete head;
 		return p;
 	}
 };