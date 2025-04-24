class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size();i++){
            unordered_set<int> st2;
            for(int j = i; j < nums.size();j++){
                st2.insert(nums[j]);
                if(st2.size() == st.size()) ans++;
            }
        }
        return ans;
    }
};
