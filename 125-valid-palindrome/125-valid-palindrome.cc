class Solution {
public:
    bool isPalindrome(string s) {
        auto l = s.begin(), r = s.end() - 1;
        while (l <= r) {
            while (l <= r && !(isalnum(*l))) ++l;
            while (l <= r && !(isalnum(*r))) --r;
            if (l <= r) {
                char lch = toupper(*l);
                char rch = toupper(*r);
                if (lch != rch) return false;
                ++l, --r;
            }
        }
        return true;
    }
};
