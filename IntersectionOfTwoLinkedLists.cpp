/**
 * Write a program to find the node at which the intersection of
 * two singly linked lists begins.
 * For example, the following two linked lists:
 * A:     a1->a2->c1->c2->c3
 * B: b1->b2->b3->c1->c2->c3
 * begin to intersect at node c1.
 * Notes:
 * if the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your codes should preferably run in O(n) time and use only O(1) memory.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * 	int val;
 * 	ListNode *next;
 * 	ListNode(int x):val(x), next(NULL) {}
 * 	};
 */

class IntersectionOfTwoLinkedLists {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		int lenA=0, lenB=0;
		ListNode *tempA=headA, *tempB=headB;
		while (tempA!=NULL) {
			tempA=tempA->next;
			lenA++;
		}
		while (tempB!=NULL) {
			tempB=tempB->next;
			lenB++;
		}
		while (lenA>lenB) {
			headA=headA->next;
			lenA--;
		}
		while (lenB>lenA) {
			headB=headB->next;
			lenB--;
		}
		while (headA!=NULL) {
			if (headA->val==headB->val) {
				return headA;
			}
			else {
				headA=headA->next;
				headB=headB->next;
			}
		}
		return NULL;
	}
};
