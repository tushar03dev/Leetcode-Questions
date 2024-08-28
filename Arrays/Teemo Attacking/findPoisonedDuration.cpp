class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=timeSeries.size();
        int timeCount=duration;
        int i=n-1;
        while(i>0){
            int diff = timeSeries[i]-timeSeries[i-1];
            if(diff < duration){
                timeCount+=diff;
            }
            else{
                timeCount+=duration;
            }
            i--;
        }
        return timeCount;
    }  
};
