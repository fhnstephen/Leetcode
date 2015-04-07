class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        array<int, 2> dp{0, 0};
        if (n == 0) return 0;
        dp[1] = num[0];
        for (int i = 1; i < n; ++i) {
            array<int, 2> l;
            copy(dp.begin(), dp.end(), l.begin());
            dp[0] = max(l[1], l[0]);
            dp[1] = l[0] + num[i];
        }
        return max(dp[0], dp[1]);
    }
};
