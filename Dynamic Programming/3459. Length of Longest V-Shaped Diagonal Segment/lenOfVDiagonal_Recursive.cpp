class Solution {
public:
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int solve(vector<vector<int>>& grid, int row, int col, int dir, int rotate,
              int curr) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        if (curr != grid[row][col] && curr != -1)
            return 0;

        int x = directions[dir].first;
        int y = directions[dir].second;
        curr = (curr == 2 || (curr != -1 && curr != 0)) ? 0 : 2;

        int straightAns = solve(grid, row + x, col + y, dir, rotate, curr);
        int rotateAns = 0;
        if (!rotate) {
            int newDir = (dir + 1) % 4;
            int x2 = directions[newDir].first;
            int y2 = directions[newDir].second;
            rotateAns = solve(grid, row + x2, col + y2, newDir, true, curr);
        }

        return 1 + max(straightAns, rotateAns);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        maxi = max(maxi, solve(grid, i, j, dir, false, -1));
                    }
                }
            }
        }
        return maxi;
    }
};
