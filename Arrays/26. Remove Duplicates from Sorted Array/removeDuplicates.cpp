class Solution {
public:
     int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums.front());
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] != ans.back()){
                ans.push_back(nums[i]);
            }
        }
        nums=ans;
        return nums.size();
    }
};
