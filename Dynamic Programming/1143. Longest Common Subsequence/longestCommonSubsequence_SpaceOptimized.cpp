int longestCommonSubsequence(string text1, string text2) {
        int i = 0, j = 0;
        vector<int> next(text1.size() + 1, 0);
        vector<int> curr(text1.size() + 1, 0);

        for (int j = text2.size() - 1; j >= 0; j--) {
            for (int i = text1.size() - 1; i >= 0; i--) {
                int ans =0;
                if (text1[i] == text2[j]) {
                    ans = 1 + next[i + 1];
                } else {

                    ans = max(next[i],curr[i + 1]);
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return next[0];
    }
