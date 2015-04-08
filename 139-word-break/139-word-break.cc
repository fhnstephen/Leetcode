class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i = 0; i < n - 1; ++i)
            dp[i+1][i] = true;
        for (int i = 0; i < n; ++i) {
            string temp;
            for (int j = i; j < n; ++j) {
                temp += s[j];
                if (dict.count(temp))
                    dp[i][j] = true;
            }
        }
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i + len;
                if (j >= n) break;
                if (dp[i][j]) continue;
                for (int k = i; k < j; ++k)
                    dp[i][j] = dp[i][j] || (dp[i][k] && dp[k+1][j]);
            }
        }
        return dp[0][n - 1];
    }
};
