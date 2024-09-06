class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sumOG= n*(n+1)/2;
        long long int sum=0;
        for(auto x: nums){
            sum+=x;
        }
        return sumOG-sum;
    }
};
