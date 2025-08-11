class Solution {
private:
    string countDigits(int x) {
        string cnt(10, '0');
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }    
public:
    bool reorderedPowerOf2(int n) {
        string s = countDigits(n);
        for (int i = 0; i < 31; ++i) { 
            if (s == countDigits(1 << i))
                return true;
        }
        return false;
    }
};
