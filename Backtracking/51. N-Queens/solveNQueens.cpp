class Solution {
public:
    void solve(vector<vector<string>>& output, vector<string>& ans, int n,
               int row, vector<bool> cols,
               vector<bool> diag1, vector<bool> diag2) {

        if (row == n) {
            output.push_back(ans);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {

                ans[row][col] = 'Q';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

                solve(output, ans, n, row + 1, cols, diag1, diag2);

                ans[row][col] = '.';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> ans(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        int row = 0;
        solve(output, ans, n, row, cols, diag1, diag2);
        return output;
    }
};
