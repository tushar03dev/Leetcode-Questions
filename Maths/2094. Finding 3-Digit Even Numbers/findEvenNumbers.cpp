class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(auto digit : digits){
            freq[digit]++;
        }
        vector<int>ans;

        for(int i = 100;i < 999;i = i+2){
            vector<int> temp = freq;
            int num = i;
            bool flag = true;
            while(num){
                if(temp[num%10] > 0) temp[num%10]--;
                else flag = false;
                num /= 10;
            }
            if(flag) ans.push_back(i);
        }

        return ans;
    }
};
