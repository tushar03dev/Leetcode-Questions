class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev){
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) return true;
        else return false;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(),cuboids.end());

        vector<int> curr(cuboids.size()+1,0);
        vector<int> prev(cuboids.size()+1,0);

        for (int curr_index = cuboids.size() - 1; curr_index >= 0; curr_index--) {
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {

                int include = 0;
                if (prev_index == -1 || check(cuboids[curr_index],cuboids[prev_index])) {
                    include = cuboids[curr_index][2] + curr[curr_index+1];
                }
                int exclude = curr[prev_index+1];
                curr[prev_index + 1] = max(include, exclude);
            }
            prev = curr;
        }

        return curr[0];
    }
};
