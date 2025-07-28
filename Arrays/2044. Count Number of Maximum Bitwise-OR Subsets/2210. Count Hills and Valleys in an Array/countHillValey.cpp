class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size() - 1; ++i) {
            if(nums[i] == nums[i - 1]) continue;

            int l = i-1;
            while(l >=0 && nums[l] == nums[i]) l--;

            int r = i+1;
            while(r < nums.size() && nums[r] == nums[i]) r++;

            if(  (l >= 0 && r < nums.size())  && ( nums[i] > nums[l] && nums[i] > nums[r] ) || (nums[i] < nums[l] && nums[i] < nums[r])) count++;

        }

        return count;
    }
};
