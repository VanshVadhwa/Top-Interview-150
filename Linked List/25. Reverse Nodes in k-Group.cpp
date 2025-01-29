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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    int length(ListNode* head) {
        int ans = 0;
        while(head) {
            head = head->next;
            ans++;
        }
        return ans;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        int len = length(head);
        if(len < k) return head;

        ListNode* dummy = new ListNode(0,head);
        ListNode* prevGroupEnd = dummy;

        while(len >= k) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = groupStart;

            for(int i=1;i<k;i++) {
                groupEnd = groupEnd->next;
            }

            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = NULL;

            ListNode* newGroupStart = reverse(groupStart);
            prevGroupEnd->next = newGroupStart;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
            len -= k;
        }


        return dummy->next;
    }
};
