class Solution {
public:
    string largestGoodInteger(string num) {
        string str = "";
        int maxi = -1;
        for(int i = 2; i < num.size();i++){
            if(num[i] == num[i-1] && num[i-1] == num[i-2]){
                if(num[i] - '0' > maxi){
                    str = string(3, num[i]);
                    maxi = num[i] - '0';
                }
            } 
        }
        return str;
    }
};
