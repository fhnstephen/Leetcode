class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        flag_ = true;
        dfs_(board, 0, 0);
        return flag_;
    }
private:
    bool row_[9][9], col_[9][9], grid_[9][9];
    bool flag_;
    void dfs_(vector<vector<char> > &board_, int x, int y) {
        if (y == 9) {
            dfs_(board_, x + 1, 0);
            return;
        }
        if (x == 9) return;
        int grid_id = x / 3 * 3 + y / 3;
        int val = board_[x][y] - 1;
        if (val != '.' - 1) {
            val = val - 48;
            if (row_[x][val] || col_[y][val] || grid_[grid_id][val]) {
                flag_ = false;
                return;
            }
            row_[x][val] = col_[y][val] = grid_[grid_id][val] = true;
        }
        dfs_(board_, x, y + 1);
    }
};
