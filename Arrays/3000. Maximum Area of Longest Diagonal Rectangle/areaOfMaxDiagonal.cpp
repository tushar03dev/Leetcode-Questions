class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diag = INT_MIN;
        int area = 0;
        for(auto &v : dimensions){
            int diag2 = v[0]*v[0] + v[1]*v[1];
            if(diag2 > diag){
                diag = diag2;
                area = v[0]*v[1];
            }
            if(diag == diag2){
                diag = diag2;
                area = max(area,v[0]*v[1]);
            }
        }

        return area;
    }
};
