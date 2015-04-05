class Solution {
public:
    string countAndSay(int n) {
        string ans{"1"};
        for (int i = 1; i < n; ++i) {
            int cnt = 0;
            string next{""};
            auto l = ans.begin();
            while (l != ans.end()) {
              char res = *l;
              while (l != ans.end() && *l == res) ++l, ++cnt;
              next += cnt + 48;
              next += res;
              cnt = 0;
            }
            ans = next;
        }
        return ans;
    }
};
