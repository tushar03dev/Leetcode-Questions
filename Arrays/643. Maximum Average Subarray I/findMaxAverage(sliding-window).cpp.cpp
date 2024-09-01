class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        double sum = 0.0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        double avg = sum/k;
        for(int i=k;i<n;i++){
            sum += nums[i] - nums[i-k];
            avg = max(avg,sum/k);
        }
        return avg;
    }    
};
