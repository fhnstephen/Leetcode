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
    void flatten(TreeNode *root) {
        if (!root) return;
        dfs(root);
    }
private:
    TreeNode* dfs(TreeNode* root) {
        if (!root || !root->left && !root->right) return root;
        auto tr = root->right;
        if (!tr) {
            root->right = root->left;
            root->left = nullptr;
            return dfs(root->right);
        }
        if (!root->left) {
            return dfs(tr);
        }
        root->right = root->left;
        auto t = dfs(root->left);
        t->right = tr;
        root->left = nullptr;
        return dfs(tr);
    }
};
