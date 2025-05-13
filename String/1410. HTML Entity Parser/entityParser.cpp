class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> mp = {{"&quot;", "\""}, {"&apos;", "\'"},
                                            {"&amp;", "&"},   {"&gt;", ">"},
                                            {"&lt;", "<"},    {"&frasl;", "/"}};

        string ans = "";
        int i = 0;
        while (i < text.size()) {
            if (text[i] == '&') {
                int j = i;
                while (j < text.size() && text[j] != ';')
                    j++;
                if (j < text.size() && text[j] == ';') {
                    string str = text.substr(i, j - i + 1);
                    if (mp.find(str) != mp.end()) {
                        ans += mp[str];
                        i = j + 1;
                        continue;
                    }
                }
            }
            ans += text[i];
            i++;
        }
        return ans;
    }
};
