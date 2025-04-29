class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int maxCount = 0;
        int left = 0;
        long long ans = 0;
        for(int right = 0; right < n ; right++){
            if(nums[right] == maxi) maxCount++;
            while(maxCount >= k){
                if(nums[left] == maxi) maxCount--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
