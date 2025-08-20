class Solution {
public:
    bool solve(string str, string s, int k){
        int count = 0, i = 0;
        for(char ch : s){
            if(ch == str[i]){
                i++;
                if(i == str.size()){
                    i = 0;
                    count++;
                    if(count == k) return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        queue<string> q;
        q.push("");

        while(!q.empty()){
            string front = q.front();
            q.pop();

            for(char ch = 'a'; ch <= 'z'; ch++){
                string str = front + ch;
                if(solve(str,s,k)){
                    ans = str;
                    q.push(str);
                }
            }
        }
        return ans;
    }
};
