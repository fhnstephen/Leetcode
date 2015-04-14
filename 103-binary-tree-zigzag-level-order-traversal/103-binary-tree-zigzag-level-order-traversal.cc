class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> cur;
        while (!q.empty()) {
          auto head = q.front();
          q.pop();
          if (!head) {
            if (!q.empty())
              q.push(nullptr);
            if ((ans.size() & 1) == 0)
              ans.push_back(cur);
            else {
              reverse(cur.begin(), cur.end());
              ans.push_back(cur);
            }
            cur.clear();
          }
          else {
            if (head->left) q.push(head->left);
            if (head->right) q.push(head->right);
            cur.push_back(head->val);
          }
        }
        return ans;
    }
};
