class Solution {
public:
    bool solve(vector<int>& stones, int index, int steps, vector<vector<int>>& dp) {

        if (index >= stones.size())
            return 0;
        if (index == stones.size() - 1)
            return 1;
        if (steps <= 0)
            return 0;

        if(dp[index][steps] != -1) return dp[index][steps];

        int target = stones[index] + steps;
        int start = index+1;
        int end = stones.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (stones[mid] == target) {
                bool option1 = solve(stones, mid, steps - 1,dp);
                bool option2 = solve(stones, mid, steps,dp);
                bool option3 = solve(stones, mid, steps + 1,dp);

                dp[mid][steps] = (option1 || option2) || option3;
                return dp[mid][steps];
            } 
            else if(stones[mid] > target){
                end = mid-1;
            }
            else start = mid+1;
        }

        return 0;
        
    }

    bool canCross(vector<int>& stones) {
        int index = 0;
        int steps = 1;
        int curr = stones[0];
        vector<vector<int>> dp(stones.size()+1, vector<int>(stones.size()+1, -1));
        bool ans = solve(stones, index, steps, dp);
        return ans;
    }
};
