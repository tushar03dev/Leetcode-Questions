class Solution {
   public:
    bool checkTwoChessboards(string c1, string c2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t1 = (c1[0] - 'a') + (c1[1] - '0');
        int t2 = (c2[0] - 'a') + (c2[1] - '0');
        return (t1 % 2 == t2 % 2);
    }
};
