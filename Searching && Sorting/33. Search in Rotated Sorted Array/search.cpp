class Solution {
public:
    int pivotElement(vector<int>& arr,int n){
    int start =0;
    int end=n-1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        // corner case
        if(start ==end) {
            // single element
            return start;
        }
        else if((mid -1 > 0) && (arr[mid] < arr[mid -1])) {   // mid = 2
            return mid-1; //16
        }
        else if((mid+1 < n)&&(arr[mid] > arr[mid+1])) {   // mid = 16
            return mid;
        }
        else if(arr[start] > arr[mid]) {   // on line B -> go left
            end = mid-1;
        }
        else {  // on line A -> go right
            start = mid +1;
        }
    }
    return -1;
}   
int binarySearch(vector<int>& nums,int start,int end,int target) {
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            start = mid +1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
    int pivotIndex = pivotElement(nums,n);
    if(target >= nums.front()){
      return  binarySearch(nums,0,pivotIndex,target);
    }
    else{
        return binarySearch(nums,pivotIndex+1,n-1,target);
    }
    }
};
