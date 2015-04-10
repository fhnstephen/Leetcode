class Solution {
public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        s = &digits;
        ans.clear();
        dfs(0);
        return ans;
    }
private:
    const string kReps[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string *s;
    int n;
    vector<string> ans;
    void dfs(int x, string cur = "") {
        if (x >= n) {
            if (cur.length())
                ans.push_back(cur);
            return;
        }
        auto rep = kReps[s->at(x) - 48];
        auto len = rep.length();
        for (int i = 0; i < len; ++i) {
            cur += rep[i];
            dfs(x+1, cur);
            cur.erase(cur.end() - 1);
        }
    }
};
