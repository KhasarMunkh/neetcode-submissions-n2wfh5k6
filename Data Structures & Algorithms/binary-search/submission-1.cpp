class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = ((r-l)/2) + l;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                r = m;
            } else if (nums[m] < target) {
                l = m + 1;
            }
        }
        return -1;
    }
};
