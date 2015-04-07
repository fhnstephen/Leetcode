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
    bool isSymmetric(TreeNode *root) {
        return dfs(root, root);
    }
private:
    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left || !right) {
            if (left == right) return true;
            else               return false;
        }
        if (left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
