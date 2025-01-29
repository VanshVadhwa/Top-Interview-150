class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); 
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
