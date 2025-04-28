class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        vector<long long> prefix(nums.size()+1,0);
        for(int i = 1; i <= nums.size();i++){
            prefix[i] += prefix[i-1] + nums[i-1];
        }

        long long ans = 0;
        for(int i = 1; i <= nums.size();i++){

            int start = i;
            int end = nums.size();
            int index = -1;

            while(start <= end){

                int mid = start + (end - start)/2;
                long long sum = prefix[mid] - prefix[i-1];

                if( sum*(mid-i+1) >= k){
                    end = mid-1;
                }
                else {
                    index = mid;
                    start = mid+1;
                } 
            }
            if(index != -1)  ans += index - i + 1;
        }
        return ans;
    }
};
