class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>left;
        vector<int>right;

        int sum=0;
        for(int x : nums){
            sum += x;
            left.push_back(sum);
        }

        sum = 0;
        for(int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            right.push_back(sum);
        }

        reverse(right.begin(), right.end());

        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            if(left[i] == right[i]){
                ans = i;
                break;
            }
        }

        return ans;

    }
};
