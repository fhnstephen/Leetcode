class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j)
                f[i + 1] += f[j] * f[i - j];
        }
        return f[n];
    }
};
