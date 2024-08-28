class Solution {
public:
    int firstOccurence(vector<int>& nums,int target,int n){
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(nums[mid] == target){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid] < target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums,int target,int n){
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(nums[mid] == target){
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid] < target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        int firstPos=firstOccurence(nums,target,n);
        int lastPos=lastOccurence(nums,target,n);
        return {firstPos,lastPos};

    }
};
