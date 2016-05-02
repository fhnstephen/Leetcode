class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        k_ = k;
        n_ = n;
        dfs();
        return ans;
    }
private:
    vector<int> currentSet;
    vector<vector<int>> ans;
    int k_, n_;
    void dfs(int lastNum = 0, int x = 0, int sum = 0) {
        if (x == k_) {
            if (sum == n_) {
                ans.push_back(currentSet);
            }
            return;
        }
        if (sum >= n_) {
            return;
        }
        if ((n_ - sum) > (maxSum(x)) || (n_ - sum) < (minSum(x, lastNum))) {
            return;
        }
        for (auto i = lastNum + 1; i <= 10 - k_ + x; ++i) {
            currentSet.push_back(i);
            dfs(i, x + 1, sum + i);
            currentSet.pop_back();
        }
    }
    int minSum(int x, int lastNum) {
        int rest = k_ - x;
        int sum = 0;
        while (rest--) {
            sum += ++lastNum;
        }
        return sum;
    }
    int maxSum(int x) {
        int rest = k_ - x;
        int sum = 0;
        int maxNum = 9;
        while (rest--) {
            sum += maxNum--;
        }
        return sum;
    }
};