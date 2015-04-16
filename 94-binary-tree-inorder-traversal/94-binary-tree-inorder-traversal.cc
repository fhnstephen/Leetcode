class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }
private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};
