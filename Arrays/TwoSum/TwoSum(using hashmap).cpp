class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                return {mp[complement],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};
