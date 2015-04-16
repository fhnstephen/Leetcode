class Solution {
public:
    int numDecodings(string s) {
        n = s.length();
        if (!n) return 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(dp, s, 0, n - 1);
    }
private:
    int n;
    int dfs(vector<vector<int>> &dp, const string &s, int i, int j) {
        if (i == j) {
          if (s[i] == '0') return 0;
          return 1;
        }
        if (i > j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        int& ret = dp[i][j];
        ret += dfs(dp, s, i + 1, j) * (s[i] == '0' ? 0 : 1);
        if ((i + 1 <= j) && (s.substr(i, 2) <= "26") && (s.substr(i, 2) != "00") && s[i] != '0') ret+= dfs(dp, s, i + 2, j);
        return ret;
    }
};
