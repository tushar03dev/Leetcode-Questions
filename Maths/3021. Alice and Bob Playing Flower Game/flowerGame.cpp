class Solution {
public:
    long long flowerGame(int n, int m) {
        int temp = n;
        int oddN = temp & 1 == 0 ? temp/2 +1 : temp/2;
        int evenN = temp - oddN;

        int temp2 = m;
        int oddM = temp2 & 1 == 0 ? temp2/2 +1 : temp2/2;
        int evenM = temp2 - oddM;


        
        return (long long) oddN * evenM + (long long) evenN * oddM;
    }
};
