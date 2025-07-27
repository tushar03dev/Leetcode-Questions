class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi =INT_MIN;
        int sum = 0;

        for(int x : nums){
            if(x >= 0 && mp.find(x) == mp.end()){
                mp[x]++;
                sum += x;
            } else if(x < 0){
                maxi = max(maxi, x);
            }
        }

        if(mp.size() > 0) {
            return sum;
        } else{
            return maxi;
        }
    }
};
