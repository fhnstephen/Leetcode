class Solution {
public:
    int maxProfit(vector<int> &prices) {
        array<int, 2> dp{0, numeric_limits<int>::min()};
        for (auto x : prices) {
            int t0 = dp[0], t1 = dp[1];
            dp[0] = max(t0, t1 + x);
            dp[1] = max(t1, t0 - x);
        }
        return max(dp[0], dp[1]);
    }
};
