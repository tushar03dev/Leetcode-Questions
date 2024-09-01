class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int missing=0;
        int repeating=0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                repeating = nums[i];
            } else if (i > 0 && nums[i] != nums[i - 1] + 1) {
                missing = nums[i - 1] + 1;
            }
        }

        if (nums[n - 1] != n) {
            missing = n;
        }

        if (nums[0] != 1) {
            missing = 1;
        }
        return{repeating,missing};
    }
};
