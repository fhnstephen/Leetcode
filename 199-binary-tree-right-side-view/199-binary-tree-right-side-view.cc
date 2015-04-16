class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        auto divider = nullptr;
        q.push(root);
        q.push(divider);
        vector<int> temp;
        while (!q.empty()) {
            auto head = q.front();
            q.pop();
            if (head == divider) {
                if (!q.empty()) q.push(divider);
                ans.push_back(*temp.rbegin());
            }
            else {
                temp.push_back(head->val);
                if (head->left) q.push(head->left);
                if (head->right) q.push(head->right);
            }
        }
        return ans;
    }
};
