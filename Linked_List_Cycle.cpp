/**
 * Linked List Cycle
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* p = head;
        ListNode* q = head;
        while (q->next && q->next->next) {
            p = p->next;    //slow pointer
            q = q->next->next;    //fast pointer
            if (p == q) return true;    //when they meet then there is a cycle
        }
        return false;
    }
};