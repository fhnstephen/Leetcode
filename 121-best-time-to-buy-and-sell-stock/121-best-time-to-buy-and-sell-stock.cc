class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int ans = 0, minp = numeric_limits<int>::max();
        for (auto x : prices) {
            if (x < minp) minp = x;
            ans = max(ans, x - minp);
        }
        return ans;
    }
};
