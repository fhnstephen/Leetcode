class Solution {
 public:
     int rangeBitwiseAnd(int m, int n) {
        bitset<32> bm(m), bn(n);
        int i;
        for (i = 31; i >= 0; --i) {
            if (bm[i] != bn[i]) break;
        }
        for (int j = i; j >= 0; --j)
            bn[j] = 0;
        return static_cast<int>(bn.to_ulong());
     }
 };
