class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]){
                j++;
                continue;
            }    
            else if (nums1[i] < nums2[j]){
                i++;
                continue;
            }    
            else {
                if(ans.empty() || nums1[i] != ans.back()){
                    ans.push_back(nums1[i]);
                }    
            }
            i++;
            j++;
        }
        return ans;
    }
};
