class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n = num.size(), ans = num[0] + num[1] + num[2];
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1, k = abs(ans - target);
            while (l < r) {
                if (abs(num[l] + num[r] + num[i] - target) < k) {
                    ans = num[l] + num[r] + num[i];
                    k = abs(ans - target);
                }
                if (num[l] + num[r] + num[i] < target) ++l;
                else                                   --r;
            }
        }
        return ans;
    }
};
