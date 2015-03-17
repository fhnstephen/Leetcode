class Solution {
public:
    int maxProfit_inf(vector<int> &prices) {
      int def_val = -(1 << 30);
      array<int, 2> dp({def_val, def_val});
      dp[0] = 0;
      int ans = 0;
      for (int x : prices) {
          dp[1] = max(dp[0] - x, dp[1]);
          dp[0] = max(dp[0], dp[1] + x);
          ans = max(ans, dp[1]);
          ans = max(ans, dp[0]);
      }
      return ans;
    }
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;
        if (k >= n / 2) return maxProfit_inf(prices);
        int ans = 0;
        auto iter = begin(prices);
        stack<pair<int, int>> s;
        vector<int> profits;
        while (iter != end(prices)) {
          int max_price = 0, min_price = numeric_limits<int>::max();
          while (iter != end(prices) && *iter < min_price) {
            min_price = *iter;
            ++iter;
          }
          while (iter != end(prices) && *iter > max_price) {
            max_price = *iter;
            ++iter;
          }
          if (max_price < min_price) break;
          // case 1
          while (!s.empty() && min_price <= (s.top().first)) {
            profits.push_back(s.top().second - s.top().first);
            s.pop();
          }

          // case 2
          while (!s.empty() && max_price >= (s.top().second)) {
            profits.push_back(s.top().second - min_price);
            min_price = s.top().first;
            s.pop();
          }
          cout << min_price << " " << max_price << endl;
          s.push(make_pair(min_price, max_price));
        }
        while (!s.empty()) {
          profits.push_back(s.top().second - s.top().first);
          s.pop();
        }

        if (k >= profits.size()) {
          for (int x : profits) {
            ans += x;
          }
        }
        else {
          sort(begin(profits), end(profits));
          for (auto i = profits.rbegin(); i != profits.rend(); ++i) {
            cout << *i << endl;
            ans += *i;
            k--;
            if (!k) break;
          }
        }
        return ans;
    }
};
