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
    ListNode *deleteDuplicates(ListNode *head) {
        auto left = head, right = head;
        while (right) {
            while (right && right->val == left->val) right = right->next;
            left->next = right;
            left = right;
            if (right) right = right->next;
        }
        return head;
    }
};
