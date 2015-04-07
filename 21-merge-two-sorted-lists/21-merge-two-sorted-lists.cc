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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ans = nullptr, *root = nullptr;
        while (l1 || l2) {
            ListNode *&smaller = valOf(l1) < valOf(l2) ? l1 : l2;
            if (ans) {
                ans -> next = smaller;
                ans = smaller;
                smaller = smaller->next;
            }
            else {
                ans = smaller;
                root = ans;
                smaller = smaller->next;
            }
        }
        return root;
    }
private:
    int valOf(ListNode *l) {
        if (l) return l->val;
        else   return numeric_limits<int>::max();
    }
};
