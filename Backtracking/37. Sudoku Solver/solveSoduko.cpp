class Solution {
public:
    bool safe(vector<vector<char>>& board, int i, int j, char ch) {
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == ch)
                return false;
        }
        for (int row = 0; row < 9; row++) {
            if (board[row][j] == ch)
                return false;
        }

        for (int row = 3 * (i / 3); row < 3 * (i / 3 + 1); row++) {
            for (int col = 3 * (j / 3); col < 3 * (j / 3 + 1); col++) {
                if (board[row][col] == ch)
                    return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return solve(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve(board, i, j + 1);

        for (char ch = '1'; ch <= '9'; ch++) {
            if (safe(board, i, j, ch)) {
                board[i][j] = ch;
                if (solve(board, i, j + 1))
                    return true;  // if current inserted element is okay return
                                  // true;
                board[i][j] = '.'; // else backtrack
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};
