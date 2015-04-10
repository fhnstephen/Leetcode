/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        ans = 0;
        dfs(root);
        return ans;
    }
private:
    int ans;
    void dfs(TreeNode *cur, int val = 0) {
        if (!cur) return;
        val = val*10 + cur->val;
        if (cur->left == cur->right && cur->left == nullptr) {
            ans += val;
            return;
        }
        dfs(cur->left, val);
        dfs(cur->right, val);
    }
};
