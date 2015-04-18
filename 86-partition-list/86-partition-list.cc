class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        auto cur1 = h1, cur2 = h2;
        while (head) {
            int val = head->val;
            if (val < x) {
                cur1->next = head;
                cur1 = head;
            }
            else {
                cur2->next = head;
                cur2 = head;
            }
            head = head->next;
        }
        cur1->next = h2->next;
        cur2->next = nullptr;
        return h1->next;
    }
};
