class Solution {
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        m = n ? board[0].size() : 0;
        b_ptr = &board;
        for (int i = 0; i < m; ++i) {
            enqueue(0, i);
            enqueue(n - 1, i);
        }
        for (int i = 1; i < n - 1; ++i) {
            enqueue(i, 0);
            enqueue(i, m - 1);
        }

        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            enqueue(now.first, now.second + 1);
            enqueue(now.first, now.second - 1);
            enqueue(now.first + 1, now.second);
            enqueue(now.first - 1, now.second);
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 'x') board[i][j] = 'O';
                else                    board[i][j] = 'X';
        return;
    }
private:
    queue<pair<int, int>> q;
    vector<vector<char>> *b_ptr;
    int n, m;
    void enqueue(int a, int b) {
        auto x = make_pair(a, b);
        if (a < 0 || a >= n || b < 0 || b >= m || (*b_ptr)[a][b] != 'O') return;
        q.push(x);
        (*b_ptr)[a][b] = 'x';
    }
};
