class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (!n) return ans;
        ans.push_back(1);
        for (int i = 1; i < n; ++i) {
            auto temp = ans.size();
            int d = 1 << i;
            while (temp != 0) {
                ans.push_back(ans[temp-1] + d);
                --temp;
            }
        }
        return ans;
    }
};
