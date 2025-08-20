class Solution {
public:
    void solve(vector<vector<int>>& output, vector<int>& candidates, vector<int>& ans, int target, int index){
        if(target <= 0){
            if(target == 0) output.push_back(ans);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            ans.push_back(candidates[i]);
            solve(output, candidates,ans,target-candidates[i],i+1);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        int index = 0;
        vector<int> ans;
        solve(output, candidates,ans,target, index);
        return output;
    }
};
