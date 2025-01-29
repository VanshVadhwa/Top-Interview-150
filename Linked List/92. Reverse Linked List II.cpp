/**
 * Definition for singly-linked list.
 * struct ListNode {gm
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;

        for(int i=1;i<left;i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next, *forward = nullptr;

        for(int i=0;i<right-left;i++) {
            forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
