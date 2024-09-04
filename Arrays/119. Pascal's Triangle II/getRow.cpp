class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1); 

        for (int i = 1; i <= rowIndex / 2; ++i) {
            ans[i] = ans[rowIndex - i] =
                (long long)ans[i - 1] * (rowIndex - i + 1) / i;
        }

        return ans;
    }
};
