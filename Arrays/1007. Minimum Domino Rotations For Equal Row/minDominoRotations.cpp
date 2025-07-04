class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top[7] = {0};
        int bottom[7] = {0};
        int same[7] = {0};

        int i = 0;
        int n = tops.size();
        while(i < n){
            if(tops[i] != bottoms[i]){
                top[tops[i]]++;
            bottom[bottoms[i++]]++;
            }
            else{
                same[tops[i++]]++;
            }
            
        }
        
        int ans = INT_MAX;
        
        for(int k = 1; k < 7; k++){
            if(top[k] + bottom[k] == n - same[k]){
                ans = min(ans,min(top[k],bottom[k]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
}

