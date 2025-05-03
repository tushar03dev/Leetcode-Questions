class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows == 1 || numRows >= s.size()) return s;

        vector<string> v(numRows);
        bool flag = false;
        int row = 0;
        string ans = "";
    
        for(char c : s){
            v[row] += c;
            if(row == numRows - 1 || row == 0) flag = !flag;
            row += flag ? 1 : -1;
        }

        for(string x : v){
            ans += x;
        }

        return ans;
    }
};
