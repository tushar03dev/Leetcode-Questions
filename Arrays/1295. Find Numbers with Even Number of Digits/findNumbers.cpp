class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num: nums){
            int count = 0;
            while(num) { 
                count++;
                num /= 10;
            }
            if(count % 2 == 0) ans++;
        }
        return ans;
    }
};
