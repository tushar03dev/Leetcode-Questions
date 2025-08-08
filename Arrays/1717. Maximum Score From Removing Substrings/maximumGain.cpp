class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto remove = [](string &s, string pair, int points){
            int count = 0;
            string st;
            for(char c : s){
                if(!st.empty() && c == pair[1] && st.back() == pair[0]){
                    count += points;
                    st.pop_back();
                } else{
                    st.push_back(c);
                }
            }

            s = st;
            return count;
        };
        

        int count=0;
        if(x > y){
            count += remove(s,"ab",x);
            count += remove(s,"ba",y);
        } else {
            count += remove(s,"ba",y);
            count += remove(s,"ab",x);
        }
        return count;


    }
};
