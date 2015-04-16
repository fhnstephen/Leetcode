class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        n = S.size();
        vector<int> temp;
        dfs(S, 0, temp);
        return ans;
    }
private:
    int n;
    vector<vector<int>> ans;
    void dfs(vector<int> &s, int x, vector<int>& cur) {
        if (x == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = x; i < n; ++i) {
            if (i == x || s[i] != s[i - 1]) {
                cur.push_back(s[i]);
                dfs(s, i + 1, cur);
                cur.pop_back();
            }
        }
        dfs(s, n, cur);
     }
};
