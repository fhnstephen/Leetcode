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
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        flag = true;
        dfs(root);
        return flag;
    }
private:
    bool flag;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (abs(left - right) > 1) {
            flag = false;
        }
        if (!flag) return -1;
        return max(left, right) + 1;
    }
};
