/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SortList {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        else {
            ListNode *fast = head, *slow = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            
            fast = sortList(head);
            slow = sortList(slow);
            return merge(fast,slow);
        }
    }
    
    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode *p, *res;
        if (h1->val < h2->val) {
            res = h1;
            h1 = h1->next;
        }
        else {
            res = h2;
            h2 = h2->next;
        }
        p = res;
        
        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            }
            else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        
        if (h1 != NULL) p->next = h1;
        else if (h2 != NULL) p->next = h2;
        return res;
    }
};