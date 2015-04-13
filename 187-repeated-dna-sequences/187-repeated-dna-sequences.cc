class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        hash<string> h;
        vector<string> ans;
        for (int i = 0; i + 10 <= n; ++i) {
            auto str = s.substr(i, 10);
            auto& x = m[h(str)];
            if (x <= 2) x++;
            if (x == 2) ans.push_back(str);
        }
        return ans;
    }
private:
    unordered_map<int, char> m;
};
