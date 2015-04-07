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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        max_ = numeric_limits<int>::min();
        dfs(root);
        return max_;
    }

private:
    int max_;
    void dfs(TreeNode *root, int depth = 1) {
        if (root == nullptr) return;
        if (isLeaf(root)) {
            if (depth > max_) max_ = depth;
        }
        else {
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
        }
    }
    bool isLeaf(TreeNode *root) {
        return root->left == root->right && root->left == nullptr;
    }
};
