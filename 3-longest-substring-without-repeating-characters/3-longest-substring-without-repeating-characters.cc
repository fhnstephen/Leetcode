class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0, len = s.length();
        unordered_set<char> hash;
        while (r < len) {
          char ch = s[r];
          if (hash.count(ch) > 0) {
            ans = max(ans, r - l);
            do {
              hash.erase(s[l]);
              ++l;
            } while (l != r && hash.count(ch) > 0);
          }
          hash.insert(ch);
          ++r;
        }
        return max(ans, r - l);
    }
};
