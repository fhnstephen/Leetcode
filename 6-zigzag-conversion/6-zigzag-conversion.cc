class Solution {
public:
    string convert(string s, int nRows) {
        // if nRows == 1, k = 0, program will run forever
        if (nRows == 1) return s;
        int k = 2 * (nRows - 1);
        string ans;
        int n = s.length();
        for (int i = 0; i < nRows && i < n; ++i) {
          ans += s[i];
          for (int delta = k; ; delta += k) {
            if (i > 0 && i < nRows - 1) {
              int mid = delta - i;
              if (mid >= n) break;
              ans += s[mid];
            }
            int cur = delta + i;
            if (cur >= n) break;
            ans += s[cur];
          }
        }
        return ans;
    }
};
