class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        int low =0;
        int high=n-1;
        int mid=low;
        while(mid<=high){
            switch(nums[mid]){
                case 0:{
                    swap(nums[low++],nums[mid++]);
                    break;
                }
                case 1:{
                    mid++;
                    break;
                }
                case 2:{
                    swap(nums[mid],nums[high--]);
                    break;
                }
            }
        }
    }
};
