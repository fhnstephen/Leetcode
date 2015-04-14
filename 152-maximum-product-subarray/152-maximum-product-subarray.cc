class Solution {
public:
    int maxProduct(int A[], int n) {
      if (!n) return 0;
      if (n == 1) return A[0];
      auto& a = A;
      array<long, 2> dp{1, 1};
      long ans = numeric_limits<long>::min();
      for (int i = 0; i < n; ++i) {
        int x = a[i];
        auto t1 = dp[0], t2 = dp[1];
        if (x < 0) {
          if (t2 < 0) {
            dp[0] = t2 * x;
            dp[1] = t1 * x;
            ans = max(ans, dp[0]);
          }
          else {
            dp[0] = 1;
            dp[1] = t1 * x;
            ans = max(ans, dp[1]);
          }
        }
        else if (x > 0) {
          dp[0] = dp[0] * x;
          dp[1] = dp[1] < 0 ? dp[1] * x : 1;
          ans = max(ans, dp[0]);
        }
        else {
          dp[0] = 1;
          dp[1] = 1;
          ans = max(ans, 0L);
        }
      }
      return ans;
    }
};
