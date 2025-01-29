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
private:
    int getLength(ListNode* node) {
        int ans = 0;
        while(node) {
            ans += 1;
            node = node->next;
        }
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = getLength(head);
        k = k%n;
        if(k==0) return head;

        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy, *curr = dummy;
        while(k--) {
            curr = curr->next;
        }

        while(curr->next) {
            prev = prev->next;
            curr = curr->next;
        }

        ListNode* newHead = prev->next;
        prev->next = nullptr;
        curr->next = dummy->next;

        return newHead;
    }
};
