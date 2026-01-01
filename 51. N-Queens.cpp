// 51. N-Queens
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, diag1, diag2;
    int n;

    void solve(int r) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[r + c] || diag2[r - c + n - 1])
                continue;

            board[r][c] = 'Q';
            col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;

            solve(r + 1);

            board[r][c] = '.';
            col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        diag1 = vector<int>(2 * n, 0);
        diag2 = vector<int>(2 * n, 0);

        solve(0);
        return ans;
    }
};
