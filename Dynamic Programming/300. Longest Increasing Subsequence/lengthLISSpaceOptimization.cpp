class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> curr(nums.size()+1,0);
        vector<int> prev(nums.size()+1,0);

        for (int curr_index = nums.size() - 1; curr_index >= 0; curr_index--) {
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {

                int include = 0;
                if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
                    include = 1 + curr[curr_index+1];
                }
                int exclude = curr[prev_index+1];
                curr[prev_index + 1] = max(include, exclude);
            }
        }

        prev = curr;

        return curr[0];
    }
};
