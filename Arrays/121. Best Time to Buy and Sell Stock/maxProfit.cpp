class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        int minPrice= INT_MAX;
        int maxProf =0;
        for(int i=0;i<n;i++){
          if(prices[i] < minPrice){
            minPrice=prices[i];
          }
          else if(prices[i] - minPrice > maxProf){
            maxProf = prices[i]-minPrice;
          }
        }
        return maxProf;
    }
};
