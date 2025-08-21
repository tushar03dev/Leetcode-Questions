class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // width by asec and height by desc
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a, const vector<int>&  b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        
        // take only height in consideration as width is already sorted asecnding
        // height is descending so even if any later value replaces it then it would be lesser
        vector<int> heights;
        for(auto &envelope : envelopes){
            heights.push_back(envelope[1]);
        }

        vector<int>ans;
        ans.push_back(heights[0]);

        for(int i = 1; i < heights.size(); i++){
            if(heights[i] > ans.back()){
                ans.push_back(heights[i]);
            } else{
                int index = lower_bound(ans.begin(),ans.end(),heights[i]) - ans.begin();
                ans[index] = heights[i];
            }
        }

        return ans.size();
    }
};
