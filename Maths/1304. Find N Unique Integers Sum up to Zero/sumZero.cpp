class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n & 1) ans.push_back(0);
        int x = 1;
        n /= 2;
        while(n--){
            ans.push_back(-x);
            ans.push_back(x);
            x++;
        }
        return ans;
    }
};
