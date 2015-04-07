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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        min_ = numeric_limits<int>::max();
        dfs(root);
        return min_;
    }
private:
    int min_;
    void dfs(TreeNode *root, int depth = 1) {
        if (root == nullptr) return;
        if (isLeaf(root)) {
            if (depth < min_) min_ = depth;
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
