class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        dfs(n, n, 0, "");
        return ans;
    }
private:
    vector<string> ans;
    void dfs(int l, int r, int s, string cur = "") {
        if (l <= 0) {
            string temp(r, ')');
            ans.push_back(cur + temp);
            return;
        }
        dfs(l - 1, r, s + 1, cur + '(');
        if (s) dfs(l, r - 1, s - 1, cur + ')');
    }
};
