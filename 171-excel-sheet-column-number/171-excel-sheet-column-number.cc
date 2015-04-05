class Solution {
public:
    int titleToNumber(string s) {
        unsigned long ans = 0;
        for (auto x : s) {
            ans = ans * 26 + x - 'A' + 1;
        }
        return ans;
    }
};
