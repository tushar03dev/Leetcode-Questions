class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int,int> freq;
        for(int x : arr){
            freq[x]++;
        }
        for(int x : arr){
            if(freq[x] == x) ans = max(ans,x);
        }
        return ans;
    }
};
