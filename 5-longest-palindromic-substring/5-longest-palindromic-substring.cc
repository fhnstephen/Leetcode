class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
      bool dp[n+1][n+1];
      memset(dp, 0, sizeof(dp));
      string ans;
      for (int i = 0; i < n; ++i) {
          dp[i][i] = true;
          if (i) dp[i][i-1] = true;
          ans = s[i];
      }

      for (int len = 2; len <= n; ++len)
        for (int i = 0; i < n; ++i) {
            int j = i + len - 1;
            if (j >= n) break;
            dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            if (dp[i][j] && len > ans.length()) {
                ans = s.substr(i, len);
            }
        }

      return ans;
    }
};
