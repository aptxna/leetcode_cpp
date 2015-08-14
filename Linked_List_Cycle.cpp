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
 *
 * 用快慢指针或者hashset
 * 把扫过的结点放入haset，重复则返回true
 * 不过这里要求不用extra space，用快慢指针
 * 慢指针每次向前一步，快指针每次向前两步，两指针相遇则返回true
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