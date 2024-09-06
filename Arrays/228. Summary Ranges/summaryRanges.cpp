class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            string str = to_string(nums[0]);
            return {str};
        }
        vector<string> ans;
        int low=0;
        for(int i=0;i<n;i++){
            int high=i;
            if( i+1 < n && nums[i] + 1 == nums[i+1]){
                high++;
            }
            else{
                string str1 = to_string(nums[low]);
                string str2 = to_string(nums[high]);
                if(low == high){
                    ans.push_back(str1);
                    low=high+1;
                }
                else{
                    ans.push_back(str1 +"->"+str2);
                    low=high+1;
                }
            }
        }
        return ans;
    }
};
