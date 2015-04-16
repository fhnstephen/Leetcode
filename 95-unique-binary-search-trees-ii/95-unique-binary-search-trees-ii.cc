class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n+2, vector<vector<TreeNode*>>(n+2, vector<TreeNode*>(0)));
        if (!n) return vector<TreeNode*>(1, nullptr);
        for (int i = 1; i <= n+1; ++i) {
            dp[i][i].push_back(new TreeNode(i));
            dp[i][i - 1].push_back(nullptr);
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for (int k = i; k <= j; ++k) {
                    for (auto& left : dp[i][k-1]) {
                        for (auto& right : dp[k+1][j]) {
                            auto root = new TreeNode(k);
                            root->left = left;
                            root->right = right;
                            dp[i][j].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};
