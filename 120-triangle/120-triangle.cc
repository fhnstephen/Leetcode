class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp(n, numeric_limits<int>::max());
        dp[0] = 0;
        for (auto& row : triangle) {
            int m = row.size();
            vector<int> temp(dp);
            for (int i = 0; i < m; ++i) {
                if (i) dp[i] = temp[i-1];
                dp[i] = min({dp[i], temp[i]}) + row[i];
            }
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i)
            ans = min(ans, dp[i]);
        return ans;
    }
};
