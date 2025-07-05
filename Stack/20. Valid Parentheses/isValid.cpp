class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(st.empty()) st.push(ch);
            else{
                if(ch == ')' && st.top() == '(') st.pop();
                else if(ch == ']' && st.top() == '[') st.pop();
                else if(ch == '}' && st.top() == '{') st.pop();
                else st.push(ch);
            }
        }

        return st.empty();
    }
};
