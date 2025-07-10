class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> gap;
        gap.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++) {
            gap.push_back(startTime[i] - endTime[i - 1]);
        }

        gap.push_back(eventTime - endTime.back());

        int maxi = 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        
        while (right < gap.size()) {
            sum += gap[right];
            if (right - left + 1 < k+1) {
                right++;
            } else  if(right - left + 1 == k+1) {
                maxi = max(maxi, sum);
                sum -= gap[left];
                left++;
                right++;         
            }
        }

        return maxi;
    }
};
