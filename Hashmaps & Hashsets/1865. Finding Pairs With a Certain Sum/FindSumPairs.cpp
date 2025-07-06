class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int x: this->nums2){
            this->freq[x]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        this->nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int x : nums1){
            int target = tot-x;
            if(freq.find(target) != freq.end()){
                ans += freq[target];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
