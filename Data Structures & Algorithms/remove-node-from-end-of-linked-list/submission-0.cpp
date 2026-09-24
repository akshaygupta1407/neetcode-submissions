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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = dummy;
        for(int i=0; i<n; i++) {
            curr = curr->next;
        }
        head = dummy;
        while(curr->next!=NULL) {
            curr = curr->next;
            head = head->next;
        }
        head->next = head->next->next;
        return dummy->next;
    }
};