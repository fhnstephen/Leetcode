class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        dp = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i) dp[i][i-1] = true;
        }
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            }
        dfs(s, 0, vector<string>());
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    int n;
    void dfs(string &s, int x, vector<string> cur) {
        if (x >= n) {
            ans.push_back(cur);
            return;
        }
        for (int i = x; i < n; ++i) {
            if (dp[x][i]) {
                cur.push_back(s.substr(x, i - x + 1));
                dfs(s, i + 1, cur);
                cur.pop_back();
            }
        }
    }
};
