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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy, *curr = head;

        while(curr) {
            bool flag = false;
            while(curr->next && curr->val == curr->next->val) {
                curr = curr->next;
                flag = true;
            }
            if(flag) {
                curr = curr->next;
                prev->next = nullptr;
                continue;
            } 
            prev->next = curr;
            prev = prev->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
