class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = 0, j = 0;
        vector<int> next(word1.size() + 1, 0);
        vector<int> curr(word1.size() + 1, 0);

        for (int row = 0; row <= word1.size(); row++) {
            next[row] = word1.size() - row;
        }

        for (int j = word2.size() - 1; j >= 0; j--) {
            // put answer in every box of last row of new column
            curr[word1.size()] = word2.size() - j;
            for (int i = word1.size() - 1; i >= 0; i--) {
                if (word1[i] == word2[j]) {
                    curr[i] = next[i + 1];
                } else {
                    int replace = 1 + next[i + 1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i + 1];
                    curr[i] = min(replace, min(insert, remove));
                }
            }
            next = curr;
        }
        return next[0];
    }
};
