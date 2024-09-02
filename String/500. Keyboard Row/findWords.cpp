class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string row1="qwertyuiop";
        string row2="asdfghjkl";
        string row3="zxcvbnm";
        int n = words.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            int size = words[i].size();
            string str="";
            for(char x: words[i]){
                str += tolower(x);
            }
            string row;
            if(row1.find(str[0]) != string::npos){
                row=row1;
            }
            else if(row2.find(str[0]) != string::npos){
                 row=row2;
            }
            else if(row3.find(str[0]) != string::npos){
                 row=row3;
            }
            for(int j=0;j<words[i].size();j++){
                if(row.find(str[j]) == string::npos){
                    break;
                }
                if(j== words[i].size()-1 && row.find(str[j]) != string::npos){
                    ans.push_back(words[i]);
                }
            }

        }
        return ans;
    }
};
