class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int size = flowerbed.size();
        int i=0;
        int count = 0;
        while(i<size){
            if(flowerbed[i] == 0){
                bool emptyPrev = (i == 0 || flowerbed[i-1] == 0);
                bool emptyNext = (i == size-1 || flowerbed[i+1] == 0);

                if(emptyPrev && emptyNext){
                    flowerbed[i]=1;
                    count++;
                    i+=2;
                }
                else{
                    i++;
                }
            }
            else{
                i+=2;
            }
            if(count >= n) return true;
        }
        return count>=n;
    }
};
