class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            char next = n % 26 == 0 ? 'Z' : 'A' + n % 26 - 1;
            n = n % 26 == 0 ? n / 26 - 1 : n / 26;
            ans += next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
