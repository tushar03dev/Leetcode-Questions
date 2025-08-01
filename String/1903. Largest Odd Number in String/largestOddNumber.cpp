class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for(int i = num.size()-1; i >= 0; i--){
            if((num[i] - '0') & 1){
                index = i;
                break;
            }
        }
        if(index == -1) return "";
        else{
            string ans = "";
            int i = 0;
            while(i <= index){
                ans += num[i];
                i++;
            }
            return ans;
        }
    }
};
