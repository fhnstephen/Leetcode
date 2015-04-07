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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        dfs(root, sum, 0);
    }
private:
    bool dfs(TreeNode *root, int sum_to_find, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr)
          if (sum + root->val == sum_to_find) return true;
          else                    return false;
        return dfs(root->left, sum_to_find, sum + root->val) || dfs(root->right, sum_to_find, sum + root->val);
    }
};
