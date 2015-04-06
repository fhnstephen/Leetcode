class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        for (int i = 0; i < numRows; ++i) {
            int len = i + 1;
            vector<int> row(len, 1);
            for (int j = 1; j < i; ++j)
                row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            ans.push_back(row);
        }
        return ans;
    }
};
