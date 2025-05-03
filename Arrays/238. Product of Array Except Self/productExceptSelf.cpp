class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size(),1);
        vector<int> suffixes(nums.size(),1);
        
        int prefixVal = 1;
        int suffixVal = 1;
        int zeroCount = 0;
        int zeroIndex = -1;

        for(int i = 0;i <nums.size();i++){
            if(i == 0) {
                if(nums[i] == 0){
                    zeroCount++;
                    zeroIndex = i;
                }
                prefixVal *= nums[0];
                suffixVal *= nums[nums.size()-1];
            } else{
                if(nums[i] == 0){
                    zeroCount++;
                    zeroIndex = i;
                }
                prefixes[i] = prefixVal;
                suffixes[suffixes.size()-1-i] = suffixVal;

                prefixVal *= nums[i];
                suffixVal *= nums[nums.size()-1-i];
            }
        }

        for(int i = 0;i <nums.size();i++){
            nums[i] = prefixes[i]*suffixes[i];
        }

        return nums;
    }
};
