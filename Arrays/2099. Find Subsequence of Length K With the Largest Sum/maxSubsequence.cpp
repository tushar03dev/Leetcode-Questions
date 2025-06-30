class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> freq;
        int i = temp.size() - k;
        while (i < temp.size()) {
            freq[temp[i]]++;
            i++;
        }
        temp = {};
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) != freq.end() && freq[nums[i]] > 0) {
                temp.push_back(nums[i]);
                freq[nums[i]]--;
            }
        }
        return temp;
    }
};
