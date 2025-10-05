class Solution {
public:
    bool isSafe(int newX, int newY, int currX, int currY,
                vector<vector<int>>& diff) {
        if (newX >= 0 && newY >= 0 && newX < diff.size() &&
            newY < diff[0].size() && diff[newX][newY] > diff[currX][currY]) {
            return true;
        } else
            return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            mini;
        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));

        mini.push({0, {0, 0}});
        diff[0][0] = 0;

        while (!mini.empty()) {
            // top down right left
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int, int> currNodePairIndex = topPair.second;
            int currX = currNodePairIndex.first;
            int currY = currNodePairIndex.second;

            for (int i = 0; i < 4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if (isSafe(newX, newY, currX, currY, diff)) {
                    int maxDiff = max(currDiff, abs(heights[newX][newY] -
                                                    heights[currX][currY]));
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);

                    if (newX != row - 1 || newY != col - 1) {
                        mini.push({diff[newX][newY], {newX, newY}});
                    }
                }
            }
        }

        return diff[row - 1][col - 1];
    }
};
