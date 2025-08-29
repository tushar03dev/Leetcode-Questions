class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> curr(triangle.size()+1,0);
        vector<int> next(triangle.size()+1,0);                       

        for (int row = triangle.size()-1; row >= 0; row--) {
            for (int col = row; col >= 0; col--) {
                int option1 =
                    triangle[row][col] + next[col];
                int option2 =
                    triangle[row][col] + next[col + 1];

                curr[col] = min(option1, option2);
            }
            next = curr;
        }
        
        return curr[0];
    }
};
