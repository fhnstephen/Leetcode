class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        dfs(s, 0, 0, "");
        return ans;
    }
private:
    vector<string> ans;
    int n;
    void dfs(const string &s, int x, int k, string cur) {
        if (x >= n) {
            if (k == 4) ans.push_back(cur);
            return;
        }
        if (k == 4) return;
        string temp = "";
        for (int i = x; i < n; ++i) {
            temp += s[i];
            int num = stoi(temp);
            if (num > 255) break;
            if (temp[0] == '0' && temp.length() > 1) break;
            dfs(s, i + 1, k + 1, cur.length() == 0 ? temp : cur + "." + temp);
        }
    }
};
