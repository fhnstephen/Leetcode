class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int n = 0, temp = x;
        while (temp != 0) {
            temp = temp / 10;
            n++;
        }
        for (int i = 0; i < n; ++i) {
            if (kth(x, i) != kth(x, n-i-1)) return false;
        }
        return true;
    }
private:
    int kth(int x, int k) {
        while (k > 0) {
            --k;
            x = x / 10;
        }
        return x%10;
    }
};
