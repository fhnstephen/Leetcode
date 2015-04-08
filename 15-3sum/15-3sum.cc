class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int>> ans;
        if (n < 3) return ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i && num[i] == num[i - 1]) continue;
            if (i >= n - 2) break;
            int a = - num[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (num[l] + num[r] > a) {
                    r--;
                } else if (num[l] + num[r] < a) {
                    l++;
                }
                if (l < r && num[l] + num[r] == a) {
                    vector<int> temp = {num[i], num[l], num[r]};
                    ans.push_back(temp);
                    ++l;
                    while (l < r && num[l] == temp[1]) ++l;
                }
            }
        }
        return ans;
    }
};
