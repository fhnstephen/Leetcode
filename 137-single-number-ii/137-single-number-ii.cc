class Solution {
public:
    int singleNumber(int a[], int n) {
        unsigned int b0 = 0, b1 = 0, reset = 0;
        for (int i = 0; i < n; ++i) {
            b1 |= b0 & a[i];
            b0 ^= a[i];
            reset = b0 & b1;
            b1 ^= reset;
            b0 ^= reset;
        }
        return b0;
    }
};
