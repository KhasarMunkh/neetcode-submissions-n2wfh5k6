class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;               // index to put 0's
        int r = nums.size() - 1; // index to put 2's
        int i = 0;               // current index being checked
        while (i <= r) {
            // i is at a 0, swap with l pos
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
                if (nums[i] != 1) {
                    continue;
                }
            }
            i++;
        }
    }
};