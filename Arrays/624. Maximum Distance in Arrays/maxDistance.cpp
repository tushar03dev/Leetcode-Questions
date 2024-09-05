class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int row = arrays.size();
        int low = arrays[0].front();
        int high = arrays[0].back();
        int maxDist = 0;
        for(int i =1;i < row;i++){
           maxDist = max(maxDist,max(abs(arrays[i].back() - low),abs(high-arrays[i].front())));
           low = min(low,arrays[i].front());
           high = max(high,arrays[i].back());
        }
        return maxDist;
    }
};
