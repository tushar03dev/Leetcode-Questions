class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> ans;
        for(auto x: nums){
            if(ans.find(x)!=ans.end()){
                return true;
            }
            ans.insert(x);
        }
        return false;
    }
};
