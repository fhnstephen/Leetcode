/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        auto before = head;
        for (int i = 1; i < m - 1; ++i, before = before->next);
        auto ml = m == 1 ? head : before->next, cur = ml->next, last = ml;
        for (int i = 0; i < n - m; ++i) {
            auto temp = cur->next;
            cur->next = last;
            last = cur;
            cur = temp;
        }
        ml->next = cur;
        if (m == 1) head = last; else before->next = last;
        return head;
    }
};
