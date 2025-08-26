class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> ans(rows * cols);
        int idx = 0;

        int i = 0,j = 0;
        bool up = true;

        while (idx < rows*cols) {

            ans[idx++] = mat[i][j];

            if (up) {
                if(j == cols -1){
                    i++;
                    up = false;
                } 
                else if(i == 0){
                    j++;
                    up = false;
                } 
                else{
                i--;
                j++;
                }
            } else {
               if(i == rows-1){
                j++;
                up = true;
               }
               else if(j == 0){
                i++;
                up = true;
               }
               else{
                i++;
                j--;
               }
            }
        }
        return ans;
    }
};
