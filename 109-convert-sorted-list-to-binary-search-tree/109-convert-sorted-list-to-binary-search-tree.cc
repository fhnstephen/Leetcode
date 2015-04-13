class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        auto fast = head, slow = head, pre = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
