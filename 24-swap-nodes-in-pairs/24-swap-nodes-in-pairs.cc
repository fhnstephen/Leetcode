class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        ListNode* cur = head;
        if (!cur->next) return cur;
        ListNode* root = cur->next;
        ListNode* next = root->next;
        root->next = cur;
        ListNode* last = cur;
        cur = next;
        while (cur && cur->next) {
            ListNode* temp = cur->next->next;
            cur->next->next = cur;
            last->next = cur->next;
            last = cur;
            cur = temp;
        }
        last->next = cur;
        return root;
    }
};
