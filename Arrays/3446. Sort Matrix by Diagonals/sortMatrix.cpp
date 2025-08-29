class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n,vector<int>(n,0));

        for(int j = n-1; j > 0; j--){
            vector<int> temp;
            int row = 0;
            int col = j;
            while(row < n && col < n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end(),greater<int>());

            row = 0;
            col = j;
            while(row < n && col < n){
                ans[row][col] = temp.back();
                temp.pop_back();
                row++;
                col++;
            }
        }

        for(int i = 0; i < n; i++){
            vector<int> temp;
            int row = i;
            int col = 0;
            while(row < n && col < n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end());

            row = i;
            col = 0;
            while(row < n && col < n){
                ans[row][col] = temp.back();
                temp.pop_back();
                row++;
                col++;
            }
        }

        return ans;
    
    }
};
