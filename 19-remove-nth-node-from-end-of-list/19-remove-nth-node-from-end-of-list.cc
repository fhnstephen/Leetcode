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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        list_.clear();
        auto backup = head;
        while (head) {
            list_.push_back(head);
            head = head->next;
        }
        int len = list_.size();
        if (n == len) return backup->next;
        list_.at(len - n - 1)->next = list_.at(len - n)->next;
        return backup;
    }
private:
    vector<ListNode*> list_;
};
