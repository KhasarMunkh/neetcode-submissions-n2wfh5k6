class Solution {
private:
    int search(vector<int>& nums, int target, int l, int r) {
        if (r == l) {
            if (nums[l] == target) {
                return l;
            } else {
                return -1;
            }
        }
        int m = (r-l)/2 + l;
        if (nums[m] == target) {
            return m;
        } else if (nums[m] > target) {
            return search(nums, target, l, m);
        } else {
            return search(nums, target, m+1, r);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size());
    }
};
