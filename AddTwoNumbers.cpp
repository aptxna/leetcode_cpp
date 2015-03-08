/**
 * Add Two Numbers
 * 
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class AddTwoNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head= new ListNode(-1);
        ListNode *p = head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        
        while (p1 != NULL || p2 != NULL) {
            int val1 = p1==NULL ? 0 : p1->val;
            int val2 = p2==NULL ? 0 : p2->val;
            
            ListNode *digit = new ListNode((val1 + val2 + carry) % 10);
            carry = (val1 + val2 + carry) / 10;
            p->next = digit;
            
            p1 = p1==NULL ? NULL : p1->next;
            p2 = p2==NULL ? NULL : p2->next;
            p = p->next;
        }
        
        if (carry > 0)
            p->next = new ListNode(1);
        
        p = head->next;
        delete head;
        return p;
    }
};