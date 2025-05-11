class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long zeroCount1 = 0;
        long long zeroCount2 = 0;
        for(auto num: nums1){
            if(num == 0){
                zeroCount1++;
                sum1++;
            } else sum1 += num;
        }
        
        for(auto num: nums2){
            if(num == 0){
                zeroCount2++;
                sum2++;
            } else sum2 += num;
        }

        if(sum1 == sum2) return sum1;

        if(sum1 < sum2){
            if(zeroCount1 == 0) return -1;
            return sum2;
        } else{
            if(zeroCount2 == 0) return -1;
            return sum1;
        }
    }
};
