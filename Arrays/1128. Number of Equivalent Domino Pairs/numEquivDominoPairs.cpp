class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<pair<int,int>,int> mp;
        for(auto x : dominoes){
            if(x[0] > x[1]){
                x[0] = x[0] + x[1] - (x[1] = x[0]);
            }
            count += mp[make_pair(x[0],x[1])]++;
        }
        return count;
    }
};
