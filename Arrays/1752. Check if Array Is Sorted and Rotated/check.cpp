class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0;
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) count++;
        }
        if(nums[0] < nums[nums.size()-1]) count++;
        return count <= 1;
    }
};
