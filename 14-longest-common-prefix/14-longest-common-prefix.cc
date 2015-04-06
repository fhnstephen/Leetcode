class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans{""};
        if (strs.empty()) return ans;
        auto maxlen = strs[0].length();
        for (auto& x : strs) {
            maxlen = min(maxlen, x.length());
        }
        for (int i = 0; i < maxlen; ++i) {
            char res = strs[0][i];
            bool flag = all_of(strs.begin(), strs.end(), [&] (string& x) {
               return x[i] == res; 
            });
            if (flag) ans += res;
            else break;
        }
        return ans;
    }
};
