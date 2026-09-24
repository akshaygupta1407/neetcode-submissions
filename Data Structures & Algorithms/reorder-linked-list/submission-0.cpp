/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *curr = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL;

        while(curr) {
            ListNode *newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }

        ListNode *p1 = head, *p2 = prev;

        while(p2) {
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;

            p1->next = p2;
            p2->next = temp1;

            p1 = temp1;
            p2 = temp2;
        }
    }
};
