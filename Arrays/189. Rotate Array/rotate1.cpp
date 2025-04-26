class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        int n = nums.size();
        int rotations = 0;
        int start = 0;
        int curr = 0;
        int curr_num = nums[curr];

        while (rotations < n) {
            do {
                int newIndex = (curr + k) % n;
                curr_num = curr_num + nums[newIndex] - (nums[newIndex] = curr_num);
                curr = newIndex;
                rotations++;
            } while (start != curr);

            start++;
            curr = start;
            curr_num = nums[curr];
        }
    }
};
