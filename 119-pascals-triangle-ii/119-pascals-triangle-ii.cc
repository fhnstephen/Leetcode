class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; ++i)
            result.push_back(c(rowIndex, i));
        return result;
    }
private:
    int c(int n, int m) {
        unsigned long ans = 1;
        if (m > n - m) return c(n, n-m);
        for (int i = n; i > n-m; --i)
            ans *= i, ans /= (n-i+1);
        return ans;
    }
};
