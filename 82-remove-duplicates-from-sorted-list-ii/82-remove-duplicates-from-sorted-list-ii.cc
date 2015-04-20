class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        auto fake = new ListNode(~head->val);
        fake->next = head;
        auto before = fake;
        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val)
                    head = head->next;
                before->next = head->next;
                head = head->next;
            }
            else {
                before = head;
                head = head->next;
            }
        }
        return fake->next;
    }
};
