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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (!root) return ans;
        vector<int> temp;
        temp.push_back(root->val);
        dfs(root, sum - root->val, temp);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int cur, vector<int>& path) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (cur == 0) ans.push_back(path);
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            dfs(root->left, cur - root->left->val, path);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            dfs(root->right, cur - root->right->val, path);
            path.pop_back();
        }
    }
};
